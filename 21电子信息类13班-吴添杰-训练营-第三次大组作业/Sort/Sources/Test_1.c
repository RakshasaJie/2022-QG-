#include "../Headers/sort.h"
#include "sort.c"

#define Data_1 10000
#define Data_2 50000
#define Data_3 200000

int main()
{
    system("cls");
    /* ��ʼ������������� */
    srand((unsigned int)time(NULL));

    int i, j, size;
    clock_t start, time_1;
    
    printf("\n\t************��ͬ���������������㷨����ʱ************\n");
    for (i = 0; i < 3; i++)
    {

        if (i == 0)
        {
            size = Data_1;
            printf("\n\t1.������Ϊ 10000 �����: \n\n");
        }
        else if (i == 1)
        {
            size = Data_2;
            printf("\n\t2.������Ϊ 50000 �����: \n\n");
        }
        else if (i == 2)
        {
            size = Data_3;
            printf("\n\t3.������Ϊ 200000 �����: \n\n");
        }
        int *a = (int *)malloc(sizeof(int) * size);
        int *temp = (int *)malloc(sizeof(int) * size);

        //��������
        for (j = 0; j < size; j++)
        {
            a[j] = rand() % 100;
        }
        start = clock();
        insertSort(a, size);
        time_1 = clock() - start;
        printf("\tʹ�ò�����������  %d��������Ҫ��ʱ��: %d ms\n", size, time_1);

        //�鲢����
        for (j = 0; j < size; j++)
        {
            a[j] = rand() % 100;
        }
        start = clock();
        MergeSort(a, 0, size - 1, temp);
        time_1 = clock() - start;
        printf("\tʹ�ù鲢��������  %d��������Ҫ��ʱ��: %d ms\n", size, time_1);

        //���ŵݹ�
        for (j = 0; j < size; j++)
            a[j] = rand() % 100;
        start = clock();
        QuickSort_Recursion(a, 0, size - 1);
        time_1 = clock() - start;
        printf("\tʹ�ÿ���(�ݹ�)���� %d ��������Ҫ��ʱ��: %d ms\n", size, time_1);

        //���ŷǵݹ�
        for (j = 0; j < size; j++)
        {
            a[j] = rand() % 100;
        }
        start = clock();
        QuickSort(a, size);
        time_1 = clock() - start;
        printf("\tʹ�ÿ���(�ǵݹ�)���� %d ��������Ҫ��ʱ��: %d ms\n", size, time_1);

        //������������
        for (j = 0; j < size; j++)
        {
            a[j] = rand() % 100;
        }
        start = clock();
        RadixCountSort(a, size);
        time_1 = clock() - start;
        printf("\tʹ�û�����������  %d ��������Ҫ��ʱ��: %d ms\n", size, time_1);

        //��������
        for (j = 0; j < size; j++)
        {
            a[j] = rand() % 100;
        }
        start = clock();
        CountSort(a, size, 100);
        time_1 = clock() - start;
        printf("\tʹ�ü�����������  %d ��������Ҫ��ʱ��: %d ms\n", size, time_1);

        free(a);
        free(temp);
    }
    printf("\t****************************************************\n");

    system("pause");
    return 0;
}