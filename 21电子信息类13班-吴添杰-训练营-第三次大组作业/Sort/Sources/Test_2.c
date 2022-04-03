#include "../Headers/sort.h"
#include "sort.c"

void show()
{
    printf("\t******��ѡ�����ɲ��Գ���******\n");
    printf("\t1.100*100k�����ݲ���\n");
    printf("\t2.�Զ������ݲ��Դ���\n");
    printf("\t3.�˳�\n");
    printf("\t���������ѡ��: ");
}

void TestTime(int c)
{
    int a[100], count = 100000, num = 100;
    if (c == 1)
    {
        printf("\t100*100k�����򻨷ѵ�ʱ��:\n");
    }
    else if (c == 2)
    {
        printf("\t������Ҫ���ԵĴ���:");
        scanf("%d", &count);
        printf("\t�Զ�����Դ������򻨷ѵ�ʱ��:\n");
    }
    else if (c == 3)
    {
        system("pause");
        exit(-1);
    }
    else
    {
        printf("\t�Ƿ�����\n");
        system("pause");
        exit(-1);
    }
    FILE *fp;
    int time = 0, start, end;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < num; j++)
        {
            a[j] = rand() % num;
        }
        start = GetTickCount();
        insertSort(a, num);
        end = GetTickCount();
        time += end - start;
    }
    printf("\t����������ʱ: %d ms\n", time);

    time = 0;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < num; j++)
        {
            a[j] = rand() % num;
        }
        start = GetTickCount();
        int tmp[100];
        MergeSort(a, 0, num - 1, tmp);
        end = GetTickCount();
        time += end - start;
    }
    printf("\t�鲢������ʱ: %d ms\n", time);

    time = 0;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < num; j++)
        {
            a[j] = rand() % num;
        }
        start = GetTickCount();
        QuickSort_Recursion(a, 0, num - 1);
        end = GetTickCount();
        time += end - start;
    }
    printf("\t��������(�ݹ��)��ʱ: %d ms\n", time);

    time = 0;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < num; j++)
        {
            a[j] = rand() % num;
        }
        start = GetTickCount();
        QuickSort(a, num);
        end = GetTickCount();
        time += end - start;
    }
    printf("\t��������(�ǵݹ��)��ʱ: %d ms\n", time);

    time = 0;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < num; j++)
        {
            a[j] = rand() % num;
        }
        start = GetTickCount();
        CountSort(a, num, GetMax(a, 100));
        end = GetTickCount();
        time += end - start;
    }
    printf("\t����������ʱ: %d ms\n", time);

    time = 0;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < num; j++)
        {
            a[j] = rand() % num;
        }
        start = GetTickCount();
        RadixCountSort(a, num);
        end = GetTickCount();
        time += end - start;
    }
    printf("\t��������������ʱ: %d ms\n", time);

    system("pause");
}

int main()
{
    /* ��ʼ������������� */
    srand((unsigned int)time(NULL));

    int choice;
    do
    {
        show();
        scanf("%d", &choice);
        TestTime(choice);
    } while (choice != 3);

    return 0;
}