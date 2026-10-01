#pragma once

#include <stdint.h>

namespace Policeman {
    const uint8_t LED_RED_OUT = 48;
    const uint8_t LED_BLUE_OUT = 47;

    constexpr uint32_t LED_BLINK_DELAY_MS = 300;

} // namespace Policeman

namespace Policeman2 {
    const uint8_t LED_OUT = 9;

    constexpr uint32_t LED_BLINK_DELAY_START = 300;
    constexpr uint32_t LED_BLINK_DELAY_END = 1000;


} // namespace Policeman