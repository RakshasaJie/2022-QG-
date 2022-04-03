#include "../Headers/sort.h"
#include "sort.c"

void show_1()
{
    printf("\t******��ѡ���������******\n");
    printf("\t1.10000 ��\n");
    printf("\t2.50000 ��\n");
    printf("\t3.200000 ��\n");
    printf("\t�����������˳�����!!!\n");
    printf("\t���������ѡ��: ");
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
        printf("\t�Ƿ����룬�Զ��˳�\n\t");
        system("pause");
        exit(-1);
    }
}

void show_2()
{
    printf("\t******��ѡ������ʽ******\n");
    printf("\t1.��������\n");
    printf("\t2.�鲢����\n");
    printf("\t3.�������򣨵ݹ�棩\n");
    printf("\t4.�������򣨷ǵݹ�棩\n");
    printf("\t5.��������\n");
    printf("\t6.��������\n");
    printf("\t�����������˳�����!!!\n");
    printf("\t���������ѡ��: ");
}

void choiceWay(int c, int *a, long size)
{
    clock_t start, time;
    if (c == 1)
    {
        start = clock();
        insertSort(a, size);
        time = clock() - start;
        printf("\tʹ�ò�����������  %d��������Ҫ��ʱ��: %d ms\n", size, time);
    }
    else if (c == 2)
    {
        int temp[size];
        start = clock();
        MergeSort(a, 0, size - 1, temp);
        time = clock() - start;
        printf("\tʹ�ù鲢��������  %d��������Ҫ��ʱ��: %d ms\n", size, time);
    }
    else if (c == 3)
    {
        start = clock();
        QuickSort_Recursion(a, 0, size - 1);
        time = clock() - start;
        printf("\tʹ�ÿ���(�ݹ�)���� %d ��������Ҫ��ʱ��: %d ms\n", size, time);
    }
    else if (c == 4)
    {
        start = clock();
        QuickSort(a, size);
        time = clock() - start;
        printf("\tʹ�ÿ���(�ǵݹ�)���� %d ��������Ҫ��ʱ��: %d ms\n", size, time);
    }
    else if (c == 5)
    {
        start = clock();
        RadixCountSort(a, size);
        time = clock() - start;
        printf("\tʹ�û�����������  %d ��������Ҫ��ʱ��: %d ms\n", size, time);
    }
    else if (c == 6)
    {
        start = clock();
        CountSort(a, size, 100);
        time = clock() - start;
        printf("\tʹ�ü�����������  %d ��������Ҫ��ʱ��: %d ms\n", size, time);
    }
    else
    {
        printf("\t�Ƿ����룬�Զ��˳�\n\t");
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
        printf("\t�������С�generate.c���ļ�\n");
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
    printf("\n\t������ڡ�testData.txt���ļ��в鿴\n\t");
    system("pause");

    return 0;
}