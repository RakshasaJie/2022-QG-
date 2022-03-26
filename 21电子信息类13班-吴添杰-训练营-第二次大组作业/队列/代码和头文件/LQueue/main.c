#include "LQueue.c"

void Menu()
{
    printf("\n**************************************\n");
    printf("*     �������ִ�����²�����         *\n");
    printf("*     1.�ж϶����Ƿ�Ϊ��             *\n");
    printf("*     2.�鿴��ͷԪ��                 *\n");
    printf("*     3.�����г���                 *\n");
    printf("*     4.���                         *\n");
    printf("*     5.����                         *\n");
    printf("*     6.��ն���                     *\n");
    printf("*     7.����                         *\n");
    printf("*     8.���ٲ��˳�����               *\n");
    printf("**************************************\n");
    printf("��ѡ��˵����:");
}

int main()
{
    LQueue *Q = NULL;
    Q = (LQueue *)malloc(sizeof(LQueue));
    // ��ʼ������
    InitLQueue(Q);
    ChooseType(Q);
    while (1)
    {
        Menu();
        int option;
        option = IfNum();

        switch (option)
        {
        case 1: // 1.�ж϶����Ƿ�Ϊ��
        {
            if (IsEmptyLQueue(Q))
            {
                printf("\n����Ϊ��\n");
            }
            else
            {
                printf("\n���зǿ�\n");
            }
            break;
        }
        case 2: // 2.�鿴��ͷԪ��
        {
            void *e;
            e = (void *)malloc(Q->data_size);
            if (GetHeadLQueue(Q, e))
            {
                printf("\n��ͷԪ��Ϊ��");
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
                printf("\n����Ϊ��\n");
            }
            break;
        }
        case 3: // 3.�����г���
        {
            printf("\n���г���Ϊ��%d\n", LengthLQueue(Q));
            break;
        }
        case 4: // 4.���
        {
            printf("���������Ԫ�أ�");
            void *data;
            if (Q->data_size == sizeof(int))
            {
                data = (int *)malloc(sizeof(int));
                while (scanf("%d", (int *)data) != 1)
                {
                    printf("��������ȷ����\n");
                    while (getchar() != '\n')
                        ;
                }
            }
            else if (Q->data_size == sizeof(char))
            {
                setbuf(stdin, NULL); // ����
                data = (char *)malloc(sizeof(char));
                scanf(" %c", (char *)data); // �ո�Իس�
                while (getchar() != '\n')
                        ; // ���������
            }
            else if (Q->data_size == sizeof(double))
            {
                data = (double *)malloc(sizeof(double));
                while (scanf("%lf", (double *)data) != 1)
                {
                    printf("��������ȷ����\n");
                    while (getchar() != '\n')
                        ;
                }
            }
            // data = (void *)malloc(Q->data_size);

            if (EnLQueue(Q, data))
            {
                printf("\n�����ɹ�\n");
            }
            else
            {
                printf("\n����ʧ��\n");
            }
            break;
        }
        case 5: // 5.����
        {
            if (DeLQueue(Q))
            {
                printf("\n�����ɹ�\n");
            }
            else
            {
                printf("\n����ʧ�ܣ�����Ϊ��\n");
            }
            break;
        }
        case 6: // 6.��ն���
        {
            ClearLQueue(Q);
            printf("\n��ղ������\n");
            break;
        }
        case 7: // 7.����
        {
            if (TraverseLQueue(Q, LPrint))
            {
                printf("\n�����ɹ�\n");
            }
            else
            {
                printf("\n����ʧ�ܣ�����Ϊ��\n");
            }
            break;
        }
        case 8: // 8.���ٲ��˳�����
        {
            DestoryLQueue(Q);
            printf("\n�����˳����򣬰ݰݣ�");
            exit(0);
            break;
        }
        default:
            printf("\nû�����ѡ�������ѡ��\n");
            break;
        }
    }
    return 0;
}