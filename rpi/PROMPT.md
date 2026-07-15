# Chip Machine Project

`chipmachine` is the C/C++ project that implements music player that can play music that was developed for the old home computers first, and then arcade machines, and then later using programs called trackers starting with Amiga home computers. It is plugin based and includes a number of plugins to cover many of today's music formats in use.

The compiled code binary can be used from the command line to play a particular music file or it can start the GUI with a music database collection of the 700K music files that can be downloaded and played.

The music player is designed to compile into a binary that executes in Apple Silicone in MacOS devices.

## The New Feature

The new feature would be to add required build changes to be able to build the same music player with a new target for execution: Raspberry Pi.

## The main objective

The main objective is to figure the necessary steps to start from the existing code, tools and build processes, and to end up with tools and build processes that can compile the executable for Raspberry Pi.

The first result should be a detailed plan on how to get to the end goal: the same music player from the same code base that runs in Raspberry Pi.

## Considerations

* Focus on the Raspberry Pi 5
* Focus on the tools and dependency needed
* Focus on the differences from the existing tools that build executable for Apple Silicon ARM CPU and MacOS


