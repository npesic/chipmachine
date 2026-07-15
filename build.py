#!/usr/bin/env python

import os.path
import subprocess
import argparse
import platform

os_name = platform.system()

def which(program):
    import os
    def is_exe(fpath):
        return os.path.isfile(fpath) and os.access(fpath, os.X_OK)

    fpath, fname = os.path.split(program)
    if fpath:
        if is_exe(program):
            return program
    else:
        for path in os.environ['PATH'].split(os.pathsep):
            path = path.strip("'")
            exe_file = os.path.join(path, program)
            if is_exe(exe_file):
                return exe_file

    return None


parser = argparse.ArgumentParser(description='Build chipmachine')
parser.add_argument('actions', choices=['build', 'clean', 'run', 'config'], default='build',
                   nargs='*', help='Actions to perform')

parser.add_argument('--buildsystem', choices=['ninja', 'make', 'xcode'], default='ninja',
                   help='Build system to use')

parser.add_argument('--config', choices=['release', 'debug', 'usan', 'asan', 'tsan', 'msan'], default='release',
                   help='Release or Debug config')

parser.add_argument('--output', default='builds',
                   help='Output directory')

parser.add_argument('--target', choices=['native', 'raspberry', 'windows', 'android'], default='native',
                   help='(Cross) compilation target')

args = parser.parse_args()

configs = { 'release' : [ 'release', ['-DCMAKE_BUILD_TYPE=Release'] ],
            'debug' : [ 'debug', ['-DCMAKE_BUILD_TYPE=Debug'] ],
            'usan' : [ 'usan', ['-DCMAKE_BUILD_TYPE=Debug', '-DSAN=undefined'] ],
            'asan' : [ 'asan', ['-DCMAKE_BUILD_TYPE=Debug', '-DSAN=address'] ],
            'msan' : [ 'msan', ['-DCMAKE_BUILD_TYPE=Debug', '-DSAN=memory'] ],
            'tsan' : [ 'tsan', ['-DCMAKE_BUILD_TYPE=Debug', '-DSAN=thread'] ]
          }
buildsystems = { 'make' : ['-GUnix Makefiles'],
                 'ninja' : [ '-GNinja',  ]
               }

scriptDir = os.path.dirname(os.path.abspath(__file__))

# (Cross-)compilation targets -> extra CMake args.
#   native    : build for the host. NOTE: an on-device build directly on a
#               Raspberry Pi 5 is a *native* build -- use --target native there.
#   raspberry : cross-compile for a Raspberry Pi 5 (64-bit aarch64 / Cortex-A76,
#               Raspberry Pi OS) from another host via the rpi5-aarch64 toolchain
#               file. Point it at a copy of the Pi's root filesystem by setting
#               the RPI_SYSROOT env var (or -DRPI_SYSROOT=... in CMake).
#   windows/android : reserved (not wired yet).
targets = { 'native'    : [],
            'raspberry' : ['-DCMAKE_TOOLCHAIN_FILE=' +
                           os.path.join(scriptDir, 'rpi5-aarch64.cmake')],
            'windows'   : [],
            'android'   : [],
          }

buildTool = args.buildsystem;
buildArgs = []
buildArgs += configs[args.config][1]
buildArgs += targets[args.target]
buildArgs.append(buildsystems[args.buildsystem][0])
#buildArgs.append('-DCMAKE_TOOLCHAIN_FILE=clang.cmake')

# Give each (cross-)target its own build tree so their CMake caches, which pin
# the compiler/toolchain, never collide with the native one.
outputSubDir = configs[args.config][0]
if args.target != 'native':
    outputSubDir = args.target + '-' + outputSubDir
outputDir = os.path.join(args.output, outputSubDir)

try :
    os.makedirs(outputDir)
except :
    pass

if args.actions == 'build' :
    args.actions = [ 'build' ]

for a in args.actions :
    a = a.strip()
    if a == 'build' :
        if not os.path.isfile(os.path.join(outputDir, 'build.ninja')) :
            subprocess.call(['cmake', '-B' + outputDir, '-H.'] + buildArgs)
        args = [buildTool, '-C', outputDir]
        if buildTool == 'make' :
            args.append('-j8')
        subprocess.call(args)
    elif a == 'config' :
        subprocess.call(['cmake', '-B' + outputDir, '-H.'] + buildArgs)
    elif a == 'clean' :
        subprocess.call([buildTool, '-C', outputDir, 'clean'])
    elif a == 'run' :
        exe = os.path.join(outputDir, 'chipmachine')
        os.system(exe + ' -d')

