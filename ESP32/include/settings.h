#pragma once

#include <stdint.h>

namespace Settings {

constexpr uint8_t LED_OUT = 48;
constexpr uint32_t LED_DELAY_MS = 1000;

constexpr uint32_t add(uint32_t a, uint32_t b) {
    return a + b;
}

constexpr uint32_t LED_DELAY_MS1 = add(1000, 600);
constexpr uint32_t LED_DELAY_MS2 = add(1000, 500);

} // namespace Settings
