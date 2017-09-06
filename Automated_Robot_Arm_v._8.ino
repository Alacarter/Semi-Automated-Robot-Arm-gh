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
int swipeOpenAngle = 60;
int openAngle = 140;

int delayBetweenAngles = 25;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

Servo servo0, servo1, servo2, servo3, servo4, servo5, servo6; //servo5 = opener; servo6 = swiper

boolean goOn = false; // key to moving on after keypad input.
boolean doTask = false;
boolean doLoop = true;
boolean flag = 1; // cancel pennies

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
      case '*':
        moveToStarting();
        doLoop = true;
        loopMimic();
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
        servo5.write(tightCloseAngle);
        delay(500);
        break;
      case '2':
        servo5.write(smallOpenAngle);
        delay(1500);
        servo5.write(tightCloseAngle);
        delay(500);
        break;
      case '3':
        servo5.write(mediumOpenAngle);
        delay(2000);
        servo5.write(tightCloseAngle);
        delay(500);
        break;
      case '4':
        servo5.write(largeOpenAngle);
        delay(2500);
        servo5.write(tightCloseAngle);
        delay(500);
        break;
      case 'A':
        Move0(77);
        Move1(95);
        Move2(32);
        Move3(20);
        endRun();
        moveToStarting();
        doLoop = true;
        loopMimic();
        break;
      case 'B':
        servo5.write(tightCloseAngle);
        flipToGrabber();
        delay(1500);
        servo4.write(180);
        delay(500);
        servo5.write(tightCloseAngle);
        break;
      case 'D':
        goOn = true;
        break;
      case '*':
        moveToStarting();
        doLoop = true;
        loopMimic();
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
         delay(delayBetweenAngles);
     }
  }
  if (after < servo0.read())
  {
     for (int i = servo0.read(); i >= after; i--)
     {
         servo0.write(i);
         delay(delayBetweenAngles);
     }
  }
}

void Move1(int after) {
  if (after > servo1.read())
  {
     for (int i = servo1.read(); i <= after; i++)
     {
         servo1.write(i);
         delay(delayBetweenAngles);
     }
  }
  if (after < servo1.read())
  {
     for (int i = servo1.read(); i >= after; i--)
     {
         servo1.write(i);
         delay(delayBetweenAngles);
     }
  }
}

void Move2(int after) {
  if (after > servo2.read())
  {
     for (int i = servo2.read(); i <= after; i++)
     {
         servo2.write(i);
         delay(delayBetweenAngles);
     }
  }
  if (after < servo2.read())
  {
     for (int i = servo2.read(); i >= after; i--)
     {
         servo2.write(i);
         delay(delayBetweenAngles);
     }
  }
}

void Move3(int after) {
  if (after > servo3.read())
  {
     for (int i = servo3.read(); i <= after; i++)
     {
         servo3.write(i);
         delay(delayBetweenAngles);
     }
  }
  if (after < servo3.read())
  {
     for (int i = servo3.read(); i >= after; i--)
     {
         servo3.write(i);
         delay(delayBetweenAngles);
     }
  }
}

