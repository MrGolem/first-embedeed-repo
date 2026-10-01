#include <Arduino.h>
#include "settings.h"
#include "policeSettings.h"

void setup() {
    pinMode(Settings::LED_OUT, OUTPUT);// Налаштовуємо пін як вихід (OUTPUT), щоб контролер міг подавати на нього напругу
    Serial.begin(115200); // Ініціалізуємо серійний порт для виводу інформації
    //Serial.println("Програма запущена. Світлdіод буде блимати.");

    pinMode(Policeman::LED_RED_OUT, OUTPUT);
    pinMode(Policeman::LED_BLUE_OUT, OUTPUT);

    pinMode(Policeman2::LED_OUT, OUTPUT);
    randomSeed(analogRead(0)); // Ініціалізуємо генератор випадкових чисел
  }

void blink() {
  neopixelWrite(RGB_BUILTIN, 15, 7, 8); // Червоний  
  //digitalWrite(Settings::LED_OUT, HIGH); // Вмикаємо світлodіod (подаємо 3.3 В)
    Serial.println("Світлdіод увімкнено."); // Виводимо повідомлення в серійний порт
    Serial.println("LED_DELAY_MS1 = " + String(Settings::LED_DELAY_MS1)); // Виводимо повідомлення в серійний порт
    Serial.println("LED_DELAY_MS2 = " + String(Settings::LED_DELAY_MS2)); // Виводимо повідомлення в серійний порт
    
    delay(Settings::LED_DELAY_MS2);                 // Чекаємо 
    
    neopixelWrite(RGB_BUILTIN, 0, 0, 0); // Червоний
    //digitalWrite(Settings::LED_OUT, LOW);  // Вимикаємо світлodіод (подаємо 0 В)
    Serial.println("Світлdіод вимкнено."); // Виводимо повідомлення в серійний порт
    delay(Settings::LED_DELAY_MS);       // Чекаємо
}

void police2gpio(){
    // Червоний світлодіод
    digitalWrite(Policeman::LED_RED_OUT, HIGH); // Вмикаємо червоний світлодіод
    delay(Policeman::LED_BLINK_DELAY_MS);       // Чекаємо
    digitalWrite(Policeman::LED_RED_OUT, LOW);  // Вимикаємо червоний світлодіод

    // Синій світлодіод
    digitalWrite(Policeman::LED_BLUE_OUT, HIGH); // Вмикаємо синій світлодіод
    
    delay(Policeman::LED_BLINK_DELAY_MS);        // Чекаємо
    digitalWrite(Policeman::LED_BLUE_OUT, LOW);  // Вимикаємо синій світлодіод
}

void police1gpio(){
  digitalWrite(Policeman2::LED_OUT, HIGH);
  int pause = random(Policeman2::LED_BLINK_DELAY_START, Policeman2::LED_BLINK_DELAY_END);
  delay(pause);  // LED увімкнений на рандомну паузу 
  digitalWrite(Policeman2::LED_OUT, LOW);

  delay(300);
}

void loop() {
    //blink();
    //police2gpio();
    police1gpio();
}