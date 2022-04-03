#include "../Headers/sort.h"

void insertSort(int *a, int n)
{
    int i, j, tmp;
    for (i = 1; i < n; i++) // forѭ����һ���Ƚ���n-1��if�ж����
    {
        if (a[i] < a[i - 1]) // һ������������Ĺؼ��֣��ͽ��в���
        {
            tmp = a[i];
            j = i - 1;
            do // �����ƶ�һ��λ�ã��ڿռ��tmp
            {
                a[j + 1] = a[j];
                j--;
            } while (j >= 0 && a[j] > tmp);
            a[j + 1] = tmp;
        }
    }
}

void MergeArray(int *a, int begin, int mid, int end, int *temp)
{
    int i = begin;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= end)
    {
        temp[k++] = a[j++];
    }
    for (i = 0; i < k; i++)
    {
        a[begin + i] = temp[i];
    }
}
void MergeSort(int *a, int begin, int end, int *temp)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2;
        MergeSort(a, begin, mid, temp);
        MergeSort(a, mid + 1, end, temp);
        MergeArray(a, begin, mid, end, temp);
    }
}

void QuickSort_Recursion(int *a, int begin, int end)
{
    int i;
    if (begin < end)
    {
        i = Partition(a, begin, end);
        QuickSort_Recursion(a, begin, i - 1); // �Ե��ӱ���еݹ�����
        QuickSort_Recursion(a, i + 1, end);   // �Ը��ӱ���еݹ�����
    }
}

void QuickSort(int *a, int size)
{
    if (a == NULL || size <= 0)
    {
        return;
    }
    int *stack = (int *)malloc(sizeof(int) * size); // ����һ���ڴ���ջ��ʹ�ã�������ʱ���
    int left = 0, right = size - 1;
    int pointer = -1;

    stack[++pointer] = left;
    stack[++pointer] = right;

    float ex = 0;
    left = 0, right = 0;

    while (pointer != -1)
    {
        right = stack[pointer--];
        left = stack[pointer--];
        int i = left - 1;
        float pivot = a[right];
        for (int j = left; j < right; ++j)
        {
            if (a[j] < pivot)
            {
                i++;
                ex = a[i];
                a[i] = a[j];
                a[j] = ex;
            }
        }
        a[right] = a[i + 1];
        a[i + 1] = pivot;

        if (left < i)
        {
            stack[++pointer] = left;
            stack[++pointer] = i;
        }

        if (i + 2 < right)
        {
            stack[++pointer] = i + 2;
            stack[++pointer] = right;
        }
    }
    free(stack);
}
int Partition(int *a, int begin, int end)
{
    int i = begin, j = end, tmp = a[begin];

    while (i < j) // �����˽������м�ɨ��,ֱ��i=jΪֹ
    {
        while (i < j && a[j] >= tmp) // ��������ɨ��,��һ��С��tmp��a[j]
        {
            j--;
        }
        a[i] = a[j]; // �ҵ�������a[j]����a[i]

        while (i < j && a[i] <= tmp) // ��������ɨ��,��һ������tmp��a[i]
        {
            i++;
        }
        a[j] = a[i]; // �ҵ�������a[i]����a[j]
    }
    a[i] = tmp; // ����׼��ֵ�滻�� a[i]
    return i;
}

void CountSort(int *a, int size, int max)
{
    int t[max + 1];
    int i, j = 0;
    for (i = 0; i <= max; i++)
    {
        t[i] = 0;
    }
    for (i = 0; i < size; i++)
    {
        t[a[i]]++;
    }
    for (i = 0; i <= max; i++)
    {
        while ((t[i]--) > 0)
        {
            a[j++] = i;
        }
    }
}

void RadixCountSort(int *a, int size)
{
    int base;
    int max = GetMax(a, size);
    for (base = 1; max / base; base *= 10)
    {
        CountSort(a, size, max);
    }
}
int GetMax(int *a, int size)
{
    int i, max;
    max = a[0];
    for (i = 0; i < size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

void ColorSort(int *a, int size)
{
    int left = 0, right = size - 1, tmp;
    for (int i = 0; i < right; i++)
    {
        if (a[i] == 0)
        {
            tmp = a[i];
            a[i] = a[left];
            a[left] = tmp;
            left++;
        }
        else if (a[i] == 2)
        {
            tmp = a[i];
            a[i] = a[right];
            a[right] = tmp;
            right--;
            i--;
        }
    }
}

int FindKthMin(int *a, int begin, int end, int k)
{
    int p;
    if (k > 0 && k <= end)
    {
        p = Partition(a, begin, end);
        if (p - begin == k - 1)
        {
            return a[p];
        }
        else if (p - begin > k - 1)
        {
            return FindKthMin(a, begin, p - 1, k);
        }
        else
        {
            return FindKthMin(a, p + 1, end, k - (p - begin + 1));
        }
    }
    return GetMax(a, end + 1);
}