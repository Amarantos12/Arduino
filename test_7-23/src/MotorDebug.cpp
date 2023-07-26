#include "MotorDebug.hpp"
#include <Arduino.h>
#include "variable.hpp"
#include "Put.hpp"

using namespace varity;

void getEncoder_L1(void){
    if(digitalRead(ENCODER_A_L) == LOW){
    if (digitalRead(ENCODER_B_L)== LOW){
      encoderVal_L1--;
    }
    else{
      encoderVal_L1++;
    }
  }
  else{
    if (digitalRead(ENCODER_B_L) == LOW){
      encoderVal_L1++;
  }
  else{
    encoderVal_L1--;
  }
  }
}

void getEncoder_R1(void){
    if(digitalRead(ENCODER_A_R)== LOW){
    if (digitalRead(ENCODER_B_R)== LOW){
      encoderVal_R1--;
    }
    else{
    encoderVal_R1++;
  }
  }
 else{
    if (digitalRead(ENCODER_B_R)== LOW){
      encoderVal_R1++;
  }
  else{
      encoderVal_R1--;
    }
    }
}

void getEncoder_R2(void){
  if(digitalRead(ENCODER_A_R2) == LOW){
    if (digitalRead(ENCODER_B_R2)== LOW){
      encoderVal_R2--;
    }
    else{
      encoderVal_R2++;
    }
  }
  else{
    if (digitalRead(ENCODER_B_R2)== LOW){
      encoderVal_R2++;
  }
  else{
    encoderVal_R2--;
  }
  }
}

void getEncoder_L2(void){
  if(digitalRead(ENCODER_A_L2) == LOW){
    if (digitalRead(ENCODER_B_L2)== LOW){
      encoderVal_L2--;
    }
    else{
      encoderVal_L2++;
    }
  }
  else{
    if (digitalRead(ENCODER_B_L2)== LOW){
      encoderVal_L2++;
  }
  else{
    encoderVal_L2--;
  }
  }
}

int pidController_L(float  targetVelocity, float currentVelocity)
{
   float ek_L0;
     ek_L0 = targetVelocity - currentVelocity;
     u_L = u_L + q0_L * ek_L0 + q1_L * ek_L1 + q2_L * ek_L2;
    if (u_L > 255)
    {
      u_L = 255;
    }
     if (u_L < -255)
   {
     u_L = -255;
   }
     ek_L2 = ek_L1;
     ek_L1 = ek_L0;
     return (int)u_L;
}

int pidController_R(float targetVelocity, float currentVelocity)
{
  float ek_R0;
    ek_R0 = targetVelocity - currentVelocity;
    u_R = u_R + q0_R * ek_R0 + q1_R * ek_R1 + q2_R * ek_R2;
    if (u_R > 255)
    {
      u_R = 255;
    }
    if (u_R < -255)
    {
      u_R = -255;
    }
     ek_R2 = ek_R1;
     ek_R1 = ek_R0;
     return (int)u_R;
}

int pidController_L2(float  targetVelocity, float currentVelocity)
{
  float ek_L0;
     ek_L0 = targetVelocity - currentVelocity;
     u_L2 = u_L2 + q0_L * ek_L0 + q1_L * ek_L12 + q2_L * ek_L22;
    if (u_L2 > 255)
    {
      u_L2 = 255;
    }
     if (u_L2 < -255)
   {
     u_L2 = -255;
   }
     ek_L22 = ek_L12;
     ek_L12 = ek_L0;
     return (int)u_L2;
}

int pidController_R2(float targetVelocity, float currentVelocity)
{
  float ek_R0;
    ek_R0 = targetVelocity - currentVelocity;
    u_R2 = u_R2 + q0_R * ek_R0 + q1_R * ek_R12 + q2_R * ek_R22;
    if (u_R2 > 255)
    {
      u_R2 = 255;
    }
    if (u_R2 < -255)
    {
      u_R2 = -255;
    }
     ek_R22 = ek_R12;
     ek_R12 = ek_R0;
     return (int)u_R2;
}
