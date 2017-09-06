#include <Servo.h>

#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {47, 46, 48, 49}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {50, 51, 52, 53}; //connect to the column pinouts of the keypad

int nudgeOpenAngle = 65;
int smallOpenAngle = 80;
int mediumOpenAngle = 95;
int largeOpenAngle = 110;
int relaxedCloseAngle = 40;
int tightCloseAngle = 25;
int openAngle = 140;

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

Servo servo0, servo1, servo2, servo3, servo4, servo5, servo6; //servo5 = opener; servo6 = swiper

boolean goOn = false; // key to moving on after keypad input.
boolean doTask = false;

void setup() {
  Serial.begin(9600);
  servo0.attach(3); 
  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(9);
  servo4.attach(10);
  servo5.attach(11);
  servo6.attach(12);

  openClaw();
  flipToGrabber();
  Starting();
  while (goOn == false)
  {
    MoveByKeyStarting();
  }
  goOn = false;
}

void rest() {
  servo0.write(0);
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
}

void Starting() {
  servo0.write(62);
  servo1.write(77);
  servo2.write(1);
  servo3.write(0);
}

void moveToStarting() {
  Move0(62);
  Move1(77);
  Move2(1);
  Move3(0);
  Move4(0);
  openClaw();
  flipToGrabber();
}

void MoveByKey() {
  char key = keypad.getKey(); // initialize key to NO_Key
 
  while (key == NO_KEY){
    key = keypad.getKey();
  }

  switch (key) {
      case '1':
        servo4.write(servo4.read()-1);
        break;
      case '2':
        servo1.write(servo1.read()-1);
        break;
      case '3':
        servo2.write(servo2.read()+1);
        break;
      case '4':
        servo0.write(servo0.read()-1);
        break;
      case '6':
        servo0.write(servo0.read()+1);
        break;
      case '7':
        servo4.write(servo4.read()+1);
        break;
      case '8':
        servo1.write(servo1.read()+1);
        break;
      case '9':
        servo2.write(servo2.read()-1);
        break;
      case 'A':
        servo3.write(servo3.read()-1);
        break;
      case 'C':
        servo3.write(servo3.read()+1);
        break;
      case 'D':
        goOn = true;
        break;
  }
}

void MoveByKeyFlip() {
  char key = keypad.getKey(); // initialize key to NO_Key
 
  while (key == NO_KEY){
    key = keypad.getKey();
  }

  switch (key) {
      case '1':
        servo5.write(nudgeOpenAngle);
        delay(1000);
        servo5.write(relaxedCloseAngle);
        delay(500);
        break;
      case '2':
        servo5.write(smallOpenAngle);
        delay(1500);
        servo5.write(relaxedCloseAngle);
        delay(1000);
      case '3':
        servo5.write(mediumOpenAngle);
        delay(2000);
        servo5.write(relaxedCloseAngle);
        delay(1500);
        break;
      case '4':
        servo5.write(largeOpenAngle);
        delay(2500);
        servo5.write(relaxedCloseAngle);
        delay(1500);
      case 'B':
        servo5.write(tightCloseAngle);
        flipToGrabber();
        delay(1500);
        servo4.write(180);
        delay(500);
        servo5.write(relaxedCloseAngle);
        break;
      case 'D':
        goOn = true;
        break;
      case '*':
        moveToStarting();
        break;
  }
}
void MoveByKeyStarting() {
  char key = keypad.getKey(); // initialize key to NO_Key
 
  while (key == NO_KEY){
    key = keypad.getKey();
  }

  switch (key) {
      case '4':
        servo0.write(servo0.read()-1);
        break;
      case '6':
        servo0.write(servo0.read()+1);
        break;
      case 'D':
        goOn = true;
        break;
  }
}

//++++++++++++++++++++++++++++++++++++++++++++++++ START MoveX() Programs +++++++++++++++++++

void Move0(int after) {
  if (after > servo0.read())
  {
     for (int i = servo0.read(); i <= after; i++)
     {
         servo0.write(i);
         delay(50);
     }
  }
  if (after < servo0.read())
  {
     for (int i = servo0.read(); i >= after; i--)
     {
         servo0.write(i);
         delay(50);
     }
  }
}

void Move1(int after) {
  if (after > servo1.read())
  {
     for (int i = servo1.read(); i <= after; i++)
     {
         servo1.write(i);
         delay(50);
     }
  }
  if (after < servo1.read())
  {
     for (int i = servo1.read(); i >= after; i--)
     {
         servo1.write(i);
         delay(50);
     }
  }
}

void Move2(int after) {
  if (after > servo2.read())
  {
     for (int i = servo2.read(); i <= after; i++)
     {
         servo2.write(i);
         delay(50);
     }
  }
  if (after < servo2.read())
  {
     for (int i = servo2.read(); i >= after; i--)
     {
         servo2.write(i);
         delay(50);
     }
  }
}

