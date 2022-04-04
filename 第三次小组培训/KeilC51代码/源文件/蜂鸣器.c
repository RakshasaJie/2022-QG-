#include "reg51.h"

sbit buzzer = P2 ^ 7;  // 有源蜂鸣器引脚声明
sbit sounder = P3 ^ 7; // 无源蜂鸣器引脚声明

unsigned int FreqTable[] = {
    63628, 63731, 63835, 63928, 64021, 64103, 64185, 64260, 64331, 64400, 64463, 64528,
    64580, 64633, 64684, 64732, 64777, 64820, 64860, 64898, 64934, 64968, 65000, 65030,
    65058, 65085, 65110, 65134, 65157, 65178, 65198, 65217, 65235, 65252, 65268, 65283};
unsigned int FreqSelect = 0;

void Timer0Init(void)
{
    // TMOD = 0x01; // 0000 0001
    //  以下代码是对上面的代码的优化
    TMOD &= 0xF0; //把TMOD的低四位清零，高四位保持不变
    //原理: 1010 0011 & 1111 0000 = 1010 0000
    TMOD |= 0x01; //把TMOD的低四位置为1，高四位保持不变

    // 50ms = 50000us  256 = 2^8   相当于 初值>>8 得到高八位
    TH0 = (65536 - 50000) / 256;
    // 得到低八位
    TL0 = (65536 - 50000) % 256;
    // 开启定时器0的中断
    ET0 = 1;
    // 开启总中断
    EA = 1;
    // 启动定时器0
    TR0 = 1;
}

void delay_ms(unsigned int x)
{
    unsigned int i, j;
    for (i = x; i > 0; i--)
    {
        for (j = 124; i > 0; j--)
            ;
    }
}

void main()
{
    Timer0Init();
    sounder = 0; // 先给引脚一个确定的电平
    while (1)
    {
        FreqSelect++;
        if (FreqSelect == 36)
        {
            FreqSelect = 0;
        }

        delay_ms(500);
        TR0 = 0;
        delay_ms(50);
        TR0 = 1;
    }

    // buzzer = 0; // 设置为高或低电平，需要根据外接的三极管触发电路决定。
    //             // 本仿真中为高电平触发电路
    //             // 因此，给P2^7引脚高电平，三极管导通，电流流经有源蜂鸣器，蜂鸣器发声
    //             // 当为低电平时，三极管关断，无电流流经有源蜂鸣器，因此不发声
    // while (1)
    // {
    //     FreqSelect++;
    //     if (FreqSelect == 36)
    //     {
    //         FreqSelect = 0;
    //     }

    //     delay_ms(500);
    // }
}

void Timer0_isr() interrupt 1 // 0表示外部中断0；1表示定时器中断0；2表示外部中断1；3表示定时器中断1；4表示串口中断
{
		// buzzer = !buzzer;	
		sounder = !sounder; // 通过取反实现电平的翻转
    // 所以产生了高低高低这样持续变化的信号，用于驱动无源蜂鸣器  
		// 每次中断完成后，都要重新赋初值
    TH0 = FreqTable[FreqSelect] / 256;
    TL0 = FreqTable[FreqSelect] % 256;
}