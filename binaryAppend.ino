/*This sketch outputs a decimal 8 bit integer in binary
//and each bit is displayed on an LED array.*/

uint8_t LEDS[] = {6,7,8,9,10,11,12,13};
uint8_t count = 0;

void setup() {
  for (int i = 0; i < 8; i++){
    pinMode(LEDS[i], OUTPUT);
  }
}
void loop() {
  decToBin(count);
  count++;//Increase count with each clock
}

//Decimal to Binary output
void decToBin(uint8_t i){
  for (int j = 0; j < 8; j++){
    //set each led in the array 
    //to represent corresponding bits
    digitalWrite(LEDS[j], bitRead(i, j));
    //Just so I can see things happening
    delay(200);
  }
}

