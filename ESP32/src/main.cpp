#include <Arduino.h>
#include "settings.h"
#include "policeSettings.h"

volatile uint32_t counter = 0; // лічильник натискань кнопки
volatile bool mode1 = true; // прапорець для відстеження натискання кнопки

IRAM_ATTR void handleButtonPress() {
  counter++; // Збільшуємо лічильник при натисканні кнопки
  mode1 = !mode1; // Перемикаємо режим при кожному натисканні кнопки
}

void setup() {
    pinMode(Settings::LED_OUT, OUTPUT);// Налаштовуємо пін як вихід (OUTPUT), щоб контролер міг подавати на нього напругу
    
    pinMode(Policeman::LED_RED_OUT, OUTPUT);
    pinMode(Policeman::LED_BLUE_OUT, OUTPUT);
    


    pinMode(Policeman2::LED_OUT, OUTPUT);
    randomSeed(analogRead(0)); // Ініціалізуємо генератор випадкових чисел

    pinMode(Settings::Button_Pin, INPUT_PULLUP); // Налаштовуємо пін кнопки як вхід з підтягуванням до живлення (INPUT_PULLUP)
    pinMode(Settings::ADC_Pin, INPUT); // Налаштовуємо пін аналогового входу як вхід (INPUT)
  
    Serial.begin(115200); // Ініціалізуємо серійний порт для виводу інформації

    attachInterrupt(digitalPinToInterrupt(Settings::Button_Pin), handleButtonPress, CHANGE);
    
    //Homework 16
    pinMode(Settings::LedOut1, OUTPUT); // Налаштовуємо пін лед
    pinMode(Settings::LedOut2, OUTPUT); // Налаштовуємо пін лед
    pinMode(Settings::Button_Out, INPUT_PULLUP); // Налаштовуємо пін кнопки
    pinMode(Settings::Button_IN, INPUT); // Налаштовуємо пін внутрішньої кнопки
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

void buttonPressLesson(){
  if(digitalRead(Settings::Button_Pin) == LOW) { // Перевіряємо стан кнопки (LOW означає, що кнопка натиснута)
    Serial.println("Кнопка натиснута: " + String(counter) + " разів"); // Виводимо повідомлення в серійний порт
    delay(50); // Затримка для уникнення дребезгу контакту
  }
}

void Mode1() {
  digitalWrite(Settings::LedOut1, HIGH); 
  digitalWrite(Settings::LedOut2, HIGH); 
  delay(200); // Чекаємо певний час
}

void Mode2() {
  digitalWrite(Settings::LedOut1, HIGH); 
  delay(1000); // Чекаємо певний час
  digitalWrite(Settings::LedOut1, LOW); 
  digitalWrite(Settings::LedOut2, HIGH); 
  delay(1000); // Чекаємо певний час
  digitalWrite(Settings::LedOut2, LOW);
}
void ModeChoose(){
    if(digitalRead(Settings::Button_Out) == LOW) { // Перевіряємо стан кнопки (LOW означає, що кнопка натиснута)
    Serial.println("Зовнішню кнопку натиснуто"); // Виводимо повідомлення в серійний порт
    if(mode1 == false) { // Перевіряємо, чи режим вже ввімкнено
      handleButtonPress(); // Викликаємо функцію обробки натискання кнопки
      Serial.println("Змінюємо режим. Режими змінювались вже " + String(counter) + " разів"); // Виводимо повідомлення в серійний порт

    }
    else {
      Serial.println("Кнопку натиснуто, але режим вже ввімкнено"); // Виводимо повідомлення в серійний порт
    }
    delay(50); // Затримка для уникнення дребезгу контакту
  }
  if(digitalRead(Settings::Button_IN) == LOW) { // Перевіряємо стан кнопки (LOW означає, що кнопка натиснута)
    Serial.println("Внутрішню кнопку натиснуто"); // Виводимо повідомлення в серійний порт
    if(mode1 == true) { 
      handleButtonPress(); 
      Serial.println("Змінюємо режим. Режими змінювались вже " + String(counter) + " разів"); // Виводимо повідомлення в серійний порт
    }
    else {
      Serial.println("Кнопку натиснуто, але режим вже ввімкнено"); // Виводимо повідомлення в серійний порт
    }
    delay(50); // Затримка для уникнення дребезгу контакту
  }
}
void Homevork16() {
  if(mode1) {
    // Виконуємо режим 1: блимання світлodіoдами одночасно
    Mode1();
  } else {
    // Виконуємо режим 2: блимання по черзі
    Mode2();
  }
}

void adcRead() {
  uint32_t adcValue = analogRead(Settings::ADC_Pin); // Зчитуємо значення з аналогового входу
  Serial.print("Значення з ADC: "); // Виводимо повідомлення в серійний порт
  Serial.println(adcValue); // Виводимо значення з ADC в серійний порт

  uint32_t milivolts = analogReadMilliVolts(Settings::ADC_Pin); // Перетворюємо значення ADC в мілівольти

  float voltage = milivolts / 1000.0; // Перетворюємо мілівольти в вольти
  Serial.print("Напруга: " + String(voltage) + " V"); // Виводимо повідомлення в серійний порт


  delay(500); // Затримка перед наступним зчитуванням
}
void loop() {
  //blink();
  //police2gpio();
  //police1gpio();
  //buttonPressLesson();
  //adcRead();

  ModeChoose();

  // Викликаємо функцію Homevork16 для виконання домашнього завдання
  Homevork16();
}