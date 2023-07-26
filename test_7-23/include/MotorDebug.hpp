#pragma once
#ifndef MotorDebug_HPP
#define MotorDebug_HPP

#include "variable.hpp"
#include "Put.hpp"

using namespace varity;

//获取右前轮编码器的值
void getEncoder_R1(void);

//获取左前轮编码器的值
void getEncoder_L1(void);

//获得右后轮编码器的值
void getEncoder_R2(void);

//获得左后轮编码器的值
void getEncoder_L2(void);

//电机左前的PID算法
int pidController_L(float  targetVelocity, float currentVelocity);

//电机右前的PID算法
int pidController_R(float targetVelocity, float currentVelocity);

//电机左后的PID算法
int pidController_L2(float  targetVelocity, float currentVelocity);

//电机右后的PID算法
int pidController_R2(float targetVelocity, float currentVelocity);






#endif