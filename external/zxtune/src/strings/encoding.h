/**
 *
 * @file
 *
 * @brief  Encoding-related
 *
 * @author vitamin.caig@gmail.com
 *
 **/

#pragma once

#include "string_type.h"
#include "string_view.h"

#include <cstdint>  // uint16_t (GCC 16 libstdc++ no longer pulls it in via <string_view>)

namespace Strings
{
  String ToAutoUtf8(StringView str);

  String Utf16ToUtf8(std::basic_string_view<uint16_t> str);
}  // namespace Strings
