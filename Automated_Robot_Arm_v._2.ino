#include <Servo.h>
Servo servo0, servo1, servo2, servo3, servo4, servo5, servo6; //servo5 = opener; servo6 = swiper

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


  //TOP STACK==========================
  Move0(97);
  Move2(126);
  Move1(144);
  Move3(69);
  closeClaw();
  Move2(110);
  flipToSwiper();

  /*
  flipToGrabber();

  //RIGHT STACK========================
  Move0(118);
  Move2(81);
  Move1(105);
  Move3(33);

  
  //BOTTOM LEFT STACK==================
  //Moving to Bottom Left
  Move0(10);
  Move2(43);
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


  //LEFT STACK=========================
  Move0(76);
  Move2(73);
  Move1(118);
  Move3(33);


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

void flipToGrabber() {
  servo4.write(8);
}

void openClaw() {
  for (int i = 40; i<120; i++)
   {
      servo5.write(i);
      delay(5); 
   }
   delay(5000);
}

void closeClaw() {
   for (int i = 120; i>40; i--)
   {
      servo5.write(i);
   }
   delay(2000);  
}

void flipToSwiper() {
  servo4.write(180);
}

void swipeTen() {
  for (int i = 1; i<= 5; i++)
  {
     for (int i = 30; i<85; i++)
     {
        servo6.write(i);
        delay(3); 
     }
     delay(500);
     for (int i = 85  ; i>30; i--)
     {
        servo6.write(i);
        delay(3);
     }
     movePennyWidth();
     delay(1000);
  }
}

void movePennyWidth() {
  int i = servo0.read();
  for (int j = 0; j < 3; j++)
  {
    i++;
    delay(500);
  }
  servo0.write(i);
}

