/*
 * This sketch cycles between colors Red, Green and Blue.
 * It acts like a color wheel. Starting from full Red
 * it continues to add more Green by raising it's brightness
 * value. When Green is at maximum brightness, Red color
 * begins to decrease in it's brightness. Then the same for
 * Blue until it goes back to Red, restarting the loop.
 * July 16, 2016 Artem(Atomic Charge)Shum
 */
#define DEL 30
#define RED 9
#define GRN 10
#define BLU 11
#define ST 5

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GRN, OUTPUT);
  pinMode(BLU, OUTPUT);
}

//Function which switches from one color to another
void switchTo(uint8_t a, uint8_t b){
  uint8_t i;
  //Add color a to color b
  for (uint8_t i = 0;i < 255; i+=ST){
    analogWrite(b, i);
    delay(DEL);
  }
  //Subtract color a from color b when color b is max
  //brightness
  for (i = 255;i > 0;i-=ST){
    analogWrite(a, i);
    delay(DEL);
  }
  //It would bug out if I didn't set it manualy to off
  analogWrite(a, 0);
}

void loop() {
  //Set Red color to max brightness
  analogWrite(RED, 255);
  analogWrite(GRN, 0);
  analogWrite(BLU, 0);  

  //The wheel in action
  switchTo(RED, GRN);
  switchTo(GRN, BLU);
  switchTo(BLU, RED);
  
}
