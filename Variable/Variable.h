#ifndef __VARIABLE_H_
#define __VARIABLE_H_

#define SERVO_STEP    1       // 每20ms移动的角度
#define SWING_LEFT    0         // 左边界
#define SWING_RIGHT   120        // 右边界

/*模式相关*/
extern uint16_t Face_Mode;       //表情切换
extern uint16_t Fan_Speed;      // 风扇档位: 0=关闭, 1=一档, 2=二档, 3=最大
extern uint16_t Fan_Swing;      // 摇摆标志: 0=停止, 1=摇摆中
extern float Servo_Current;      // 当前角度
extern float Servo_Target;        // 目标角度
extern uint16_t Servo_Enable;      // 运动使能
extern int16_t Swing_Direction ;   // 摇摆方向

/*呼吸灯相关*/
extern uint16_t Time;            //呼吸灯间隔时间
extern uint16_t HuXi;            //呼吸灯输出脉冲数
extern uint16_t PanDuan;         //呼吸灯模式
extern uint16_t Wait;            //间隔时间
extern uint16_t AllLed;          //开启灯光
extern uint16_t BreatheLed;    //开启呼吸灯

/*测电量相关*/
extern float Battery_Value;
extern uint16_t temp;            //每200ms测得的当前电量
extern uint16_t temp1;           //每20ms测得的当前电量
extern uint16_t CurBattery;      //当前电量
extern uint8_t Battery_num;      //获取电量滤波系数
extern uint8_t Battery_Bit;
#endif
