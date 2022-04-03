#include "../Headers/sort.h"
#include "sort.c"

void show_1()
{
    printf("\t******请选择测试数量******\n");
    printf("\t1.10000 级\n");
    printf("\t2.50000 级\n");
    printf("\t3.200000 级\n");
    printf("\t输入其他将退出程序!!!\n");
    printf("\t请输入你的选择: ");
}

void choiceData(int c, long *num)
{
    if (c == 1)
    {
        *num = 10000;
    }
    else if (c == 2)
    {
        *num = 50000;
    }
    else if (c == 3)
    {
        *num = 200000;
    }
    else
    {
        printf("\t非法输入，自动退出\n\t");
        system("pause");
        exit(-1);
    }
}

void show_2()
{
    printf("\t******请选择排序方式******\n");
    printf("\t1.插入排序\n");
    printf("\t2.归并排序\n");
    printf("\t3.快速排序（递归版）\n");
    printf("\t4.快速排序（非递归版）\n");
    printf("\t5.计数排序\n");
    printf("\t6.基数排序\n");
    printf("\t输入其他将退出程序!!!\n");
    printf("\t请输入你的选择: ");
}

void choiceWay(int c, int *a, long size)
{
    clock_t start, time;
    if (c == 1)
    {
        start = clock();
        insertSort(a, size);
        time = clock() - start;
        printf("\t使用插入排序排序  %d个数字需要的时间: %d ms\n", size, time);
    }
    else if (c == 2)
    {
        int temp[size];
        start = clock();
        MergeSort(a, 0, size - 1, temp);
        time = clock() - start;
        printf("\t使用归并排序排序  %d个数字需要的时间: %d ms\n", size, time);
    }
    else if (c == 3)
    {
        start = clock();
        QuickSort_Recursion(a, 0, size - 1);
        time = clock() - start;
        printf("\t使用快排(递归)排序 %d 个数字需要的时间: %d ms\n", size, time);
    }
    else if (c == 4)
    {
        start = clock();
        QuickSort(a, size);
        time = clock() - start;
        printf("\t使用快排(非递归)排序 %d 个数字需要的时间: %d ms\n", size, time);
    }
    else if (c == 5)
    {
        start = clock();
        RadixCountSort(a, size);
        time = clock() - start;
        printf("\t使用基数排序排序  %d 个数字需要的时间: %d ms\n", size, time);
    }
    else if (c == 6)
    {
        start = clock();
        CountSort(a, size, 100);
        time = clock() - start;
        printf("\t使用计数排序排序  %d 个数字需要的时间: %d ms\n", size, time);
    }
    else
    {
        printf("\t非法输入，自动退出\n\t");
        system("pause");
        exit(-1);
    }
}

int main()
{
    system("cls");
    FILE *fp;
    fp = fopen("testData.txt", "r");
    if (fp == NULL)
    {
        printf("\t请先运行“generate.c”文件\n");
        system("pause");
        exit(-1);
    }

    int c;
    long num;
    show_1();
    scanf("%d", &c);
    choiceData(c, &num);
    int a[num];
    for (int i = 0; i < num; i++)
    {
        fscanf(fp, "%d ", &a[i]);
    }
    fclose(fp);

    show_2();
    scanf("%d", &c);
    choiceWay(c, a, num);

    fp = fopen("testData.txt", "w");
    for (int i = 0; i < num; i++)
    {
        fprintf(fp, "%d ", a[i]);
    }
    fclose(fp);
    printf("\n\t你可以在“testData.txt”文件中查看\n\t");
    system("pause");

    return 0;
}