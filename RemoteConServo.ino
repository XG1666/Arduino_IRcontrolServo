#include<Servo.h>
#include<IRremote.h>//include tow heads.one for servo and the other for IRremoteController    引用两个头文件，一个负责舵机驱动，另一个负责红外远程遥控

Servo servo;
int pos = 0;//initialize servo and define an int for its position(its angle)   初始化舵机并定义它的位置（转动角度）

IRrecv irrecv(8);
decode_results results;
int dir = 0;//initialize IR remote controller.point its pin and define its decoded figure name   初始化红外远程遥控器。指定它的引脚，并定义其解码数据的名称

void setup() {
  // put your setup code here, to run once:
  servo.attach(9);//attach servo to pin 9 (supporting pwm)   将舵机附于引脚9（支持pwm）
  servo.write(pos);//initialize servo's position   初始化舵机的位置

  irrecv.enableIRIn();//initialize IRreciever   初始化红外接收器

  Serial.begin(9600);//initialize serial   初始化串口监视器
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results))//execute when recieve IR signal   当接收到红外信号时执行
  {
    dir = results.value;//assign results' value to dir   将results的值赋给dir
    Serial.println(dir,HEX);
    Serial.println(results.value,HEX);//print dir's and results' values just in case   以防万一，在串口监视器打印dir和results的值
    pos += turn(dir);//change pos's value according to dir's value(button)   根据dir的值（即按钮）改变pos的值
    irrecv.resume();//resume results'value   重置results的值
    if(pos < 0)
    {
      pos = 0;
    }
    else if(pos > 180)
    {
      pos = 180;
    }//logical judge.limit pos's value between 0 and 180   逻辑判断。将pos的值限定在0到180
    servo.write(pos);//rotate the servo   舵机旋转
    Serial.println(pos);
  }
}

int turn(double i)//return different value as angle according to the button   根据按键反馈不同值作为旋转角度
{
  if(i == 0x20DF)
  {
    return -10;
  }
  else if(i == 0x609F)
  {
    return 10;
  }
  else
  {
    return 0;
  }
}

