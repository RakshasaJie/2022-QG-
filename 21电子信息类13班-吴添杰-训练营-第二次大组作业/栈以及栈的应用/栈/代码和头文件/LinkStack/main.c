#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.c"

// 判断输入是否为数字
int IfNum()
{
    int guess, ret;
    guess = scanf("%d", &ret);
    while (!guess)
    {
        while (getchar() != '\n')
            ; // 清除缓冲区
        printf("\n请输入数字\n");
        guess = scanf("%d", &ret);
    }
    return ret;
}

void Menu()
{
    printf("\n\n**************************************\n");
    printf("*     现在你可执行以下操作：         *\n");
    printf("*     1.判断栈是否为空               *\n");
    printf("*     2.得到栈顶元素                 *\n");
    printf("*     3.清空栈                       *\n");
    printf("*     4.检测栈长度                   *\n");
    printf("*     5.入栈                         *\n");
    printf("*     6.出栈                         *\n");
    printf("*     7.销毁并退出程序               *\n");
    printf("**************************************\n");
    printf("请选择菜单编号:");
}

int main()
{
    LinkStack *s = NULL;
    s = (LinkStack *)malloc(sizeof(LinkStack));
    // 初始化栈
    initLStack(s);
    while (1)
    {
        // 菜单栏
        Menu();

        int option;
        option = IfNum();

        switch (option)
        {
        case 1:
        {
            if (isEmptyLStack(s))
            {
                printf("\n栈内为空\n");
            }
            else
            {
                printf("\n栈非空\n");
            }
            break;
        }
        case 2:
        {
            int d;
            if (getTopLStack(s, &d))
            {
                printf("\n操作完成\n");
                printf("\n栈顶元素为：%d\n", d);
            }
            else
            {
                printf("\n操作失败\n");
            }
            break;
        }
        case 3:
        {
            if (clearLStack(s))
            {
                printf("\n清空操作完成\n");
            }
            else
            {
                printf("\n清空操作失败\n");
            }
            break;
        }
        case 4:
        {
            int d;
            if (LStackLength(s, &d))
            {
                printf("\n操作完成\n");
                printf("\n栈的长度为：%d\n", d);
            }
            else
            {
                printf("\n操作失败\n");
            }
            break;
        }
        case 5:
        {
            int d;
            printf("\n请输入你想存入栈的元素：\n");
            d = IfNum();
            if (pushLStack(s, d))
            {
                printf("\n操作完成\n");
            }
            else
            {
                printf("\n操作失败\n");
            }
            break;
        }
        case 6:
        {
            int d;
            if (popLStack(s, &d))
            {
                printf("\n操作完成\n");
                printf("\n出栈元素为：%d\n", d);
            }
            else
            {
                printf("\n操作失败\n");
            }
            break;
        }
        case 7:
        {
            if (destroyLStack(s))
            {
                printf("\n销毁操作完成\n");
            }
            printf("\n您已退出程序，拜拜！");
            exit(0);
        }

        default:
            printf("\n没有这个选项，请重新选择。\n");
            break;
        }
    }
    return 0;
}