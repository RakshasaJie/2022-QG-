#include "../Headers/sort.h"
#include "sort.c"

void show()
{
    printf("\t******请选择生成测试程序******\n");
    printf("\t1.100*100k次数据测试\n");
    printf("\t2.自定义数据测试次数\n");
    printf("\t3.退出\n");
    printf("\t请输入你的选择: ");
}

void TestTime(int c)
{
    int a[100], count = 100000, num = 100;
    if (c == 1)
    {
        printf("\t100*100k次排序花费的时间:\n");
    }
    else if (c == 2)
    {
        printf("\t输入你要测试的次数:");
        scanf("%d", &count);
        printf("\t自定义测试次数排序花费的时间:\n");
    }
    else if (c == 3)
    {
        system("pause");
        exit(-1);
    }
    else
    {
        printf("\t非法输入\n");
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
    printf("\t插入排序用时: %d ms\n", time);

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
    printf("\t归并排序用时: %d ms\n", time);

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
    printf("\t快速排序(递归版)用时: %d ms\n", time);

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
    printf("\t快速排序(非递归版)用时: %d ms\n", time);

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
    printf("\t计数排序用时: %d ms\n", time);

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
    printf("\t基数计数排序用时: %d ms\n", time);

    system("pause");
}

int main()
{
    /* 初始化随机数发生器 */
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