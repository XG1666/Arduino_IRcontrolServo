# Arduino_IRcontrolServo  
## Hardware  
- Arduino Uno x1
- Servo x1
![wire](https://github.com/XG1666/Arduino_IRcontrolServo/blob/main/Material/IRcontrolServo.png)  
## Software  
### Liberary  
- Servo.h  
- IRremote.h(2.6.0)
### Logics  
Arduino reads IR signal from controller.If it's right botton,the serial would recieve **FD20DF**.If it's left botton,**FD609F** would be recieved.  
So I use a function **turn** to translate the signals to angles  
```
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
```
