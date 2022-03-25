#include <stdio.h>
#include <stdlib.h>
#include "../head/LinkStack.h"
// // ****************************************************************
// Status initLStack(LinkStack *s)
// {
//     if (!s)
//     {
//         printf("分配内存失败\n");
//         return ERROR;
//     }
//     s->top = NULL;
//     s->count = 0;
//     return SUCCESS;
// }
// Status isEmptyLStack(LinkStack *s)
// {
//     if (!s->top)
//     {
//         return SUCCESS;
//     }
//     else
//     {
//         return ERROR;
//     }
// }
// // 2.得到栈顶元素
// Status getTopLStack(LinkStack *s, ElemType *e)
// {
//     if (isEmptyLStack(s))
//     {
//         printf("\n栈内为空\n");
//         return ERROR;
//     }
//     *e = s->top->data;
//     return SUCCESS;
// }
// // 3.
// Status clearLStack(LinkStack *s)
// {
//     LinkStackPtr p;
//     p = s->top;
//     while (s->top)
//     {
//         s->top = s->top->next;
//         free(p);
//         p = s->top;
//     }
//     s->count = 0;
//     return SUCCESS;
// }
// // 5.
// //销毁栈
// Status destroyLStack(LinkStack *s)
// {
//     clearLStack(s);
//     free(s);
//     return SUCCESS;
// }
// //检测栈长度
// Status LStackLength(LinkStack *s, int *length)
// {
//     *length = s->count;
//     return SUCCESS;
// }
// // 6.
// Status pushLStack(LinkStack *s, ElemType data)
// {
//     LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
//     p->next = s->top;
//     p->data = data;
//     s->top = p;
//     s->count++;
//     return SUCCESS;
// }
// // 7.出栈
// Status popLStack(LinkStack *s, ElemType *data)
// {
//     if (isEmptyLStack(s))
//     {
//         printf("\n栈内为空\n");
//         return ERROR;
//     }
//     *data = s->top->data;
//     LinkStackPtr p = s->top;
//     s->top = s->top->next;
//     free(p);
//     s->count--;
//     return SUCCESS;
// }
// // ****************************************************************
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
            return 0;
        }

        default:
            printf("\n没有这个选项，请重新选择。\n");
            break;
        }
    }
    return 0;
}