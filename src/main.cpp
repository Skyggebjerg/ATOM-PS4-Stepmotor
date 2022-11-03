#include <Arduino.h>
#include <PS4Controller.h>
#include <M5Atom.h>

#include "StepperDriver.h"

int motor_steps = 200;    
int step_divisition = 32;
int en_pin = 22;
int dir_pin = 23;
int step_pin = 19;

int step = 0;
int speed = 0;


StepperDriver ss(motor_steps, step_divisition, en_pin, dir_pin, step_pin);  

void setup()
{
  M5.begin(true, false, true);
  Serial.begin(115200);
  PS4.begin("b0:52:16:e3:5b:02");
  Serial.println("Ready.");
  ss.setSpeed(0);
  //ss.powerEnable(true);
  delay(1600);
}

void loop()
{
   if (PS4.isConnected()) {
   ss.powerEnable(true);
    if (PS4.Square()) {
      Serial.println("Square Button");
      ss.setSpeed(300);
      ss.step(1000);
    }

    if (PS4.Circle()) {
      Serial.println("Circle Button");
      ss.setSpeed(300);
      ss.step(-1000);
    }
    if (PS4.Triangle()) {
      Serial.println("Triangle Button");
      ss.setSpeed(100);
      ss.step(500);
    }
    if (PS4.Cross()) {
      Serial.println("Cross Button");
      ss.setSpeed(100);
      ss.step(-500);
    }

   }
   else {
    ss.powerEnable(false);
    }

   //delay(1000);
   //M5.update();
}