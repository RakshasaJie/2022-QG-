#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h> // malloc

// 1.链表初始化——构造一个空表
Status InitList(LinkedList *L)
{
    *L = (LinkedList)malloc(sizeof(LNode));
    if (!(*L))
    {
        return ERROR;
    }

    // 将头节点的指针域置空
    (*L)->next = NULL;
    return SUCCESS;
}

// 2.在L中第i个元素前插入数据元素e
int ListInsert(LinkedList *L, int i, int e)
{
    LNode *p, *s;
    p = *L;
    int j = 1;
    while (p && j < i) // 定位
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
    {
        printf("\n发生错误，第 %d 个元素不存在，请重新操作！\n\n", i);
        return 0;
    }

    s = (LinkedList)malloc(sizeof(LNode)); // 生成新节点
    s->data = e;
    s->next = p->next;
    p->next = s;

    printf("\n操作完成\n\n");
    return 0;
}

// 3.输出链表
void DisplayList(LinkedList L)
{
    printf("\n");
    LNode *p = L->next;
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    if (p == NULL)
    {
        printf("NULL\n");
    }
    if (!L)
    {
        printf("\n还未生成链表\n\n");
    }
}

// 4.将链表反转
Status ReverseList(LinkedList *L)
{
    LinkedList pre = NULL, p = (*L)->next, next;
    while (p)
    {
        next = p->next;
        p->next = pre;
        pre = p;
        p = next;
    }
    (*L)->next = pre;
    return SUCCESS;
}

// 5.找到单链表中点
int GetMid(LinkedList L)
{
    LinkedList slow, fast;
    slow = fast = L->next;
    if (!fast)
    {
        printf("\n此链表为空\n");
        return 0;
    }
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("\n中间节点为：%d\n", slow->data);
    return 0;
}

// 6.判断是否成环
Status IsLoopList(LinkedList L)
{
    LinkedList slow, fast;
    slow = fast = L->next;
    if (!fast)
    {
        return ERROR;
    }
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        // 两指针相遇
        if (slow == fast)
        {
            return SUCCESS;
        }
    }
    return ERROR;
}

// 7.删除节点取值
int ListDelete(LinkedList *L, int i, int *e)
{
    LinkedList p, q;
    p = *L;
    int j = 1;
    while (p->next && j < i) // 遍历定位
    {
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i)
    {
        printf("\n发生错误，第 %d 个元素不存在，请重新操作！\n\n", i);
        return 0;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);

    printf("\n操作完成\n\n");
    return 0;
}