void Move3(int after) {
  if (after > servo3.read())
  {
     for (int i = servo3.read(); i <= after; i++)
     {
         servo3.write(i);
         delay(50);
     }
  }
  if (after < servo3.read())
  {
     for (int i = servo3.read(); i >= after; i--)
     {
         servo3.write(i);
         delay(50);
     }
  }
}

void Move4(int after) {
  if (after > servo4.read())
  {
     for (int i = servo4.read(); i <= after; i++)
     {
         servo4.write(i);
         delay(50);
     }
  }
  if (after < servo4.read())
  {
     for (int i = servo4.read(); i >= after; i--)
     {
         servo4.write(i);
         delay(50);
     }
  }
}

//++++++++++++++++++++++++++++++++++++++++++++++++ END MoveX() Programs +++++++++++++++++++

void flipToGrabber() {
  servo4.write(8);
}

void openClaw() {
  for (int i = relaxedCloseAngle; i<openAngle; i++)
   {
      servo5.write(i);
      delay(5); 
   }
   delay(1000);
}

void closeClaw() {
   for (int i = openAngle; i>tightCloseAngle; i--)
   {
      servo5.write(i);
   }
   delay(2000);  
}

void flipToSwiper() {
  servo4.write(180);
  delay(1000);
  for (int i = tightCloseAngle; i<nudgeOpenAngle; i++)
   {
      servo5.write(i); 
   }
   delay(500);
  for (int i = nudgeOpenAngle; i>relaxedCloseAngle; i--)
   {
      servo5.write(i);
   }
  delay(500);
}

void swipeOnce() {
  for (int i = 35; i<85; i++)
  {
     servo6.write(i);
     delay(3); 
  }
  delay(500);
  for (int i = 85; i>35; i--)
  {
     servo6.write(i);
     delay(3);
  }
}

//===================================================START 5 Swipe Programs===========

void swipeTenTop() {
  swipeOnce();
  delay(750);
  for (int i = 1; i<= 6; i++)
  {
     swipeOnce();
     movePennyWidthRight();
     delay(1000);
  }
  servo0.write(servo0.read()-2);
  delay(500);
  servo1.write(servo1.read()-5);
  delay(500);
  servo2.write(servo2.read()-5);
  for (int i = 7; i<= 10; i++)
  {
     swipeOnce();
     movePennyWidthLeft();
     delay(1000);
  }
}

void swipeTenLeft() {
  swipeOnce();
  delay(750);
  for (int i = 1; i<= 3; i++)
  {
     swipeOnce();
     movePennyWidthLeft();
     delay(1000);
  }
  servo0.write(servo0.read()-2);
  delay(500);
  servo1.write(servo1.read()-5);
  delay(500);
  servo2.write(servo2.read()-5);
  for (int i = 4; i<= 10; i++)
  {
     swipeOnce();
     movePennyWidthRight();
     delay(1000);
  }
}

void swipeTenRight() {
  swipeOnce();
  delay(750);
  swipeOnce();
  servo0.write(servo0.read()+2);
  delay(500);
  servo1.write(servo1.read()-5);
  delay(500);
  servo2.write(servo2.read()-5);
  for (int i = 2; i<= 10; i++)
  {
     swipeOnce();
     movePennyWidthLeft();
     delay(1000);
  }
}

void swipeTenBottomLeft() {
  swipeOnce();
  delay(750);
  for (int i = 1; i<= 8; i++)
  {
     swipeOnce();
     movePennyWidthRight();
     delay(1000);
  }
  servo0.write(servo0.read()-5);
  delay(500);
  servo1.write(servo1.read()-5);
  delay(500);
  servo2.write(servo2.read()-5);
  for (int i = 9; i<= 10; i++)
  {
     swipeOnce();
     movePennyWidthLeft();
     delay(1000);
  }
}

void swipeTenBottom() {
  swipeOnce();
  delay(750);
  for (int i = 1; i<= 5; i++)
  {
     swipeOnce();
     movePennyWidthLeft();
     delay(1000);
  }
  servo0.write(servo0.read()+5);
  delay(500);
  servo1.write(servo1.read()-5);
  delay(500);
  servo2.write(servo2.read()-5);
  for (int i = 6; i<= 10; i++)
  {
     swipeOnce();
     movePennyWidthRight();
     delay(1000);
  }
}

//===================================================END 5 Swipe Programs===========

void movePennyWidthRight() {
  int i = servo0.read();
  for (int j = 0; j < 4; j++)
  {
    i++;
    delay(500);
  }
  servo0.write(i);
}

void movePennyWidthLeft() {
  int i = servo0.read();
  for (int j = 0; j < 4; j++)
  {
    i--;
    delay(500);
  }
  servo0.write(i);
}

void initialize() {
  flipToGrabber();
  openClaw();
  servo6.write(85);
}