void Move4(int after) {
  if (after > servo4.read())
  {
     for (int i = servo4.read(); i <= after; i++)
     {
         servo4.write(i);
         delay(delayBetweenAngles);
     }
  }
  if (after < servo4.read())
  {
     for (int i = servo4.read(); i >= after; i--)
     {
         servo4.write(i);
         delay(delayBetweenAngles);
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
   delay(250);
}

void closeClaw() {
   for (int i = openAngle; i>tightCloseAngle; i--)
   {
      servo5.write(i);
   }
   delay(1000);  
}

void flipToSwiper() {
  servo4.write(180);
  delay(750);
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
  servo5.write(swipeOpenAngle);
  for (int i = 27; i<90; i++)
  {
     servo6.write(i);
     delay(3); 
  }
  delay(500);
  for (int i = 90; i>27; i--)
  {
     servo6.write(i);
     //delay(3);
  }
}

//===================================================START 5 Swipe Programs===========

void swipeTenTop() {
  swipeOnce();
  delay(500);
    char key = keypad.getKey(); // initialize key to NO_Key

    for (int i = 1; i<= 6; i++)
    {
       key = keypad.getKey();
       if (key == '*')
       {
         i=6;
         break;
       }
       swipeOnce();
       movePennyWidthRight();
       for (int j = 0; j<=500; j++)
     {
       key = keypad.getKey();
       if (key == '*')
         {
           j=500;
           i=10;
           break;
         }
       delay(1);
        if (key == '*')
         {
           j=500;
           i=10;
           break;
         }
     }
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
       for (int j = 0; j<=500; j++)
     {
       key = keypad.getKey();
       if (key == '*')
         {
           j=500;
           i=10;
           break;
         }
       delay(1);
        if (key == '*')
         {
           j=500;
           i=10;
           break;
         }
     }
    }

    
}

void swipeTenBottom() {
  swipeOnce();
  delay(500);
  char key = keypad.getKey();
  for (int i = 1; i<= 3; i++)
  {
     key = keypad.getKey();
     if (key == '*')
       {
         i=3;
         break;
       }
     swipeOnce();
     movePennyWidthLeft();
     for (int j = 0; j<=500; j++)
     {
       key = keypad.getKey();
       if (key == '*')
         {
           j=500;
           i=10;
           break;
         }
       delay(1);
        if (key == '*')
         {
           j=500;
           i=10;
           break;
         }
     }
  }
  servo0.write(servo0.read()-2);
  delay(500);
  servo1.write(servo1.read()-3);
  delay(500);
  servo2.write(servo2.read()-3);
  for (int i = 4; i<= 10; i++)
  {
     key = keypad.getKey();
     if (key == '*')
       {
         i=10;
         break;
       }
     swipeOnce();
     movePennyWidthRight();
     for (int j = 0; j<=500; j++)
     {
       key = keypad.getKey();
       if (key == '*')
         {
           j=500;
           i=10;
           break;
         }
       delay(1);
        if (key == '*')
         {
           j=500;
           i=10;
           break;
         }
     }
  }
}

void swipeTenBottomLeft() {
  swipeOnce();
  delay(500);
  swipeOnce();
  char key = keypad.getKey();
  servo0.write(servo0.read()+2);
  delay(500);
  servo1.write(servo1.read()-5);
  delay(500);
  servo2.write(servo2.read()-5);
  for (int i = 2; i<= 10; i++)
  {
     key = keypad.getKey();
     if (key == '*')
       {
         i=10;
         break;
       }
     swipeOnce();
     movePennyWidthLeft();
     for (int j = 0; j<=500; j++)
     {
       key = keypad.getKey();
       if (key == '*')
         {
           j=500;
           i=10;
           break;
         }
       delay(1);
        if (key == '*')
         {
           j=500;
           i=10;
           break;
         }
     }
  }
}

void swipeTenLeft() {
  swipeOnce();
  delay(750);
  char key = keypad.getKey();
  for (int i = 1; i<= 8; i++)
  {
     key = keypad.getKey();
     if (key == '*')
       {
         i=8;
         break;
       }
     swipeOnce();
     movePennyWidthRight();
     for (int j = 0; j<=500; j++)
     {
       key = keypad.getKey();
       if (key == '*')
         {
           j=500;
           i=10;
           break;
         }
       delay(1);
        if (key == '*')
         {
           j=500;
           i=10;
           break;
         }
     }
  }
  servo0.write(servo0.read()-5);
  delay(500);
  servo1.write(servo1.read()-5);
  delay(500);
  servo2.write(servo2.read()-5);
  for (int i = 9; i<= 10; i++)
  {
     key = keypad.getKey();
     if (key == '*')
       {
         i=10;
         break;
       }
     swipeOnce();
     movePennyWidthLeft();
     for (int j = 0; j<=500; j++)
     {
       key = keypad.getKey();
       if (key == '*')
         {
           j=500;
           i=10;
           break;
         }
       delay(1);
        if (key == '*')
         {
           j=500;
           i=10;
           break;
         }
     }
  }
}

void swipeTenRight() {
  swipeOnce();
  delay(750);
  char key = keypad.getKey();
  for (int i = 1; i<= 5; i++)
  {
     swipeOnce();
     movePennyWidthLeft();
     for (int j = 0; j<=500; j++)
     {
       key = keypad.getKey();
       if (key == '*')
         {
           j=500;
           i=10;
           break;
         }
       delay(1);
       if (key == '*')
         {
           j=500;
           i=10;
           break;
         }
     }
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
     for (int j = 0; j<=500; j++)
     {
       key = keypad.getKey();
       if (key == '*')
         {
           j=500;
           i=10;
           break;
         }
       delay(1);
        if (key == '*')
         {
           j=500;
           i=10;
           break;
         }
     }
  }
}

//===================================================END 5 Swipe Programs===========

void movePennyWidthRight() {
  int i = servo0.read();
  for (int j = 0; j < 4; j++)
  {
    i++;
    delay(100);
  }
  servo0.write(i);
}

void movePennyWidthLeft() {
  int i = servo0.read();
  for (int j = 0; j < 4; j++)
  {
    i--;
    delay(100);
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
  Move2(70);
  Move0(95);
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

  
  Move1(87);
  Move0(91);
  Move2(69);
  
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
  Move2(65);
  Move1(100);
  Move3(34);
  
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
  
  
  Move1(80);
  Move0(87);
  Move2(46);
  Move3(63);
  swipeTenLeft();
}

void doRight() { //============================================================ RIGHT ==============
  Move2(65);
  Move0(116);
  Move1(95);
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
  Move4(180);
  Move1(74);
  Move0(103);
  Move2(38);
  Move3(56);
  
  
  swipeTenRight();
}

void doBottomLeft() { //============================================================ BOTTOM LEFT ==============
  //Avoid coins
  Move2(35);
  Move1(75);
  Move0(1);
  Move3(0);

  //Regular position
  Move2(37);
  Move0(4);
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
  Move1(90);
  Move0(111);
  Move2(56);
  Move3(70);
  
  swipeTenBottomLeft();
}

void doBottom() { //============================================================ BOTTOM ==============
  //avoid coins
  Move2(19);
  Move0(80);
  Move1(78);
  Move3(0);
  
  //Regular position
  Move2(30);
  Move0(85);
  Move1(78);
  Move3(0);
  Move1(89);
  Move2(17);
  Move4(8);
  
  while (goOn == false)
  {
    MoveByKey();
    Serial.println("Go on is false");
  }
  goOn = false;
  /*
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
  
  Move1(88);
  Move0(106);
  Move2(60);
  Move3(70);
  
  
  swipeTenBottom();
}

void loopMimic() {
  while (doLoop == true)
  {
    char key = keypad.getKey(); // initialize key to NO_Key
 
    while (key == NO_KEY){
      key = keypad.getKey();
    }

    switch (key) {
      case 'A':
        initialize();
        doBottom();
        endRun();
        break;
      case 'B':
        initialize();
        doBottomLeft();
        endRun();
        break;
      case 'C':
        initialize();
        doLeft();
        endRun();
        break;
      case 'D':
        initialize();
        doRight();
        endRun();
        break;
      case '#':
        initialize();
        doTop();
        endRun();
        break;
      case '*':
        moveToStarting();
        break;
      case '4':
        servo0.write(servo0.read()-1);
        break;
      case '6':
        servo0.write(servo0.read()+1);
        break;
    }
  }
}
void loop() { //============================================================ VOID LOOP ==============
  char key = keypad.getKey(); // initialize key to NO_Key
 
  while (key == NO_KEY){
      key = keypad.getKey();
    }

    switch (key) {
      case 'A':
        initialize();
        doBottom();
        endRun();
        break;
      case 'B':
        initialize();
        doBottomLeft();
        endRun();
        break;
      case 'C':
        initialize();
        doLeft();
        endRun();
        break;
      case 'D':
        initialize();
        doRight();
        endRun();
        break;
      case '#':
        initialize();
        doTop();
        endRun();
        break;
      case '*':
        moveToStarting();
        break;
      case '4':
        servo0.write(servo0.read()-1);
        break;
      case '6':
        servo0.write(servo0.read()+1);
        break;
  }
}
