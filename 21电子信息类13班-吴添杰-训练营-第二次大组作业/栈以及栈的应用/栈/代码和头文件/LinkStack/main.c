#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.c"

// �ж������Ƿ�Ϊ����
int IfNum()
{
    int guess, ret;
    guess = scanf("%d", &ret);
    while (!guess)
    {
        while (getchar() != '\n')
            ; // ���������
        printf("\n����������\n");
        guess = scanf("%d", &ret);
    }
    return ret;
}

void Menu()
{
    printf("\n\n**************************************\n");
    printf("*     �������ִ�����²�����         *\n");
    printf("*     1.�ж�ջ�Ƿ�Ϊ��               *\n");
    printf("*     2.�õ�ջ��Ԫ��                 *\n");
    printf("*     3.���ջ                       *\n");
    printf("*     4.���ջ����                   *\n");
    printf("*     5.��ջ                         *\n");
    printf("*     6.��ջ                         *\n");
    printf("*     7.���ٲ��˳�����               *\n");
    printf("**************************************\n");
    printf("��ѡ��˵����:");
}

int main()
{
    LinkStack *s = NULL;
    s = (LinkStack *)malloc(sizeof(LinkStack));
    // ��ʼ��ջ
    initLStack(s);
    while (1)
    {
        // �˵���
        Menu();

        int option;
        option = IfNum();

        switch (option)
        {
        case 1:
        {
            if (isEmptyLStack(s))
            {
                printf("\nջ��Ϊ��\n");
            }
            else
            {
                printf("\nջ�ǿ�\n");
            }
            break;
        }
        case 2:
        {
            int d;
            if (getTopLStack(s, &d))
            {
                printf("\n�������\n");
                printf("\nջ��Ԫ��Ϊ��%d\n", d);
            }
            else
            {
                printf("\n����ʧ��\n");
            }
            break;
        }
        case 3:
        {
            if (clearLStack(s))
            {
                printf("\n��ղ������\n");
            }
            else
            {
                printf("\n��ղ���ʧ��\n");
            }
            break;
        }
        case 4:
        {
            int d;
            if (LStackLength(s, &d))
            {
                printf("\n�������\n");
                printf("\nջ�ĳ���Ϊ��%d\n", d);
            }
            else
            {
                printf("\n����ʧ��\n");
            }
            break;
        }
        case 5:
        {
            int d;
            printf("\n�������������ջ��Ԫ�أ�\n");
            d = IfNum();
            if (pushLStack(s, d))
            {
                printf("\n�������\n");
            }
            else
            {
                printf("\n����ʧ��\n");
            }
            break;
        }
        case 6:
        {
            int d;
            if (popLStack(s, &d))
            {
                printf("\n�������\n");
                printf("\n��ջԪ��Ϊ��%d\n", d);
            }
            else
            {
                printf("\n����ʧ��\n");
            }
            break;
        }
        case 7:
        {
            if (destroyLStack(s))
            {
                printf("\n���ٲ������\n");
            }
            printf("\n�����˳����򣬰ݰݣ�");
            exit(0);
        }

        default:
            printf("\nû�����ѡ�������ѡ��\n");
            break;
        }
    }
    return 0;
}