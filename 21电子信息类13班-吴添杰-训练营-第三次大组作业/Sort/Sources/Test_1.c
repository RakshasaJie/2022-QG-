#include "../Headers/sort.h"
#include "sort.c"

#define Data_1 10000
#define Data_2 50000
#define Data_3 200000

int main()
{
    system("cls");
    /* 初始化随机数发生器 */
    srand((unsigned int)time(NULL));

    int i, j, size;
    clock_t start, time_1;
    
    printf("\n\t************不同数据量各种排序算法的用时************\n");
    for (i = 0; i < 3; i++)
    {

        if (i == 0)
        {
            size = Data_1;
            printf("\n\t1.数据量为 10000 的情况: \n\n");
        }
        else if (i == 1)
        {
            size = Data_2;
            printf("\n\t2.数据量为 50000 的情况: \n\n");
        }
        else if (i == 2)
        {
            size = Data_3;
            printf("\n\t3.数据量为 200000 的情况: \n\n");
        }
        int *a = (int *)malloc(sizeof(int) * size);
        int *temp = (int *)malloc(sizeof(int) * size);

        //插入排序
        for (j = 0; j < size; j++)
        {
            a[j] = rand() % 100;
        }
        start = clock();
        insertSort(a, size);
        time_1 = clock() - start;
        printf("\t使用插入排序排序  %d个数字需要的时间: %d ms\n", size, time_1);

        //归并排序
        for (j = 0; j < size; j++)
        {
            a[j] = rand() % 100;
        }
        start = clock();
        MergeSort(a, 0, size - 1, temp);
        time_1 = clock() - start;
        printf("\t使用归并排序排序  %d个数字需要的时间: %d ms\n", size, time_1);

        //快排递归
        for (j = 0; j < size; j++)
            a[j] = rand() % 100;
        start = clock();
        QuickSort_Recursion(a, 0, size - 1);
        time_1 = clock() - start;
        printf("\t使用快排(递归)排序 %d 个数字需要的时间: %d ms\n", size, time_1);

        //快排非递归
        for (j = 0; j < size; j++)
        {
            a[j] = rand() % 100;
        }
        start = clock();
        QuickSort(a, size);
        time_1 = clock() - start;
        printf("\t使用快排(非递归)排序 %d 个数字需要的时间: %d ms\n", size, time_1);

        //基数计数排序
        for (j = 0; j < size; j++)
        {
            a[j] = rand() % 100;
        }
        start = clock();
        RadixCountSort(a, size);
        time_1 = clock() - start;
        printf("\t使用基数排序排序  %d 个数字需要的时间: %d ms\n", size, time_1);

        //计数排序
        for (j = 0; j < size; j++)
        {
            a[j] = rand() % 100;
        }
        start = clock();
        CountSort(a, size, 100);
        time_1 = clock() - start;
        printf("\t使用计数排序排序  %d 个数字需要的时间: %d ms\n", size, time_1);

        free(a);
        free(temp);
    }
    printf("\t****************************************************\n");

    system("pause");
    return 0;
}