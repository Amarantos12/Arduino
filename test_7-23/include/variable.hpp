#pragma once
#ifndef variable_HPP
#define variable_HPP



#include <Arduino.h>
//----------------------------------定义管脚-----------------------------------

#define ENCODER_A_L 2 //电机 左前
#define ENCODER_B_L 4 //电机 左前
#define ENCODER_A_R 3 //电机 右前
#define ENCODER_B_R 5 //电机 右前

#define ENCODER_A_R2 21 //电机 右后
#define ENCODER_B_R2 25 //电机 右后
#define ENCODER_A_L2 20 //电机 左后
#define ENCODER_B_L2 29 //电机 左后


#define EN_1 9 //电机 右前
#define EN_2 10//电机 左前
#define EN_3 7 //电机 右后
#define EN_4 30 //电机 左后


#define IN1_R 8 //对应IN1   右前
#define IN2_R 6 //对应IN2   右前
#define IN3_L 12//左前
#define IN4_L 11//左前
#define IN5_R 13 //右后
#define IN6_R 22 //右后
#define IN7_L 26 //左后
#define IN8_L 27 //左后

#define PERIOD 10
#define Kp_L 15//15//5.0
#define Ti_L 30//20//30//50//80.0
#define Td_L 10//10//80.0
#define Kp_R 15//15//5.0
#define Ti_R 30 //20//30//50//80.0
#define Td_R 10//10//80.0


namespace varity{
//-----------------------------------全局变量--------------------------------------


    extern float target_L , t_L; //左前 保守
    extern float target_R , t_R; //右前 速度
    extern float target_L2 , t_L2;//左后
    extern float target_R2 , t_R2;//右后
    extern volatile long encoderVal_L1;//编码器 左前 值
    extern float velocity_L; //左前轮转速
    extern volatile long encoderVal_R1;//编码器 右前 值
    extern float velocity_R; //右前轮转速
    extern volatile long encoderVal_R2;//编码器 右后 值
    extern volatile long encoderVal_L2;//编码器 左后 值
    extern float velocity_L2;//左后轮转速
    extern float velocity_R2;//右后轮转速

    extern float T ;
    extern float q0_L ;
    extern float q1_L;
    extern float q2_L ;
    extern float q0_R ;
    extern float q1_R;
    extern float q2_R ;
    extern float u_L, ek_L1, ek_L2;
    extern float u_L2, ek_L12,ek_L22;
    extern float u_R, ek_R1, ek_R2;
    extern float u_R2, ek_R12,ek_R22;
    extern unsigned int PWM1;
    extern unsigned int PWM2;
    
    //-----------------------------------测速与转向
    #define V 25.0 //基础速度

}



#endif 