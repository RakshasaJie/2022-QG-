#include <stdio.h>
#include <stdlib.h>
#include "../inc/binary_sort_tree.h"
#include "binary_sort_tree.c"

void show()
{
    system("cls");
    printf("\n\n\t********************************\n");
    printf("\t*          二叉排序树          *\n");
    printf("\t********************************\n");
    printf("\t******     1 初始化树     ******\n");
    printf("\t********************************\n");
    printf("\t******     2 插入数字     ******\n");
    printf("\t********************************\n");
    printf("\t******     3 删除数字     ******\n");
    printf("\t********************************\n");
    printf("\t******     4 查找数字     ******\n");
    printf("\t********************************\n");
    printf("\t******     5 递归先序遍历 ******\n");
    printf("\t********************************\n");
    printf("\t******     6 迭代先序遍历 ******\n");
    printf("\t********************************\n");
    printf("\t******     7 递归中序遍历 ******\n");
    printf("\t********************************\n");
    printf("\t******     8 迭代中序遍历 ******\n");
    printf("\t********************************\n");
    printf("\t******     9 递归后序遍历 ******\n");
    printf("\t********************************\n");
    printf("\t******    10 迭代后序遍历 ******\n");
    printf("\t********************************\n");
    printf("\t******    11 层序遍历     ******\n");
    printf("\t********************************\n");
    printf("\t******    12 退出         ******\n");
    printf("\t********************************\n");
    printf("\n\t请输入你的选择:");
}

// 判断输入是否为数字
int IfNum()
{
    int guess, ret;
    guess = scanf("%d", &ret);
    while (!guess)
    {
        while (getchar() != '\n')
            ; // 清除缓冲区
        printf("\n请输入数字\n");
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
            printf("请输入一个整数:");
            value = IfNum();
            printf("\n\t");

            if (BST_insert(bt, value))
            {
                printf("插入成功！\n\t");
            }
            else
            {
                printf("插入失败！\n\t");
            }
            system("pause");
            break;

        case 3:
            printf("请输入一个整数:");
            value = IfNum();
            printf("\n\t");
            BST_delete(bt, value);
            system("pause");
            break;

        case 4:
            printf("请输入一个整数:");
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
