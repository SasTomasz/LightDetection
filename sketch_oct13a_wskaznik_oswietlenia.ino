#define DIVIDER_1 A0  // photoresistor F29
#define DIVIDER_2 A1  // photoresistor F2
#define RED_LED_1 13  // LED A21
#define RED_LED_2 12  // LED A17
#define YELLOW_LED 11 // LED A13
#define GREEN_LED_2 10  // LED A10
#define GREEN_LED_1 9   // LED A7

int dividerValue1 = 0;
int dividerValue2 = 0;
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

  // dividerValue1 is right photoresistor, dividerValue2 is left photoresistor
  Serial.print("L: ");
  Serial.print(dividerValue2);
  Serial.print(" R: ");
  Serial.println(dividerValue1);
  delay(100);

  // light source

  switch // to be continued...
  

}