void endRun() {
  openClaw();
  servo4.write(90);
  delay(500);
  servo4.write(0);
}
//|||||||||||||||||||||||||||||||||||||||||||||||||| START 5 Complete Stacks Programs ||||||||||

void doTop() { //============================================================ TOP ==============
  Move0(94);
  Move2(70);
  //Move3(20);
  Move1(100);
  Move2(105);
  Move1(130);
  Move3(55);
  Move4(3);
  
  while (goOn == false)
  {
    MoveByKey();
    Serial.println("Go on is false");
  }
  goOn = false;
  closeClaw();
  /*
  Move1(90);
  Move0(91);
  Move2(69);
  Move3(64);
  */
  flipToSwiper();
  while (goOn == false)
  {
    MoveByKeyFlip();
    Serial.println("Go on is false");
  }
  goOn = false;
  
  Move1(93);
  Move4(180);
  swipeTenTop();
}

void doLeft() { //============================================================ LEFT ==============
  Move1(80);
  Move2(15);
  Move3(0);
  Move0(60); // intermediate position to avoid the pennies
  
  Move0(70);
  Move4(3);
  Move2(70);
  Move1(96);
  Move3(30);
  
  while (goOn == false)
  {
    MoveByKey();
    Serial.println("Go on is false");
  }
  goOn = false;
  /*
  Move1(102);
  Move4(8);
  while (goOn == false)
  {
    MoveByKey();
    Serial.println("Go on is false");
  }
  goOn = false;
  */
  closeClaw();
  Move1(95);
  flipToSwiper();
  while (goOn == false)
  {
    MoveByKeyFlip();
    Serial.println("Go on is false");
  }
  goOn = false;
  
  Move1(90);
  Move0(96);
  Move2(64);
  Move3(68);
  swipeTenLeft();
}

void doRight() { //============================================================ RIGHT ==============
  Move0(116);
  Move2(65);
  Move1(94);
  Move3(33);
  
  while (goOn == false)
  {
    MoveByKey();
    Serial.println("Go on is false");
  }
  goOn = false;
  /*
  Move1(104);
  Move4(3);
  while (goOn == false)
  {
    MoveByKey();
    Serial.println("Go on is false");
  }
  goOn = false;
  */
  closeClaw();
  Move1(95);
  flipToSwiper();
  while (goOn == false)
  {
    MoveByKeyFlip();
    Serial.println("Go on is false");
  }
  goOn = false;
  
  Move1(95);
  Move0(111);
  Move2(59);
  Move3(52);
  swipeTenRight();
}

void doBottomLeft() { //============================================================ BOTTOM LEFT ==============
  //Avoid coins
  Move2(35);
  Move1(75);
  Move0(1);
  Move3(0);

  //Regular position
  Move2(44);
  Move0(5);
  Move1(103);
  Move3(17);
  
  while (goOn == false)
  {
    MoveByKey();
    Serial.println("Go on is false");
  }
  goOn = false;
  closeClaw();
  Move1(102);
  flipToSwiper();
  while (goOn == false)
  {
    MoveByKeyFlip();
    Serial.println("Go on is false");
  }
  goOn = false;
  
  Move1(86);
  Move0(85);
  Move2(53);
  Move3(60);
  swipeTenBottomLeft();
}

void doBottom() { //============================================================ BOTTOM ==============
  //avoid coins
  Move0(80);
  Move1(78);
  Move2(19);
  Move3(0);
  
  //Regular position
  Move0(89);
  Move2(80);
  Move1(78);
  Move3(0);

  while (goOn == false)
  {
    MoveByKey();
    Serial.println("Go on is false");
  }
  goOn = false;
  /*
  Move1(89);
  Move2(17);
  Move4(8);
  while (goOn == false)
  {
    MoveByKey();
    Serial.println("Go on is false");
  }
  goOn = false;
  */
  closeClaw();
  flipToSwiper();
  while (goOn == false)
  {
    MoveByKeyFlip();
    Serial.println("Go on is false");
  }
  goOn = false;
  
  Move4(180);
  Move1(82);
  Move0(103);
  Move2(46);
  Move3(56);
  swipeTenBottom();
}

void loop() { //============================================================ VOID LOOP ==============
  char key = keypad.getKey(); // initialize key to NO_Key
 
  while (key == NO_KEY){
    key = keypad.getKey();
  }

  switch (key) {
      case 'A':
        initialize();
        doTop();
        endRun();
        break;
      case 'B':
        initialize();
        doLeft();
        endRun();
        break;
      case 'C':
        initialize();
        doRight();
        endRun();
        break;
      case 'D':
        initialize();
        doBottomLeft();
        endRun();
        break;
      case '#':
        initialize();
        doBottom();
        endRun();
        break;
      case '*':
        moveToStarting();
        break;
  }
}
