#include <Arduino.h>
#include "variable.hpp"
#include "Put.hpp"
#include "MotorDebug.hpp"

using namespace varity;

void control(){
    //左前轮速度
    velocity_L = (encoderVal_L1 / 780.0) * 3.1415 * 2.0 * (1000 / PERIOD);
    //右前轮速度
    velocity_R = (encoderVal_R1 / 780.0) * 3.1415 * 2.0 * (1000 / PERIOD);
    encoderVal_L1 = 0;
    encoderVal_R1 = 0;
    //左后轮速度
    velocity_L2 = (encoderVal_L2 / 780.0) * 3.1415 * 2.0 * (1000 / PERIOD);
    //右后轮速度
    velocity_R2 = (encoderVal_R2 / 780.0) * 3.1415 * 2.0 * (1000 / PERIOD);
    encoderVal_L2 = 0;
    encoderVal_R2 = 0;

    target_L = target_L*0.6 + t_L * 0.4;
    target_R = target_R*0.6 + t_R * 0.4;
    target_L2 = target_L2*0.6 + t_L2 * 0.4;
    target_R2 = target_R2*0.6 + t_R2 * 0.4;

    int output_L = pidController_L(-target_L, velocity_L);
    if(output_L>0)
    {
    digitalWrite(IN3_L, LOW);
    digitalWrite(IN4_L, HIGH);
    analogWrite(EN_2, output_L);
    }
    else
    {
    digitalWrite(IN3_L,HIGH);
    digitalWrite(IN4_L, LOW);
    analogWrite(EN_2,abs(output_L));

    }
    int output_R = pidController_R(target_R, velocity_R);
    if(output_R>0)
    {
    digitalWrite(IN1_R, LOW);
    digitalWrite(IN2_R, HIGH);
    analogWrite(EN_1, output_R);
    }
    else
    {
    digitalWrite(IN1_R,HIGH);
    digitalWrite(IN2_R, LOW);
    analogWrite(EN_1,abs(output_R));

    }
    int output_L2 = pidController_L2(-target_L2, velocity_L2);
    if(output_L2>0)
    {
    digitalWrite(IN3_L, LOW);
    digitalWrite(IN4_L, HIGH);
    analogWrite(EN_4, output_L2);
    }
    else
    {
    digitalWrite(IN7_L,HIGH);
    digitalWrite(IN8_L, LOW);
    analogWrite(EN_4,abs(output_L2));

    }
    int output_R2 = pidController_R2(target_R2, velocity_R2);
    if(output_R2>0)
    {
    digitalWrite(IN5_R, LOW);
    digitalWrite(IN6_R, HIGH);
    analogWrite(EN_3, output_R2);
    }
    else
    {
    digitalWrite(IN5_R,HIGH);
    digitalWrite(IN6_R, LOW);
    analogWrite(EN_3,abs(output_R2));

    }
    t_L = target_L;
    t_R = target_R;
    t_L2= target_L2;
    t_R2= target_R2;

}

/*
    digitalWrite(IN1_R,LOW);
     digitalWrite(IN2_R,HIGH);
     digitalWrite(EN_1,HIGH);  //右前轮正转

     digitalWrite(IN3_L,LOW);
     digitalWrite(IN4_L,HIGH);
     digitalWrite(EN_2,HIGH);  //左前轮正转

     digitalWrite(IN5_R,HIGH);
     digitalWrite(IN6_R,LOW);
     digitalWrite(EN_3,HIGH);  //右后轮正转

     digitalWrite(IN7_L,LOW);
     digitalWrite(IN8_L,HIGH);
     digitalWrite(EN_4,HIGH);  //左后轮正转
*/


