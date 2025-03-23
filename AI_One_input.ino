
#include <Keypad.h>
const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns

// Define the keypad layout
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

// Define the row and column pin connections
byte rowPins[ROWS] = {5, 4, 3, 2}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; // Connect to the column pinouts of the keypad


Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int r1 = 9;
const int r2 = 10;
const int r3 = 11;
const int r4 = 12;
const int buzzPin = 13;
int result;
unsigned long startTime;
unsigned long endTime;

//char key;

void cw()
{
      digitalWrite(r1,1);
      digitalWrite(r2,0);
      digitalWrite(r3,0);
      digitalWrite(r4,0);
      delay(5);
      digitalWrite(r1,0);
      digitalWrite(r2,1);
      digitalWrite(r3,0);
      digitalWrite(r4,0);
      delay(5);
      digitalWrite(r1,0);
      digitalWrite(r2,0);
      digitalWrite(r3,1);
      digitalWrite(r4,0);
      delay(5);
      digitalWrite(r1,0);
      digitalWrite(r2,0);
      digitalWrite(r3,0);
      digitalWrite(r4,1);
      delay(5);
}

void ccw()
{
      digitalWrite(r1,0);
      digitalWrite(r2,0);
      digitalWrite(r3,0);
      digitalWrite(r4,1);
      delay(5);
      digitalWrite(r1,0);
      digitalWrite(r2,0);
      digitalWrite(r3,1);
      digitalWrite(r4,0);
      delay(5);
      digitalWrite(r1,0);
      digitalWrite(r2,1);
      digitalWrite(r3,0);
      digitalWrite(r4,0);
      delay(5);
      digitalWrite(r1,1);
      digitalWrite(r2,0);
      digitalWrite(r3,0);
      digitalWrite(r4,0);
      delay(5);
}
void buzzerShort()
{
  digitalWrite(buzzPin,HIGH);
  delay(2000);
  digitalWrite(buzzPin,LOW);
}
void buzzerRead()
{
  digitalWrite(buzzPin,HIGH);
  delay(3000);
  digitalWrite(buzzPin,LOW);
}
void buzzerLong()
{
  digitalWrite(buzzPin,HIGH);
  delay(5000);
  digitalWrite(buzzPin,LOW);
}


void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  int i;
  // Initialize random seed
 // randomSeed(analogRead(0));
  
}

void loop() {
 
  
    //number 1 display
    startTime = millis();
    for(int i=0;i<64;i++)
    {
      cw();
    }
    buzzerRead();
    delay(2000);
    for(int i=0;i<64;i++)
    {
      ccw();
    }
   // buzzerShort();
    delay(500);
    

     //operation display
    for(int i=0;i<320;i++)
    {
      cw();
    }
    buzzerRead();
    delay(2000);
    for(int i=0;i<320;i++)
    {
      ccw();
    }
    delay(500);

    //number 2 display
    for(int i=0;i<96;i++)
    {
      cw();
    }
    buzzerRead();
    delay(2000);
    for(int i=0;i<96;i++)
    {
      ccw();
    }
    buzzerLong();
    delay(500);

    char key;

  // Wait until a key is pressed
  while (!keypad.getKey()) {
    // Do nothing and keep waiting
  }

  // Once a key is pressed, print it and wait for 1 second
  key = keypad.getKey();
  Serial.println(key);
  delay(1000);

  if (key()=='5') {
    Serial.println("Correct!");
  } else {
    Serial.println("Incorrect!");
  }

  endTime = millis();

  unsigned long elapsedTime = endTime - startTime;

  // Convert elapsed time to seconds
  float seconds = elapsedTime / 1000.0;

  Serial.print("Time taken: ");
  Serial.print(seconds);
  Serial.println(" seconds");    
     
  
  // Delay for a short period before generating the next random number
  delay(1000);
}
