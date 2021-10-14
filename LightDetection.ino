#define DIVIDER_1 A0  // photoresistor F29
#define DIVIDER_2 A1  // photoresistor F2
#define RED_LED_1 13  // LED A21
#define RED_LED_2 12  // LED A17
#define YELLOW_LED 11 // LED A13
#define GREEN_LED_2 10  // LED A10
#define GREEN_LED_1 9   // LED A7

// dividerValue1 is right photoresistor, dividerValue2 is left photoresistor
int dividerValue1 = 0;
int dividerValue2 = 0;
int mapDividerValue1 = 0;
int mapDividerValue2 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED_1, OUTPUT);
  pinMode(RED_LED_2, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED_1, OUTPUT);
  pinMode(GREEN_LED_2, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  dividerValue1 = analogRead(DIVIDER_1);
  dividerValue2 = analogRead(DIVIDER_2);

  /* In my room with lights on, dividerValue1 is 600 and dividerValue2 is 700
   * and light decrease this values to 300 (dividerValue1) and 400 (dividerValue2)
   */
  mapDividerValue1 = map(dividerValue1, 300, 600, 1, 3);
  mapDividerValue2 = map(dividerValue2, 400, 700, 1, 3);

  
// It may be usefull to adjust 
//  Serial.print("L: ");
//  Serial.print(dividerValue2);
//  Serial.print(" R: ");
//  Serial.println(dividerValue1);
//  delay(100);

  switch (mapDividerValue1) {
    case 1:   // strong light on right
      flashLight(LOW, LOW, LOW, HIGH, HIGH);
      break;

    case 2:   // medium light on right
      flashLight(LOW, LOW, LOW, HIGH, LOW);
      break;
  
  } 
  delay(1);   // for stability

  switch (mapDividerValue2) {
    case 1:   // strong light on left
      flashLight(HIGH, HIGH, LOW, LOW, LOW);
      break;

    case 2:   // medium light on left
      flashLight(LOW, HIGH, LOW, LOW, LOW);
      break;

  } delay(1); // for stability

  if (mapDividerValue1 == 3 && mapDividerValue2 == 3) {
    flashLight(LOW, LOW, HIGH, LOW, LOW);
  } delay(1);
  

}

// Turn on specified LED
void flashLight(uint8_t gLed1, uint8_t gLed2, uint8_t yLed1, uint8_t rLed2, uint8_t rLed1) {
  digitalWrite(GREEN_LED_1, gLed1);
  digitalWrite(GREEN_LED_2, gLed2);
  digitalWrite(YELLOW_LED, yLed1);
  digitalWrite(RED_LED_2, rLed2); 
  digitalWrite(RED_LED_1, rLed1);
}
