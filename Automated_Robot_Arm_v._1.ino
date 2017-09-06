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
  Starting();
  Move0(81,13);
  Move2(10,43);
  Move1(81,108);
  Move3(0,17);
  Move0(13,14);
  /*
  BottomLeft0();
  BottomLeft2();
  BottomLeft1();
  BottomLeft3();
  BottomLeftBefore0();
  BottomLeftBefore3();
  BottomLeftBefore2();
  BottomLeftBefore1();
  BottomLeftAfter0123();
  ShoulderLift();
  DepositBottomLeft01();
  DepositBottomLeft3();
  DepositBottomLeft2();
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

void Move0(int before, int after) {
  if (after > before)
  {
     for (int i = before; i <= after; i++)
     {
         servo0.write(i);
         delay(50);
     }
  }
  if (after < before)
  {
     for (int i = before; i >= after; i--)
     {
         servo0.write(i);
         delay(50);
     }
  }
}

void Move1(int before, int after) {
  if (after > before)
  {
     for (int i = before; i <= after; i++)
     {
         servo1.write(i);
         delay(50);
     }
  }
  if (after < before)
  {
     for (int i = before; i >= after; i--)
     {
         servo1.write(i);
         delay(50);
     }
  }
}

void Move2(int before, int after) {
  if (after > before)
  {
     for (int i = before; i <= after; i++)
     {
         servo2.write(i);
         delay(50);
     }
  }
  if (after < before)
  {
     for (int i = before; i >= after; i--)
     {
         servo2.write(i);
         delay(50);
     }
  }
}

void Move3(int before, int after) {
  if (after > before)
  {
     for (int i = before; i <= after; i++)
     {
         servo3.write(i);
         delay(50);
     }
  }
  if (after < before)
  {
     for (int i = before; i >= after; i--)
     {
         servo3.write(i);
         delay(50);
     }
  }
}

void BottomLeft0() {
  for (int i = 81; i >= 12 ; i--)
  {
     servo0.write(i);
     delay(50);
  }
  servo1.write(108);
}

void BottomLeft1() {
  for (int i = 81; i <= 108; i++)
  {
     servo1.write(i);
     delay(50);
  }
}
void BottomLeft2() {
  for (int i = 10; i <= 43; i++)
  {
     servo2.write(i);
     delay(50);
  }
}

void BottomLeft3() {
  for (int i = 0; i <= 17; i++)
  {
     servo3.write(i);
     delay(50);
  }
}
/*
void BottomLeftBefore0() {
  for (int i = 81; i>=0; i--)
  {
     servo0.write(i);
     delay(50);
  }
}
void BottomLeftBefore1() {
  for (int i = 81; i <= 109; i++)
  {
     servo1.write(i);
     delay(50);
  }
  servo0.write(0);
}

void BottomLeftBefore2() {
  for (int i = 10; i<= 44; i++)
  {
     servo2.write(i);
     delay(50);
  }
}

void BottomLeftBefore3() {
  for (int i = 0; i <= 15; i++)
  {
     servo3.write(i);
     delay(50);
  }
}


//Open the claw

void BottomLeftAfter0123() {
  for (int i = 0; i<=17; i++)
  {
     servo0.write(i);
     delay(20);
  }
  servo1.write(107);
  servo2.write(49);
  servo3.write(15);
}

*/
// Close the claw
//Flip the container

void ShoulderLift() {
  int i = servo1.read();
  for (int j; j <= 15; j++)
  {
     servo1.write(i-j);
     delay(50);
  }
  
}
void DepositBottomLeft01() {
  for (int i = 17; i<= 81; i++)
  {
     servo0.write(i);
     delay(50);
  }
  servo1.write(94);
}

void DepositBottomLeft2 () {
  for (int i = 49; i <= 65; i++)
  {
     servo2.write(i);
     delay(50);
  }
}

void DepositBottomLeft3() {
  for (int i = 15; i <= 38; i++)
  {
     servo3.write(i);
     delay(50);
  }
}

