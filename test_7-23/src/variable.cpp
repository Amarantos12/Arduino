#include <Arduino.h>
#include "variable.hpp"

namespace varity
{
    float target_L =10.0, t_L; //左前 保守
    float target_R =10.0, t_R; //右前 速度
    float target_L2 =10.0, t_L2;//左后
    float target_R2 =10.0, t_R2;//右后
    volatile long encoderVal_L1;//编码器 左前 值
    float velocity_L; //左前轮转速
    volatile long encoderVal_R1;//编码器 右前 值
    float velocity_R; //右前轮转速
    volatile long encoderVal_R2;//编码器 右后 值
    volatile long encoderVal_L2;//编码器 左后 值
    float velocity_L2;//左后轮转速
    float velocity_R2;//右后轮转速

    float T = PERIOD;
    float q0_L = Kp_L * (1 + T / Ti_L + Td_L / T);
    float q1_L = -Kp_L * (1 + 2 * Td_L / T);
    float q2_L = Kp_L * Td_L / T;
    float q0_R = Kp_R * (1 + T / Ti_R + Td_R / T);
    float q1_R = -Kp_R * (1 + 2 * Td_R / T);
    float q2_R = Kp_R * Td_R / T;
    float u_L, ek_L1, ek_L2;
    float u_L2, ek_L12,ek_L22;
    float u_R, ek_R1, ek_R2;
    float u_R2, ek_R12,ek_R22;
    unsigned int PWM1=0;
    unsigned int PWM2=0;
    
}