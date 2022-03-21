// #include "duLinkList.h"
#include <stdio.h>
#include <stdlib.h>
// define element type
typedef int ElemType;

// define struct of linked list
typedef struct DuLNode {
	ElemType data;
  	struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;

// define status
typedef enum Status {
	ERROR,
	SUCCESS,
} Status;
// 1.用头结点初始化一个空链表
Status InitList_DuL(DuLinkedList *L)
{
    // 分配内存
    *L = (DuLinkedList)malloc(sizeof(DuLNode));

    // 分配内存失败
    if (!(*L))
    {
        return ERROR;
    }
    (*L)->prior = NULL;
    (*L)->next = NULL;
    return SUCCESS;
}

// 2.销毁链表
void DestroyList_DuL(DuLinkedList *L)
{
    if (!(*L))
    {
        printf("\n还未创建链表，请先扣 1 创建。\n");
        return;
    }
    else
    {
        DuLinkedList p;
        while (*L)
        {
            // 代替L的指向
            p = *L;
            // L指向它的指针域
            *L = (*L)->next;
            // 删除原先L的指向
            free(p);
        }
        printf("\n销毁成功！\n");
    }
}

// 3.在p之前插入q(头插法)
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
    // 当链表为空
    if (!p->next)
    {
        p->next = q;
        q->prior = p;
    }
    else
    {
        DuLinkedList temp;
        temp = p->next;
        p->next = q;
        q->next = temp;
        temp->prior = q;
        q->prior = p;
    }
    return SUCCESS;
}

// 4.在p之后插入q
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
    while (p->next)
    {
        p = p->next;
    }
    p->next = q;
    q->prior = p;
}

// 5.删除节点 p 后的第一个节点，并将其值赋给 e
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
    if (p->next == NULL)
    {
        printf("\n这是一个空表\n");
        return ERROR;
    }
    else
    {
        *e=p->next->data;
        p=p->next;
        p->prior->next=p->next;
        p->next->prior=p->prior;
        free(p);
        return SUCCESS;
    }
}

// 输出函数
void push(ElemType e)
{
    printf("%d <-> ", e);
}

// 6.打印链表——重点：函数指针
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
    printf("\n");
    DuLinkedList p = L->next;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("NULL");
    printf("\n");
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
    int option;

    // 创建一个指向空的指针
    DuLinkedList L; // = (DuLinkedList)malloc(sizeof(DuLNode));
    L = NULL;

    while (1)
    {
        printf("\n\n**************************************\n");
        printf("*     现在你可执行以下操作：         *\n");
        printf("*     1.创建新链表                   *\n");
        printf("*     2.销毁链表                     *\n");
        printf("*     3.头插法                       *\n");
        printf("*     4.尾插法                       *\n");
        printf("*     5.删除第一个节点并返回删除数据 *\n");
        printf("*     6.打印链表                     *\n");
        printf("*     7.退出程序                     *\n");
        printf("**************************************\n");
        printf("请选择菜单编号:");
        option = IfNum();
        switch (option)
        {
        case 1:
        {
            if (L)
            {
                printf("\n已存在一个双向链表，执行此操作前请先销毁此链表\n");
            }
            else
            {
                if (InitList_DuL(&L))
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
            DestroyList_DuL(&L);
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
                DuLinkedList new;
                if (InitList_DuL(&new))
                {
                    printf("\n新节点创建成功，请输入数据：");
                    new->data = IfNum();

                    if (InsertBeforeList_DuL(L, new))
                    {
                        printf("插入成功\n");
                    }
                    else
                    {
                        printf("插入失败\n");
                    }
                }
                else
                {
                    printf("\n插入失败\n");
                }
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
                DuLinkedList new;
                if (InitList_DuL(&new))
                {
                    printf("\n新节点创建成功，请输入数据：");
                    new->data = IfNum();

                    if (InsertAfterList_DuL(L, new))
                    {
                        printf("插入成功\n");
                    }
                    else
                    {
                        printf("插入失败\n");
                    }
                }
                else
                {
                    printf("\n插入失败\n");
                }
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
                ElemType e;

                if (DeleteList_DuL(L, &e))
                {
                    printf("\n数据删除成功，删除的数据为：%d\n",e);
                }
                else
                {
                    printf("\n数据删除失败！\n");
                }
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
                TraverseList_DuL(L, push);
            }
            break;
        }

        case 7:
        {
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