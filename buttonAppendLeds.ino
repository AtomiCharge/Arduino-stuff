/* This uses a button which activates one more led after a press.
 * So when it is pressed a led in the array lights up. When it's 
 * pressed again, it lights up the next one while the previous one
 * remains turned on. This continues until 5 leds are lit up. If
 * a button is pressed when all are lit up, imediately after the
 * press all turn off.
 * July 16, 2016
 */
#define BIn 8
#define DEL 200

bool curr = 0;
bool prev = 0;

//Initialize the array
uint8_t leds[] = {2, 3, 4, 5, 6};
int8_t ledsOn = 0;

void setup() {
  pinMode(BIn, INPUT);

  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
  //Serial.begin(9600); uncomment this and other for debugging
}

void loop() {
  
  //gets current state of the button
  curr = digitalRead(BIn);
  if (curr == 1 && prev == 0) {
    
    //Serial.println("Pressed"); uncomment for debugging
    delay(200);
    
    //if more than 5 are on set the amount of leds
    //on to -1 so that the loop appends it to 0
    if (ledsOn >= 5) {
      ledsOn = -1;
      
      //turn them all off
      for (int j = 0; j < 5; j++) {
        digitalWrite(leds[j], LOW);
      }
    }
    
    //append the amount of leds that are on
    ledsOn++;
    
    //turn on the corresponding amount of leds
    for (int i = 0; i < ledsOn; i++) {
      digitalWrite(leds[i], HIGH);
    }
  }

  //makes sure it doesn't append for as long as the button is held
  prev = curr;
}

