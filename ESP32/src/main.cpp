#include <Arduino.h>
#include "settings.h"
#include "policeSettings.h"

void setup() {
    pinMode(Settings::LED_OUT, OUTPUT);// Налаштовуємо пін як вихід (OUTPUT), щоб контролер міг подавати на нього напругу
    Serial.begin(115200); // Ініціалізуємо серійний порт для виводу інформації

    pinMode(Policeman::LED_RED_OUT, OUTPUT);
    pinMode(Policeman::LED_BLUE_OUT, OUTPUT);

    pinMode(Policeman2::LED_OUT, OUTPUT);
    randomSeed(analogRead(0)); // Ініціалізуємо генератор випадкових чисел
  }

void blink() {
  Serial.println("Програму блінк запущено контролються піном номер: " + String(Settings::LED_OUT)); // Виводимо повідомлення в серійний порт
  if (Settings::LED_OUT == 48) {
      neopixelWrite(Settings::LED_OUT, 15, 7, 8); // Червоний
      Serial.println("RGB світлdіod увімкнено."); // Виводимо повідомлення в серійний порт

  }
  else if(Settings::LED_OUT == 47) {
      digitalWrite(Settings::LED_OUT, HIGH); // Вмикаємо світлodіod (подаємо 3.3 В)
      Serial.println("Світлdіod увімкнено."); // Виводимо повідомлення в серійний порт
  }
    
    delay(Settings::LED_DELAY_MS2);                 // Чекаємо 
    
    if (Settings::LED_OUT == 48) {
        neopixelWrite(Settings::LED_OUT, 0, 0, 0); // Червоний
        Serial.println("RGB світлdіod вимкнено."); // Виводимо повідомлення в серійний порт
    }
    else if(Settings::LED_OUT == 47) {
        digitalWrite(Settings::LED_OUT, LOW); // Вимикаємо світлodіod (подаємо 0 В)
        Serial.println("Світлdіod вимкнено."); // Виводимо повідомлення в серійний порт
    }
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
    blink();
    //police2gpio();
    //police1gpio();
}