#include <stdio.h>
#include <stdlib.h> // malloc

// 链表结构初始化
typedef struct LNode
{
    int data;           // 数据域
    struct LNode *next; // 指针域
} LNode, *LinkList;

// 1.链表初始化——构造一个空表
LinkList InitList()
{
    LinkList L = (LinkList)malloc(sizeof(LNode));
    // 将头节点的指针域置空
    L->next = NULL;
    return L;
}

// 2.在L中第i个元素前插入数据元素e
int ListInsert(LinkList *L, int i, int e)
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
        printf("\n发生错误，第 %d 个元素不存在，请重新操作！\n\n",i);
        return 0;
    }

    s = (LinkList)malloc(sizeof(LNode)); // 生成新节点
    s->data = e;
    s->next = p->next;
    p->next = s;

    printf("\n操作完成\n\n");
    return 0;
}

// 3.输出链表
void DisplayList(LinkList L)
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
LinkList ReverseList(LinkList *L)
{
    LinkList pre = NULL, p = (*L)->next, next;
    while (p)
    {
        next = p->next;
        p->next = pre;
        pre = p;
        p = next;
    }
    LinkList h = (LinkList)malloc(sizeof(LNode));
    h->next = pre;
    return h;
}

// 5.找到单链表中点
int GetMid(LinkList L)
{
    LinkList slow, fast;
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
int IfLoop(LinkList L){
    LinkList slow, fast;
    slow = fast = L->next;
    if (!fast)
    {
        return 0;
    }
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;\

        // 两指针相遇
        if (slow==fast)
        {
            return 1;
        }
    }
    return 0;
}

// 7.删除节点取值
int ListDelete(LinkList *L, int i, int *e)
{
    LinkList p, q;
    p = *L;
    int j = 1;
    while (p->next && j < i) // 遍历定位
    {
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i)
    {
        printf("\n发生错误，第 %d 个元素不存在，请重新操作！\n\n",i);
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
LinkList OddEvenReverse(LinkList *L)
{
    if (!(*L)->next)
    {
        return L;
    }
    LinkList odd = (*L)->next;
    LinkList evenHead = odd->next;
    LinkList even = evenHead;
    while (even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return L;
}

// 9.查询数据是否在表中并获取该数据的位置序号
int LocateNumElem(LinkList L, int e)
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
LinkList CycleList(LinkList *L)
{
    if (!(*L)->next)
    {
        printf("\n此表为空\n");
        return L;
    }
    LinkList p, First;
    p = (*L)->next;
    First = p;
    while (!p->next)
    {
        p = p->next;
    }
    p->next = First;
    printf("\n构造成功\n");
    return L;
}

// 0.销毁删除链表
void DestroyList(LinkList *L)
{
    // 定义一个新指针
    LinkList p;
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
    LinkList L = NULL;
    while (1)
    {
        printf("\n\n**************************************************************\n");
        printf("*  现在你可执行以下操作（请先创建新链表再进行其他操作）：       *\n");
        printf("*  1.创建新链表               * *             2.插入新节点     *\n");
        printf("*  3.输出链表                 * *             4.将链表反转     *\n");
        printf("*  5.找到单链表中点           * *            6.判断是否成环    *\n");
        printf("*  7.删除节点取值             * *             8.奇偶反转       *\n");
        printf("*                     9.查询数据是否在表中                    *\n");
        printf("*                     10.构造循环链表                         *\n");
        printf("*                     0.删除链表并退出系统                    *\n");
        printf("**************************************************************\n");
        printf("请选择菜单编号:");

        option = IfNum();

        switch (option)
        {
        case 1:
        {
            L = InitList();
            printf("\n创建完成，请进行下一步操作\n\n");
        }
        break;
        case 2:
        {
            if (IfLoop(L))
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
        case 3:
        {
            if (IfLoop(L))
            {
                printf("\n此链表已经成环，无法执行以下操作！\n\n");
                continue;
            }

            DisplayList(L);
            printf("\n打印完成，请进行下一步操作\n\n");
        }
        break;
        case 4:
        {
            if (IfLoop(L))
            {
                printf("\n此链表已经成环，无法执行以下操作！\n\n");
                continue;
            }

            L = ReverseList(&L);
            printf("\n反转完成，请进行下一步操作\n\n");
        }
        break;
        case 5:
        {
            if (IfLoop(L))
            {
                printf("\n此链表已经成环，无法执行以下操作！\n\n");
                continue;
            }

            GetMid(L);
            printf("\n请进行下一步操作\n\n");
        }
        break;
        case 6:
        {
            int i;
            if (i = IfLoop(L))
            {
                printf("\n此链表成环\n");
            }else
            {
                printf("\n此链表不成环\n");
            }
            printf("\n请进行下一步操作\n\n");
        }
        break;
        case 7:
        {
            if (IfLoop(L))
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
        case 8:
        {
            if (IfLoop(L))
            {
                printf("\n此链表已经成环，无法执行以下操作！\n\n");
                continue;
            }
            
            OddEvenReverse(&L);
            printf("\n奇偶反转完成，请进行下一步操作\n\n");
        }
        break;
        case 9:
        {
            if (IfLoop(L))
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
        case 10:
        {
            if (IfLoop(L))
            {
                printf("\n此链表已经成环，无法执行以下操作！\n\n");
                continue;
            }

            CycleList(&L);
            printf("\n请进行下一步操作\n\n");
        }
        break;

        case 0: // 删除链表并退出系统
        {
            DestroyList(&L);
            printf("\n您已退出程序，拜拜！");
            return 0;
        }
        break;
        default:
            printf("\n没有这个选项，请重新选择。\n");
            break;
        }
    }
    return 0;
}