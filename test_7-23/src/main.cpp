#include <Arduino.h>

#include "variable.hpp"
#include "MotorDebug.hpp"
#include "Put.hpp"

#include<MsTimer2.h>//定时器库的头文件
#include<Servo.h>

using namespace varity;


void setup() {
  //9,10 两个管脚的 PWM 由定时器 TIMER1 产生，这句程序改变 PWM 的频率，勿删
      TCCR1B = TCCR1B & B11111000 | B00000001;
     pinMode(ENCODER_A_L, INPUT);
     pinMode(ENCODER_B_L, INPUT);
     pinMode(ENCODER_A_R, INPUT);
     pinMode(ENCODER_B_R, INPUT);

     pinMode(ENCODER_A_L2, INPUT);
     pinMode(ENCODER_B_L2, INPUT);
     pinMode(ENCODER_A_R2, INPUT);
     pinMode(ENCODER_B_R2, INPUT);

     Serial.begin(9600);
     attachInterrupt(0,getEncoder_L1,CHANGE);
     attachInterrupt(1,getEncoder_R1,CHANGE);
     attachInterrupt(2,getEncoder_R2,CHANGE);
     attachInterrupt(3,getEncoder_L2,CHANGE);

     pinMode(EN_1, OUTPUT);
     pinMode(EN_2, OUTPUT);
     pinMode(EN_3, OUTPUT);
     pinMode(EN_4, OUTPUT);

     pinMode(IN1_R,OUTPUT);
     pinMode(IN2_R,OUTPUT);
     pinMode(IN3_L,OUTPUT);     
     pinMode(IN4_L,OUTPUT);
     pinMode(IN5_R,OUTPUT);
     pinMode(IN6_R,OUTPUT);
     pinMode(IN7_L,OUTPUT);
     pinMode(IN8_L,OUTPUT);
     MsTimer2::set(PERIOD,control);
     MsTimer2::start();

}

void loop() {
     Serial.print("velocity_L:");
     Serial.print(-velocity_L);
     Serial.print("\n");
     Serial.print("velocity_R:");
     Serial.println(velocity_R);
     Serial.print("velocity_L2:");
     Serial.print(-velocity_L2);
     Serial.print("\n");
     Serial.print("velocity_R2:");
     Serial.println(velocity_R2);
     

}


















