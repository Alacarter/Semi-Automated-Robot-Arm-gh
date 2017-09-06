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

int nudgeOpenAngle = 75;
int closeAngle = 25;
int openAngle = 140;

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

Servo servo0, servo1, servo2, servo3, servo4, servo5, servo6; //servo5 = opener; servo6 = swiper

boolean goOn = false; // key to moving on after keypad input.

void setup() {
  Serial.begin(9600);
  servo0.attach(3); 
  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(9);
  servo4.attach(10);
  servo5.attach(11);
  servo6.attach(12);

  rest();
  openClaw();
  flipToGrabber();
  Starting();

  /*
  //TOP STACK==========================
  Move0(97);
  Move2(126);
  Move1(144);
  Move3(69);
  closeClaw();
  Move2(110);
  flipToSwiper();
  */
  /*
  flipToGrabber();
  */
  //LEFT STACK=========================
  Move0(76);
  Move2(73);
  Move1(113);
  Move3(25);
  while (goOn == false)
  {
    Move01Key();
    Serial.println("Go on is false");
  }
  goOn = false;
  Move1(118);
  Move3(33);
  closeClaw();
  Move1(105);
  flipToSwiper();
  Move1(100);
  Move0(98);
  Move2(64);
  Move3(68);
  swipeTenRight();
  
  //RIGHT STACK======================== (Complete Draft)
  /*
  Move0(114);
  Move2(74);
  Move1(100);
  Move3(25);
  while (goOn == false)
  {
    Move01Key();
    Serial.println("Go on is false");
  }
  goOn = false;
  Move1(105);
  Move3(33);
  closeClaw();
  Move1(95);
  flipToSwiper();
  Move1(90);
  Move0(109);
  Move2(63);
  Move3(52);
  swipeTenRight();
  */

  //BOTTOM LEFT STACK================== (Complete Draft)
  //Moving to Bottom Left
  /*
  Move0(10);
  Move2(43);
  while (goOn == false)
  {
    Move01Key();
    Serial.println("Go on is false");
  }
  goOn = false;
  Move1(108);
  Move3(17);
  //Bottom Left Close Flip

  closeClaw();
  Move1(102);
  flipToSwiper();
  Move1(89);
  Move0(87);
  Move2(56);
  Move3(60);
  swipeTen();


  //BOTTOM STACK=======================
  Move0(93);
  Move2(26);
  Move1(86);
  Move3(14);
  */
}

/*
 * Format of Coordinates:
 * Servo (0,1,2,3)
 * 
 * Starting Position
 * (81, 81, 10, 0)
 * 
 * 
 * Bottom Left Penny Stack
 * (16,108,43,17)
 * 
 * //Bottom Left Penny Stack (before scoop)
 * //(0,109,44,15)
 * 
 * //Bottom Left Penny Stack (after scoop)
 * //(17, 107, 49, 15)
 * 
 * Depositing Left Penny Stack onto target
 * (81, 94, 65, 38)
 */
void loop() {

}

void rest() {
  servo0.write(0);
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
}

void Starting() {
  for (int i = 0; i <= 81; i++)
  {
     servo0.write(i);
     servo1.write(i);
     servo2.write((int)(i/8));
     servo3.write(0);
     delay(50);
  }
}

void Move01Key() {
  char key = keypad.getKey(); // initialize key to NO_Key
 
  while (key == NO_KEY){
    key = keypad.getKey();
  }

  switch (key) {
      case '2':
        servo1.write(servo1.read()-1);
        break;
      case '3':
        servo2.write(servo2.read()-1);
        break;
      case '4':
        servo0.write(servo0.read()-1);
        break;
      case '6':
        servo0.write(servo0.read()+1);
        break;
      case '8':
        servo1.write(servo1.read()+1);
        break;
      case '9':
        servo2.write(servo2.read()+1);
        break;
      case 'D': // Enter special case delayCruise vale here
        goOn = true;
        break;
  }
}

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

void flipToGrabber() {
  servo4.write(8);
}

void openClaw() {
  for (int i = closeAngle; i<openAngle; i++)
   {
      servo5.write(i);
      delay(5); 
   }
   delay(5000);
}

void closeClaw() {
   for (int i = openAngle; i>closeAngle; i--)
   {
      servo5.write(i);
   }
   delay(2000);  
}

void flipToSwiper() {
  servo4.write(180);
  delay(1000);
  for (int i = 30; i<nudgeOpenAngle; i++)
   {
      servo5.write(i); 
   }
   delay(500);
  for (int i = nudgeOpenAngle; i>30; i--)
   {
      servo5.write(i);
   }
  delay(500);
}

void swipeTenBottomLeft() {
  for (int i = 1; i<= 11; i++)
  {
     for (int i = 35; i<85; i++)
     {
        servo6.write(i);
        delay(3); 
     }
     delay(500);
     for (int i = 85  ; i>35; i--)
     {
        servo6.write(i);
        delay(3);
     }
     movePennyWidthRight();
     delay(1000);
  }
}

void swipeTenRight() {
  for (int i = 1; i<= 11; i++)
  {
     for (int i = 35; i<85; i++)
     {
        servo6.write(i);
        delay(3); 
     }
     delay(500);
     for (int i = 85  ; i>35; i--)
     {
        servo6.write(i);
        delay(3);
     }
     movePennyWidthLeft();
     delay(1000);
  }
}

void swipeTenLeft() {
  for (int i = 1; i<= 11; i++)
  {
     for (int i = 35; i<85; i++)
     {
        servo6.write(i);
        delay(3); 
     }
     delay(500);
     for (int i = 85  ; i>35; i--)
     {
        servo6.write(i);
        delay(3);
     }
     movePennyWidthRight();
     delay(1000);
  }
}
void movePennyWidthRight() {
  int i = servo0.read();
  for (int j = 0; j < 3; j++)
  {
    i++;
    delay(500);
  }
  servo0.write(i);
}

void movePennyWidthLeft() {
  int i = servo0.read();
  for (int j = 0; j < 3; j++)
  {
    i--;
    delay(500);
  }
  servo0.write(i);
}

