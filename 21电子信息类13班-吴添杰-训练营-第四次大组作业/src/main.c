#include <stdio.h>
#include <stdlib.h>
#include "../inc/binary_sort_tree.h"
#include "binary_sort_tree.c"

void show()
{
    system("cls");
    printf("\n\n\t********************************\n");
    printf("\t*          ����������          *\n");
    printf("\t********************************\n");
    printf("\t******     1 ��ʼ����     ******\n");
    printf("\t********************************\n");
    printf("\t******     2 ��������     ******\n");
    printf("\t********************************\n");
    printf("\t******     3 ɾ������     ******\n");
    printf("\t********************************\n");
    printf("\t******     4 ��������     ******\n");
    printf("\t********************************\n");
    printf("\t******     5 �ݹ�������� ******\n");
    printf("\t********************************\n");
    printf("\t******     6 ����������� ******\n");
    printf("\t********************************\n");
    printf("\t******     7 �ݹ�������� ******\n");
    printf("\t********************************\n");
    printf("\t******     8 ����������� ******\n");
    printf("\t********************************\n");
    printf("\t******     9 �ݹ������� ******\n");
    printf("\t********************************\n");
    printf("\t******    10 ����������� ******\n");
    printf("\t********************************\n");
    printf("\t******    11 �������     ******\n");
    printf("\t********************************\n");
    printf("\t******    12 �˳�         ******\n");
    printf("\t********************************\n");
    printf("\n\t���������ѡ��:");
}

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

int main()
{
    BinarySortTreePtr bt = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    if (bt == NULL)
    {
        printf("malloc failed\n\t");
        return failed;
    }
    bt->root = NULL;
    int option = 0, value = 0;

    do
    {
        show();

        option = IfNum();
        printf("\n\t");

        switch (option)
        {
        case 1:
            BST_init(bt);
            system("pause");
            break;

        case 2:
            printf("������һ������:");
            value = IfNum();
            printf("\n\t");

            if (BST_insert(bt, value))
            {
                printf("����ɹ���\n\t");
            }
            else
            {
                printf("����ʧ�ܣ�\n\t");
            }
            system("pause");
            break;

        case 3:
            printf("������һ������:");
            value = IfNum();
            printf("\n\t");
            BST_delete(bt, value);
            system("pause");
            break;

        case 4:
            printf("������һ������:");
            value = IfNum();
            printf("\n\t");
            BST_search(bt, value);
            system("pause");
            break;

        case 5:
            BST_preorderR(bt, visit);
            system("pause");
            break;

        case 6:
            BST_preorderI(bt, visit);
            system("pause");
            break;

        case 7:
            BST_inorderR(bt, visit);
            system("pause");
            break;

        case 8:
            BST_inorderI(bt, visit);
            system("pause");
            break;

        case 9:
            BST_postorderR(bt, visit);
            system("pause");
            break;

        case 10:
            BST_postorderI(bt, visit);
            system("pause");
            break;

        case 11:
            BST_levelOrder(bt, visit);
            system("pause");
            break;

        default:
            break;
        }

    } while (option != 12);

    return 0;
}
