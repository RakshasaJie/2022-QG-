/* 实现按键每按下一次，计数加一 */

#include "reg51.h"

unsigned char string[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned char num = 0;

void initcounter()
{
    // 8位自动重置计数器
    // 计数值为N和初值X关系：	X = 256 - N/(12/fosc), fosc约等于12
    TMOD &= 0xF0; //把TMOD的低四位清零，高四位保持不变
    TMOD |= 0x06; //把TMOD的低四位置为0110，高四位保持不变
    TH0 = 256 - 1;
    TL0 = 256 - 1;
    ET0 = 1; // 开启定时器0的中断
    EA = 1;  // 开启总中断
    TR0 = 1; // 启动定时器0
}

void display()
{
    P2 = string[num];
    if (num == 10)
    {
        num = 0;
    }
}

void main()
{
    initcounter();
    while (1)
    {
        display();
    }
}

void counter_isr() interrupt 1
{
    num++;
}