// 8.奇偶反转
LinkedList ReverseEvenList(LinkedList *L)
{
    if (!(*L)->next)
    {
        return *L;
    }
    LinkedList odd = (*L)->next;
    LinkedList evenHead = odd->next;
    LinkedList even = evenHead;
    while (even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return *L;
}

// 9.查询数据是否在表中并获取该数据的位置序号
int LocateNumElem(LinkedList L, int e)
{
    LNode *p;
    p = L;
    int j = 0;
    while (p && p->data != e)
    {
        p = p->next;
        j++;
    }
    if (p)
    {
        printf("\n该数据在表中的第 %d 个位置\n\n", j);
        return 0;
    }
    else
    {
        printf("\n该数据不在此表中\n\n");
        return 0;
    }
}

// 10.构造循环链表
LinkedList CycleList(LinkedList *L)
{
    if (!(*L)->next)
    {
        printf("\n此表为空\n");
        return *L;
    }
    LinkedList p, First;
    p = (*L)->next;
    First = p;
    while (p->next)
    {
        p = p->next;
    }
    p->next = First;
    printf("\n构造成功\n");
    return *L;
}

// 0.销毁删除链表
void DestroyList(LinkedList *L)
{
    LinkedList p, First;
    // 如果链表成环
    if (IsLoopList(*L))
    {
        First = (*L)->next;
        // 释放头结点，保留第一个节点
        p = *L;
        *L = First->next;
        free(p);

        while (*L != First)
        {
            p = *L;
            *L = (*L)->next;
            free(p);
        }
        free(First);
    }
    else
    {
        while (*L)
        {
            // 代替L的指向
            p = *L;
            // L指向它的指针域
            *L = (*L)->next;
            // 删除原先L的指向
            free(p);
        }
    }
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

int main(void)
{
    int option;
    LinkedList L = NULL;
    while (1)
    {
        printf("\n\n**************************************************************\n");
        printf("*  现在你可执行以下操作（请先创建新链表再进行其他操作）：    *\n");
        printf("*  1.创建新链表               * *             2.插入新节点   *\n");
        printf("*  3.输出链表                 * *             4.将链表反转   *\n");
        printf("*  5.找到单链表中点           * *             6.判断是否成环 *\n");
        printf("*  7.删除节点取值             * *             8.奇偶反转     *\n");
        printf("*                     9.查询数据是否在表中                   *\n");
        printf("*                     10.构造循环链表                        *\n");
        printf("*                     0.删除链表并退出系统                   *\n");
        printf("**************************************************************\n");
        printf("请选择菜单编号:");

        option = IfNum();

        switch (option)
        {
        case 1:
        {
            if (L)
            {
                printf("\n已存在一个单链表，执行此操作前请先销毁此链表\n");
            }
            else
            {
                if (InitList(&L))
                {
                    printf("\n创建完成，请进行下一步操作\n");
                }
                else
                {
                    printf("分配内存失败");
                }
            }

            break;
        }
        case 2:
        {
            if (!L)
            {
                printf("\n还未创建链表，请先扣 1 创建。\n");
            }
            else
            {
                if (IsLoopList(L))
                {
                    printf("\n此链表已经成环，无法执行以下操作！\n\n");
                    continue;
                }

                int i, e;
                printf("\n你将在第i个元素前插入数据元素e\n");
                printf("现在请你输入i：");
                i = IfNum();
                printf("\n现在请你输入e：");
                e = IfNum();
                ListInsert(&L, i, e);
            }

            break;
        }
        case 3:
        {
            if (!L)
            {
                printf("\n还未创建链表，请先扣 1 创建。\n");
            }
            else
            {
                if (IsLoopList(L))
                {
                    printf("\n此链表已经成环，无法执行以下操作！\n\n");
                    continue;
                }

                DisplayList(L);
                printf("\n打印完成，请进行下一步操作\n\n");
            }

            break;
        }
        case 4:
        {
            if (!L)
            {
                printf("\n还未创建链表，请先扣 1 创建。\n");
            }
            else
            {
                if (IsLoopList(L))
                {
                    printf("\n此链表已经成环，无法执行以下操作！\n\n");
                    continue;
                }

                ReverseList(&L);
                printf("\n反转完成，请进行下一步操作\n\n");
            }

            break;
        }
        case 5:
        {
            if (!L)
            {
                printf("\n还未创建链表，请先扣 1 创建。\n");
            }
            else
            {
                if (IsLoopList(L))
                {
                    printf("\n此链表已经成环，无法执行以下操作！\n\n");
                    continue;
                }

                GetMid(L);
                printf("\n请进行下一步操作\n\n");
            }

            break;
        }
        case 6:
        {
            if (!L)
            {
                printf("\n还未创建链表，请先扣 1 创建。\n");
            }
            else
            {
                int i;
                if (i = IsLoopList(L))
                {
                    printf("\n此链表成环\n");
                }
                else
                {
                    printf("\n此链表不成环\n");
                }
                printf("\n请进行下一步操作\n\n");
            }

            break;
        }
        case 7:
        {
            if (!L)
            {
                printf("\n还未创建链表，请先扣 1 创建。\n");
            }
            else
            {
                if (IsLoopList(L))
                {
                    printf("\n此链表已经成环，无法执行以下操作！\n\n");
                    continue;
                }

                int i, e;
                printf("\n你将删除第i个元素并将该元素返回为e\n");
                printf("现在请你输入i：");
                i = IfNum();
                ListDelete(&L, i, &e);
                printf("\ne = %d", e);
                printf("\n请进行下一步操作\n\n");
            }

            break;
        }
        case 8:
        {
            if (!L)
            {
                printf("\n还未创建链表，请先扣 1 创建。\n");
            }
            else
            {
                if (IsLoopList(L))
                {
                    printf("\n此链表已经成环，无法执行以下操作！\n\n");
                    continue;
                }

                ReverseEvenList(&L);
                printf("\n奇偶反转完成，请进行下一步操作\n\n");
            }

            break;
        }
        case 9:
        {
            if (!L)
            {
                printf("\n还未创建链表，请先扣 1 创建。\n");
            }
            else
            {
                if (IsLoopList(L))
                {
                    printf("\n此链表已经成环，无法执行以下操作！\n\n");
                    continue;
                }

                int e;
                printf("\n现在请输入你想查询的数据：");
                e = IfNum();
                LocateNumElem(L, e);
                printf("\n请进行下一步操作\n\n");
            }

            break;
        }
        case 10:
        {
            if (!L)
            {
                printf("\n还未创建链表，请先扣 1 创建。\n");
            }
            else
            {
                if (IsLoopList(L))
                {
                    printf("\n此链表已经成环，无法执行以下操作！\n\n");
                    continue;
                }

                CycleList(&L);
                printf("\n请进行下一步操作\n\n");
            }
            break;
        }
        case 0: // 删除链表并退出系统
        {
            DestroyList(&L);
            printf("\n您已退出程序，拜拜！");
            exit(0);

            break;
        }
        default:
            printf("\n没有这个选项，请重新选择。\n");
            break;
        }
    }
    return 0;
}