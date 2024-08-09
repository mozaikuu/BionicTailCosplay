#include <Servo.h>
#include <Keypad.h>

// SERVOS
Servo servoX;
Servo servoY;

int pos = 0;
int delayMS = 2000;

// MECHANICS
// int speed = 1;
bool isLoop = false;

// KEYPADS
const byte ROWS = 4; 
const byte COLS = 3; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);

  servoX.attach(12);
  servoY.attach(13);
}

void loop(){
  char customKey = customKeypad.getKey();


  if (customKey){
    switch (customKey) {
      case '1': 
      Serial.println("1️⃣ Start");
       goUp();
      Serial.println("1️⃣ Done");
      break; 
      
      case '2': 
      Serial.println("2️⃣ Start");
             wiringMode();

      Serial.println("2️⃣ Done");
      break; 
      
      case '3': 
      Serial.println("3️⃣ Start");
      goUp();
      Serial.println("3️⃣ Done");
      break;
      
      case '4': 
      Serial.println("4️⃣ Start");
      testSpeed();
      Serial.println("4️⃣ Done");
      break; 
      
      case '5': 
      Serial.println("5️⃣ Start");
      standingMode();

      Serial.println("5️⃣ Done");
      break; 
      
case '8': 
      Serial.println("8️⃣ Start");
      goUp();
      // isLoop = !isLoop;
      // Serial.println(isLoop);

      Serial.println("8️⃣ Done");
      break; 

case '0': 
      Serial.println("8️⃣ Start");
      goDown();

      Serial.println("8️⃣ Done");
      break; 


      default:
        Serial.println("Choose Bitch Choose!!");
        break;
    }
  }
}


// Helper Functions
int goUp(){
  Serial.println("Going up");
  
  servoX.write(180);
  servoY.write(180);             
  delay(1000);                       
  servoX.write(0);
  servoY.write(0); 

  Serial.println("Gone up");
  return 0;
}

int goDown(){
  Serial.println("Going Down");
  
    servoX.write(33);
    servoY.write(33);             
    // delay(500);                       

  Serial.println("Gone Down");
  return 0;
}

int testSpeed() {
  Serial.println("🚀 Testing Speed");
  
  servoX.write(0);
  servoY.write(0);             
  delay(1000); 

  while(true) {
    for (pos = 0; pos <= 180; pos += 1) { 
      servoX.write(pos);
      delay(5);
    }

    delay(1000);

    for (pos = 180; pos <= 0; pos -= 1) { 
      servoX.write(pos);
      delay(5);
    }
    
    delay(1000);
  }
  servoX.write(0);
  servoY.write(0);             



  Serial.println("Testing Speed Done");
  return 0;
}

// byAmount, lastMode
// int speedUp(){
//   Serial.println("🚀 Speeding Up");

//   speed = speed + 1000;

//   return speed;
// }



// MODES
int wiringMode(){
  Serial.println("🚀 Wiring Mode");
  
    servoX.write(90);
    servoY.write(90);             
    // delay(500);                       

  Serial.println("wiring mode done");
  return 0;
}

int standingMode(){
  Serial.println("🚀 Initializing Standing Mode");
  
  servoX.write(0);
  servoY.write(0);

  for (pos = 0; pos <= 180; pos += 1) {
    servoX.write(pos);
      delay(5);
  }

  delay(5000);


  for (pos = 180; pos >= 0; pos -= 1) {
      servoX.write(pos);
        delay(5);
    }

               
  // delay(500);                       

  Serial.println("standingMode DONE");
  return 0;
}

