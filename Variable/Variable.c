/*在这里定义所有的变量，并允许外部引用*/
#include "stm32f10x.h"                  // Device header
#include "Variable.h"


/*动作相关*/
uint16_t Face_Mode=5;     //表情切换，上电是两个眼睛表情
uint16_t Fan_Speed=0;      // 风扇档位: 0=关闭, 1=一档, 2=二档, 3=最大
uint16_t Fan_Swing=0;      // 摇摆标志: 0=停止, 1=摇摆中
float Servo_Current=90;      // 当前角度
float Servo_Target=90;        // 目标角度
uint16_t Servo_Enable=0;      // 运动使能
int16_t Swing_Direction=1;   // 摇摆方向


/*呼吸灯相关*/
uint16_t Time;            //呼吸灯间隔时间
uint16_t HuXi;            //呼吸灯输出脉冲数
uint16_t PanDuan=1;       //呼吸灯模式
uint16_t Wait=0;          //间隔时间
uint16_t AllLed=1;        //开启灯光
uint16_t BreatheLed=0;    //初始呼吸灯

/*测电量相关*/
float Battery_Value=0;
uint16_t temp;            //每200ms测得的当前电量
uint16_t temp1=0;         //每20ms测得的当前电量
uint16_t CurBattery;      //当前电量
uint8_t Battery_num=0;    //获取电量滤波系数
uint8_t Battery_Bit=1;
