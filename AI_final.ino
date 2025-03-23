//#include <Adafruit_Keypad.h>
//#include <Adafruit_Keypad_Ringbuffer.h>
#include<Servo.h>
#include <Keypad.h>
const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns

Servo s1;
// Define the keypad layout
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

// Define the row and column pin connections
byte rowPins[ROWS] = {12,11,10,9}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; // Connect to the column pinouts of the keypad

String input;
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int hepPin = 2;
const int buzzPin = 3;
const int irPin = 4;
int result1, result2,fnalresult,correctAnswer=0;

unsigned long start1,end1,start2,end2,start3,end3,rstart,rend,elapsedTime,en1,st1,en2,st2,en3,st3,ren,rst,et;

float seconds,Aseconds,finalTrainingTiming=0,testCounter;
char key;

void buzzerShort()
{
  digitalWrite(buzzPin,HIGH);
  delay(500);
  digitalWrite(buzzPin,LOW);
}

void buzzerLong()
{
  digitalWrite(buzzPin,HIGH);
  delay(2000);
  digitalWrite(buzzPin,LOW);
}
void buzzercorrect()
{
  //digitalWrite(buzzPin,HIGH);
  digitalWrite(hepPin,HIGH);
  delay(1000);
  digitalWrite(buzzPin,LOW);
  digitalWrite(hepPin,LOW);
  
}
void buzzerincorrect()
{
  digitalWrite(buzzPin,HIGH);
  delay(500);
  digitalWrite(buzzPin,LOW);
  //delay(500);
}





void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  int i;
  s1.attach(5);
  s1.write(180);
  Serial.println("Setting initial position to 0...");
  delay(2000);
  pinMode(hepPin,OUTPUT);
  pinMode(buzzPin,OUTPUT);
  pinMode(irPin,INPUT);
 
  // Initialize random seed
  randomSeed(analogRead(0));
  
}

