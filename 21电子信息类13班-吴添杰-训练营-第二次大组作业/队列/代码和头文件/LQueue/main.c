#include "LQueue.c"

void Menu()
{
    printf("\n**************************************\n");
    printf("*     现在你可执行以下操作：         *\n");
    printf("*     1.判断队列是否为空             *\n");
    printf("*     2.查看队头元素                 *\n");
    printf("*     3.检测队列长度                 *\n");
    printf("*     4.入队                         *\n");
    printf("*     5.出队                         *\n");
    printf("*     6.清空队列                     *\n");
    printf("*     7.遍历                         *\n");
    printf("*     8.销毁并退出程序               *\n");
    printf("**************************************\n");
    printf("请选择菜单编号:");
}

int main()
{
    LQueue *Q = NULL;
    Q = (LQueue *)malloc(sizeof(LQueue));
    // 初始化队列
    InitLQueue(Q);
    ChooseType(Q);
    while (1)
    {
        Menu();
        int option;
        option = IfNum();

        switch (option)
        {
        case 1: // 1.判断队列是否为空
        {
            if (IsEmptyLQueue(Q))
            {
                printf("\n队列为空\n");
            }
            else
            {
                printf("\n队列非空\n");
            }
            break;
        }
        case 2: // 2.查看队头元素
        {
            void *e;
            e = (void *)malloc(Q->data_size);
            if (GetHeadLQueue(Q, e))
            {
                printf("\n队头元素为：");
                if (Q->data_size == sizeof(int))
                {
                    printf("%d\n", *(int *)e);
                }
                else if (Q->data_size == sizeof(char))
                {
                    printf("%c\n", *(char *)e);
                }
                else if (Q->data_size == sizeof(double))
                {
                    printf("%lf\n", *(double *)e);
                }
            }
            else
            {
                printf("\n队列为空\n");
            }
            break;
        }
        case 3: // 3.检测队列长度
        {
            printf("\n队列长度为：%d\n", LengthLQueue(Q));
            break;
        }
        case 4: // 4.入队
        {
            printf("请输入入队元素：");
            void *data;
            if (Q->data_size == sizeof(int))
            {
                data = (int *)malloc(sizeof(int));
                while (scanf("%d", (int *)data) != 1)
                {
                    printf("请输入正确类型\n");
                    while (getchar() != '\n')
                        ;
                }
            }
            else if (Q->data_size == sizeof(char))
            {
                setbuf(stdin, NULL); // 清屏
                data = (char *)malloc(sizeof(char));
                scanf(" %c", (char *)data); // 空格吃回车
                while (getchar() != '\n')
                        ; // 清除缓冲区
            }
            else if (Q->data_size == sizeof(double))
            {
                data = (double *)malloc(sizeof(double));
                while (scanf("%lf", (double *)data) != 1)
                {
                    printf("请输入正确类型\n");
                    while (getchar() != '\n')
                        ;
                }
            }
            // data = (void *)malloc(Q->data_size);

            if (EnLQueue(Q, data))
            {
                printf("\n操作成功\n");
            }
            else
            {
                printf("\n操作失败\n");
            }
            break;
        }
        case 5: // 5.出队
        {
            if (DeLQueue(Q))
            {
                printf("\n操作成功\n");
            }
            else
            {
                printf("\n操作失败，队列为空\n");
            }
            break;
        }
        case 6: // 6.清空队列
        {
            ClearLQueue(Q);
            printf("\n清空操作完成\n");
            break;
        }
        case 7: // 7.遍历
        {
            if (TraverseLQueue(Q, LPrint))
            {
                printf("\n操作成功\n");
            }
            else
            {
                printf("\n操作失败，队列为空\n");
            }
            break;
        }
        case 8: // 8.销毁并退出程序
        {
            DestoryLQueue(Q);
            printf("\n您已退出程序，拜拜！");
            exit(0);
            break;
        }
        default:
            printf("\n没有这个选项，请重新选择。\n");
            break;
        }
    }
    return 0;
}