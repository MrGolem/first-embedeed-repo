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

constexpr uint32_t Button_Pin = 9;

constexpr uint32_t ADC_Pin = 6; // Пін аналогового входу для читання значення

constexpr uint32_t LedOut1 = 15; // Пін для керування світлodіodом 1
constexpr uint32_t LedOut2 = 16; // Пін для керування світlodіodом 2
constexpr uint32_t Button_Out = 21; // Пін для керування зовнішньою кнопкою
constexpr uint32_t Button_IN = 0; // Пін для керування внутрішньою кнопкою
} // namespace Settings