void loop() {
  
  
  Serial.println("Moderators kindly orient the blind person about this system with the following instructions");
  Serial.println("Practice session begins, you will have to score atleast 50% of the marks to take actual test...");
  delay(2000);
  Serial.println("On short buzzer read the number from specified place, and then you need to remove your finger from there");
  delay(2000);
  Serial.println("On long buzzer press the asnwer followed by # or enter");
  Serial.println(5000);
  for(int j=0;j<2;j++) //for selecting how many number of questions to be run through
  {
    Serial.print("Practice question no: ");
    Serial.println(j);
  int randomNumber = random(5);
  switch(randomNumber)
  {
    case 0:
    //number 1 display
    s1.write(145);
    Serial.println("2");
    buzzerShort(); 
    start1 = millis();
    Serial.println("Start reading number 1....");
    while(digitalRead(irPin)==1)
    {      
      
    }
    
    Serial.println("remove finger once done reading number 1...");
    while(digitalRead(irPin)==0)
    {
      
      
    }
    
    end1 = millis();

    //Operation display
    s1.write(65);
    Serial.println("+");
    buzzerShort(); 
    start2 = millis();
    Serial.println("Start reading operator....");
    while(digitalRead(irPin)==1)
    {
      
      
    }
    
     Serial.println("remove finger once done reading operator...");
    while(digitalRead(irPin)==0)
    {
     
      
    }
    
    end2 = millis();
    
    //number 2 display
    s1.write(95);
    Serial.println("7");
    buzzerShort(); 
    start3 = millis();
    Serial.println("Start reading number 2....");
    while(digitalRead(irPin)==1)
    {
      
      
    }
    Serial.println("remove finger once done reading number 2...");
    while(digitalRead(irPin)==0)
    {
      
      
    }
    end3 = millis();

    buzzerLong();

  Serial.println("Enter result....");

    rstart = millis();
  
   key = keypad.getKey();
     input = "";
    while (key != '#') {
      if (key) {
             input += key;
      }
    key = keypad.getKey();
  }
    

  if (input.toInt()==9) {
    buzzercorrect();
    Serial.println("Correct!");
    correctAnswer++;
  } else {
    buzzerincorrect();
    Serial.println("Incorrect!");
  }
//    while(Serial.read()!='5')
//  {
//   
//  }
  rend = millis();

  elapsedTime = (end1 - start1)+(end2 - start2)+(rend - rstart);

  // Convert elapsed time to seconds
   seconds = elapsedTime / 1000.0;
   finalTrainingTiming = finalTrainingTiming+seconds; 
   

  Serial.print("Time taken: ");
  Serial.print(seconds);
  Serial.println(" seconds");   
  Serial.print("Total timings so far");
  Serial.print(finalTrainingTiming);
    
   break;

    case 1:

    //number 1 display
    s1.write(75);
    Serial.println("9");
    buzzerShort(); 
    start1 = millis();
    Serial.println("Start reading number 1....");
    while(digitalRead(irPin)==1)
    {      
      
    }
    
    Serial.println("remove finger once done reading number 1...");
    while(digitalRead(irPin)==0)
    {
      
      
    }
    
    end1 = millis();

    //Operation display
    s1.write(55);
    Serial.println("-");
    buzzerShort(); 
    start2 = millis();
    Serial.println("Start reading operator....");
    while(digitalRead(irPin)==1)
    {
      
      
    }
    
     Serial.println("remove finger once done reading operator...");
    while(digitalRead(irPin)==0)
    {
     
      
    }
    
    end2 = millis();
    
    //number 2 display
    s1.write(145);
    Serial.println("2");
    buzzerShort(); 
    start3 = millis();
    Serial.println("Start reading number 2....");
    while(digitalRead(irPin)==1)
    {
      
      
    }
    Serial.println("remove finger once done reading number 2...");
    while(digitalRead(irPin)==0)
    {
      
      
    }
    end3 = millis();
    buzzerLong();
Serial.println("Enter result....");

    rstart = millis();
   key = keypad.getKey();
     input = "";
    while (key != '#') {
      if (key) {
             input += key;
      }
    key = keypad.getKey();
  }
    

  if (input.toInt()==7) {
    buzzercorrect();
    correctAnswer++;
    Serial.println("Correct!");
    } else {
    buzzerincorrect();
    Serial.println("Incorrect!");
  }
  
//  while(Serial.read()!='1')
//  {
//   
//  }
  rend = millis();

  elapsedTime = (end1 - start1)+(end2 - start2)+(rend - rstart);

  // Convert elapsed time to seconds
   seconds = elapsedTime / 1000.0;
   finalTrainingTiming = finalTrainingTiming+seconds;

  Serial.print("Time taken: ");
  Serial.print(seconds);
  Serial.println(" seconds");    
  Serial.print("Total timings so far");
  Serial.print(finalTrainingTiming);
    
 
    break;

    case 2:

    //number 1 display
    s1.write(145);
    Serial.println("2");
    buzzerShort(); 
    start1 = millis();
    Serial.println("Start reading number 1....");
    while(digitalRead(irPin)==1)
    {      
      
    }
    
    Serial.println("remove finger once done reading number 1...");
    while(digitalRead(irPin)==0)
    {
      
      
    }
    
    end1 = millis();

    //Operation display
    s1.write(45);
    Serial.println("X");
    buzzerShort(); 
    start2 = millis();
    Serial.println("Start reading operator....");
    while(digitalRead(irPin)==1)
    {
      
      
    }
    
     Serial.println("remove finger once done reading operator...");
    while(digitalRead(irPin)==0)
    {
     
      
    }
    
    end2 = millis();
    
    //number 2 display
    s1.write(135);
    Serial.println("3");
    buzzerShort(); 
    start3 = millis();
    Serial.println("Start reading number 2....");
    while(digitalRead(irPin)==1)
    {
      
      
    }
    Serial.println("remove finger once done reading number 2...");
    while(digitalRead(irPin)==0)
    {
      
      
    }
    end3 = millis();
    buzzerLong();
Serial.println("Enter result....");
    rstart = millis();
   key = keypad.getKey();
     input = "";
    while (key != '#') {
      if (key) {
             input += key;
      }
    key = keypad.getKey();
  }
    

  if (input.toInt()==6) {
    buzzercorrect();
    correctAnswer++;
    Serial.println("Correct!");
    
  } else {
    buzzerincorrect();
    Serial.println("Incorrect!");
  }
  
//  while(Serial.read()!='9')
//  {
//   
//  }
  rend = millis();

   elapsedTime = (end1 - start1)+(end2 - start2)+(rend - rstart);

  // Convert elapsed time to seconds
  seconds = elapsedTime / 1000.0;
 finalTrainingTiming = finalTrainingTiming+seconds;

  Serial.print("Time taken: ");
  Serial.print(seconds);
  Serial.println(" seconds");    
  Serial.print("Total timings so far");
  Serial.print(finalTrainingTiming);    
    
    

    break;
    
    
    case 3:

    //number 1 display
    s1.write(85);
    Serial.println("8");
    buzzerShort(); 
    start1 = millis();
    Serial.println("Start reading number 1....");
    while(digitalRead(irPin)==1)
    {      
      
    }
    
    Serial.println("remove finger once done reading number 1...");
    while(digitalRead(irPin)==0)
    {
      
      
    }
    
    end1 = millis();

    //Operation display
    s1.write(35);
    Serial.println("/");
    buzzerShort(); 
    start2 = millis();
    Serial.println("Start reading operator....");
    while(digitalRead(irPin)==1)
    {
      
      
    }
    
     Serial.println("remove finger once done reading operator...");
    while(digitalRead(irPin)==0)
    {
     
      
    }
    
    end2 = millis();
    
    //number 2 display
    s1.write(125);
    Serial.println("4");
    buzzerShort(); 
    start3 = millis();
    Serial.println("Start reading number 2....");
    while(digitalRead(irPin)==1)
    {
      
      
    }
    Serial.println("remove finger once done reading number 2...");
    while(digitalRead(irPin)==0)
    {
      
      
    }
    end3 = millis();
    buzzerLong();
Serial.println("Enter result....");
    rstart = millis();
   key = keypad.getKey();
     input = "";
    while (key != '#') {
      if (key) {
             input += key;
      }
    key = keypad.getKey();
  }
    

  if (input.toInt()==2) {
    buzzercorrect();
    correctAnswer++;
    Serial.println("Correct!");
    
  } else {
    buzzerincorrect();
    Serial.println("Incorrect!");
  }
  
//  while(Serial.read()!='9')
//  {
//   
//  }
  rend = millis();

   elapsedTime = (end1 - start1)+(end2 - start2)+(rend - rstart);

  // Convert elapsed time to seconds
  seconds = elapsedTime / 1000.0;
 finalTrainingTiming = finalTrainingTiming+seconds;

  Serial.print("Time taken: ");
  Serial.print(seconds);
  Serial.println(" seconds");    
  Serial.print("Total timings so far");
  Serial.print(finalTrainingTiming);    
    
    

    break;


    case 4:

    //number 1 display
    s1.write(115);
    Serial.println("5");
    buzzerShort(); 
    start1 = millis();
    Serial.println("Start reading number 1....");
    while(digitalRead(irPin)==1)
    {      
      
    }
    
    Serial.println("remove finger once done reading number 1...");
    while(digitalRead(irPin)==0)
    {
      
      
    }
    
    end1 = millis();

    //Operation display
    s1.write(65);
    Serial.println("+");
    buzzerShort(); 
    start2 = millis();
    Serial.println("Start reading operator....");
    while(digitalRead(irPin)==1)
    {
      
      
    }
    
     Serial.println("remove finger once done reading operator...");
    while(digitalRead(irPin)==0)
    {
     
      
    }
    
    end2 = millis();
    
    //number 2 display
    s1.write(135);
    Serial.println("3");
    buzzerShort(); 
    start3 = millis();
    Serial.println("Start reading number 2....");
    while(digitalRead(irPin)==1)
    {
      
      
    }
    Serial.println("remove finger once done reading number 2...");
    while(digitalRead(irPin)==0)
    {
      
      
    }
    end3 = millis();
    buzzerLong();
Serial.println("Enter result....");
    rstart = millis();
   key = keypad.getKey();
     input = "";
    while (key != '#') {
      if (key) {
             input += key;
      }
    key = keypad.getKey();
  }
    

  if (input.toInt()==8) {
    buzzercorrect();
    correctAnswer++;
    Serial.println("Correct!");
    
  } else {
    buzzerincorrect();
    Serial.println("Incorrect!");
  }
  
//  while(Serial.read()!='9')
//  {
//   
//  }
  rend = millis();

   elapsedTime = (end1 - start1)+(end2 - start2)+(rend - rstart);

  // Convert elapsed time to seconds
  seconds = elapsedTime / 1000.0;
 finalTrainingTiming = finalTrainingTiming+seconds;

  Serial.print("Time taken: ");
  Serial.print(seconds);
  Serial.println(" seconds");    
  Serial.print("Total timings so far ");
  Serial.print(finalTrainingTiming);    
    
    

    break;
    default: break;
  }
 }


 
  finalTrainingTiming=finalTrainingTiming+25.000;
  Serial.println("Final Time inlcuidng Buzzer");
  Serial.println(finalTrainingTiming);
//  Serial.println("Calculating average time.."
//  delay(1000);

  



    
   if(correctAnswer>=1)
   {
    Serial.println("Starting actaul test now...");
  delay(2000);
  
   int count=0;
   testCounter = millis()/1000;
   Serial.print("Test Counter");
   Serial.println(testCounter);
    for(int k=0;k<2;k++)
    {
   int randomNumber1 = random(2); 
    switch(randomNumber1)
    {
      
      case 0: 
    if(testCounter<=finalTrainingTiming)
    {
      s1.write(85);
    Serial.println("8");
    buzzerShort(); 
   
    Serial.println("Start reading number 1....");
    while(digitalRead(irPin)==1)
    {      
      
    }
    
    Serial.println("remove finger once done reading number 1...");
    while(digitalRead(irPin)==0)
    {
      
      
    }
    
   
    //Operation display
    s1.write(35);
    Serial.println("/");
    buzzerShort(); 
    Serial.println("Start reading operator....");
    while(digitalRead(irPin)==1)
    {
      
      
    }
    
     Serial.println("remove finger once done reading operator...");
    while(digitalRead(irPin)==0)
    {
     
      
    }
    
    
    //number 2 display
    s1.write(125);
    Serial.println("4");
    buzzerShort(); 
    Serial.println("Start reading number 2....");
    while(digitalRead(irPin)==1)
    {
      
      
    }
    Serial.println("remove finger once done reading number 2...");
    while(digitalRead(irPin)==0)
    {
      
      
    }
    buzzerLong();
    Serial.println("Enter result....");
    
    key = keypad.getKey();
    input = "";
    while (key != '#') {
      if (key) {
             input += key;
      }
    key = keypad.getKey();
  }
    

  if (input.toInt()==2) {
    buzzercorrect();
    Serial.println("Correct!");
    count++;
  } else {
    buzzerincorrect();
    Serial.println("Incorrect!");
  }
  
  
  }
    else
    {
      Serial.println("Time Up");
      break;
    }

    break;
    case 1:
    if(testCounter<=finalTrainingTiming)
    {
      s1.write(125);
    Serial.println("4");
    buzzerShort(); 
    Serial.println("Start reading number 1....");
    while(digitalRead(irPin)==1)
    {      
      
    }
    
    Serial.println("remove finger once done reading number 1...");
    while(digitalRead(irPin)==0)
    {
      
      
    }
    
  
    //Operation display
    s1.write(125);
    Serial.println("/");
    buzzerShort(); 
    Serial.println("Start reading operator....");
    while(digitalRead(irPin)==1)
    {
      
      
    }
    
     Serial.println("remove finger once done reading operator...");
    while(digitalRead(irPin)==0)
    {
     
      
    }
    
    //number 2 display
    s1.write(25);
    Serial.println("1");
    buzzerShort(); 
    Serial.println("Start reading number 2....");
    while(digitalRead(irPin)==1)
    {
      
      
    }
    Serial.println("remove finger once done reading number 2...");
    while(digitalRead(irPin)==0)
    {
      
      
    }
    buzzerLong();
    Serial.println("Enter result....");
    key = keypad.getKey();
    input = "";
    while (key != '#') {
      if (key) {
             input += key;
      }
    key = keypad.getKey();
  }
    

  if (input.toInt()==4) {
    buzzercorrect();
    Serial.println("Correct!");
    count++;
  } else {
    buzzerincorrect();
    Serial.println("Incorrect!");
  }
  
  }
    else
    {
      Serial.println("Time Up");
      break;
    }
    

    break;
    
    

  }

    }

    Serial.println("Total Number of correct answers...");
    Serial.println(count);
    delay(3000);
    for(int m=0;m<count;m++)
    {
      digitalWrite(hepPin,HIGH);
      delay(2000);
      digitalWrite(hepPin,LOW);
      delay(1000);
    }
    delay(5000);
    

   }
   else
   {
   Serial.println("You need to retake the test....");
   
   }


}
