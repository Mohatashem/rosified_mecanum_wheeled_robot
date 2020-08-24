#ifndef MECANUM_BASE_CONFIG_H
#define MECANUM_BASE_CONFIG_H


#define MECANUM_BASE MECANUM         // Mecanum drive robot

//uncomment the motor driver you're using
//#define USE_L298_DRIVER
#define USE_BTS7960_DRIVER
// #define USE_ESC

//uncomment the IMU you're using
//#define USE_GY85_IMU
#define USE_MPU6050_IMU
// #define USE_MPU9150_IMU
// #define USE_MPU9250_IMU

#define DEBUG 0

//=================SMALLER ROBOT SPEC (L298N)=============================
//#define K_P 0.6 // P constant
//#define K_I 0.3 // I constant
//#define K_D 0.5 // D constant
//define your robot' specs here
//#define MAX_RPM 330               // motor's maximum RPM
//#define COUNTS_PER_REV 1550       // wheel encoder's no of ticks per rev
//#define WHEEL_DIAMETER 0.10       // wheel's diameter in meters
//#define PWM_BITS 8                // PWM Resolution of the microcontroller
//#define LR_WHEELS_DISTANCE 0.235  // distance between left and right wheels
//#define FR_WHEELS_DISTANCE 0.30   // distance between front and rear wheels. Ignore this if you're on 2WD/ACKERMANN
//#define MAX_STEERING_ANGLE 0.415  // max steering angle. This only applies to Ackermann steering
//================= END OF SMALLER ROBOT SPEC =============================

//=================BIGGER ROBOT SPEC (BTS7960)=============================
#define K_P  0.6 // 0.0 //0.6 //0.3853// 0.05  // P constant
#define K_I  0.275// 0.0 //0.5//0.00975 //0.9   // I constant
#define K_D  -0.09// 0.0 //0.3//-0.085 //0.1  // D constant

//define your robot' specs here
#define MAX_RPM 350              // motor's maximum RPM
#define COUNTS_PER_REV 1493     // wheel encoder's no of ticks per rev
#define WHEEL_DIAMETER 0.08      // wheel's diameter in meters
#define PWM_BITS 8               // PWM Resolution of the microcontroller
#define LR_WHEELS_DISTANCE 0.214  // distance between left and right wheels
#define FR_WHEELS_DISTANCE 0.095  // distance between front and back wheels. Ignore this if you're on 2WD/ACKERMANN
#define MAX_STEERING_ANGLE 0.415  // max steering angle. This only applies to Ackermann steering
//================= END OF BIGGER ROBOT SPEC =============================

/*
ROBOT ORIENTATION
         FRONT
    MOTOR1  MOTOR2  (2WD/ACKERMANN)
    MOTOR3  MOTOR4  (4WD/MECANUM)  
         BACK
*/

/// ENCODER PINS
#define MOTOR1_ENCODER_A  15
#define MOTOR1_ENCODER_B  14 

#define MOTOR2_ENCODER_A  12 //11 
#define MOTOR2_ENCODER_B  11 //12  

#define MOTOR3_ENCODER_A  17
#define MOTOR3_ENCODER_B  16 

#define MOTOR4_ENCODER_A 10 // 9
#define MOTOR4_ENCODER_B  9// 10

//MOTOR PINS
#ifdef USE_L298_DRIVER
  #define MOTOR_DRIVER L298

  #define MOTOR1_PWM 21
  #define MOTOR1_IN_A 20
  #define MOTOR1_IN_B 1

  #define MOTOR2_PWM 5
  #define MOTOR2_IN_A 6 //8
  #define MOTOR2_IN_B 8 //6

  #define MOTOR3_PWM 22
  #define MOTOR3_IN_A 23
  #define MOTOR3_IN_B 0

  #define MOTOR4_PWM 4
  #define MOTOR4_IN_A 2
  #define MOTOR4_IN_B 3

  #define PWM_MAX pow(2, PWM_BITS) - 1
  #define PWM_MIN -PWM_MAX
#endif 

#ifdef USE_BTS7960_DRIVER
  #define MOTOR_DRIVER BTS7960  

  #define MOTOR1_PWM 1 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR1_IN_A 20 //21
  #define MOTOR1_IN_B 21 //20

  #define MOTOR2_PWM 8 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR2_IN_A 5
  #define MOTOR2_IN_B 6

  #define MOTOR3_PWM 0 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR3_IN_A 23 //22
  #define MOTOR3_IN_B 22//23

  #define MOTOR4_PWM 2 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR4_IN_A 4
  #define MOTOR4_IN_B 3

  #define PWM_MAX pow(2, PWM_BITS) - 1
  #define PWM_MIN -PWM_MAX
#endif

#ifdef USE_ESC
  #define MOTOR_DRIVER ESC  

  #define MOTOR1_PWM 1 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR1_IN_A 21
  #define MOTOR1_IN_B 20

  #define MOTOR2_PWM 8 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR2_IN_A 5
  #define MOTOR2_IN_B 6

  #define MOTOR3_PWM 0 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR3_IN_A 22
  #define MOTOR3_IN_B 23

  #define MOTOR4_PWM 2 //DON'T TOUCH THIS! This is just a placeholder
  #define MOTOR4_IN_A 4
  #define MOTOR4_IN_B 3

  #define PWM_MAX 400
  #define PWM_MIN -PWM_MAX
#endif

#define STEERING_PIN 7

#endif
