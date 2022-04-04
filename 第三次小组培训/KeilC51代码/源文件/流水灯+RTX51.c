#include "reg51.h" // 先去用户自定义的路径查找，再去系统默认路径查找
#include "rtx51tny.h"

// unsigned char leddat[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
unsigned char leddat[50] = {0X01, 0X02, 0X04, 0X08, 0X10, 0X20, 0X40, 0X80, 0X81, 0X82,
							0X84, 0X88, 0X90, 0XA0, 0XC0, 0XC1, 0XC2, 0XC4, 0XC8, 0XD0, 0XE0, 0XE1, 0XE2, 0XE4, 0XE8, 0XF0, 0XF1, 0XF2, 0XF4, 0XF8, 0XF9, 0XFA, 0XFC, 0XFD, 0XFE, 0XFF, 0XFF, 0X00, 0XFF, 0X00};

void delay(unsigned int n) // 延时函数
{
	unsigned int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 120; j++)
			;
	}
}

// void led() // 流水灯函数
// {
// 	int i;
// 	for (i = 0; i < 50; i++)
// 	{
// 		// 初始版本：
// 		// P2 = ~(0x01<<i); // 0x01 = 0000 0001

// 		// 通用方法：
// 		P2 = ~leddat[i];
// 		// 共阳极，需要低电平才能让灯亮，所以需要取反
// 		delay(50);

// 		// P1 = 0x01<<i;
// 		// 通用方法：
// 		P1 = leddat[i];
// 		// 共阴极，需要高电平才能让灯亮
// 		delay(50);
// 	}
// }

void main_job() _task_ 0
{
	// while(1)
	// {
	// 	led();
	// }
	os_create_task(1); // task1

	os_create_task(2); // task2

	os_delete_task(0); // delet task0
}

void led1_job() _task_ 1
{
	int i;
	for (i = 0; i < 50; i++)
	{
		P2 = ~leddat[i];
		// 共阳极，需要低电平才能让灯亮，所以需要取反
		delay(50);
	}
}

void led2_job() _task_ 2
{
	int i;
	for (i = 0; i < 50; i++)
	{
		P1 = leddat[i];
		// 共阴极，需要高电平才能让灯亮
		delay(50);
	}
}