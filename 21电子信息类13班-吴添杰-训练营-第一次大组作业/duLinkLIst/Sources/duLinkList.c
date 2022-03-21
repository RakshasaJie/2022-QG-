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
// 1.��ͷ����ʼ��һ��������
Status InitList_DuL(DuLinkedList *L)
{
    // �����ڴ�
    *L = (DuLinkedList)malloc(sizeof(DuLNode));

    // �����ڴ�ʧ��
    if (!(*L))
    {
        return ERROR;
    }
    (*L)->prior = NULL;
    (*L)->next = NULL;
    return SUCCESS;
}

// 2.��������
void DestroyList_DuL(DuLinkedList *L)
{
    if (!(*L))
    {
        printf("\n��δ�����������ȿ� 1 ������\n");
        return;
    }
    else
    {
        DuLinkedList p;
        while (*L)
        {
            // ����L��ָ��
            p = *L;
            // Lָ������ָ����
            *L = (*L)->next;
            // ɾ��ԭ��L��ָ��
            free(p);
        }
        printf("\n���ٳɹ���\n");
    }
}

// 3.��p֮ǰ����q(ͷ�巨)
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
    // ������Ϊ��
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

// 4.��p֮�����q
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
    while (p->next)
    {
        p = p->next;
    }
    p->next = q;
    q->prior = p;
}

// 5.ɾ���ڵ� p ��ĵ�һ���ڵ㣬������ֵ���� e
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
    if (p->next == NULL)
    {
        printf("\n����һ���ձ�\n");
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

// �������
void push(ElemType e)
{
    printf("%d <-> ", e);
}

// 6.��ӡ�������ص㣺����ָ��
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
    int option;

    // ����һ��ָ��յ�ָ��
    DuLinkedList L; // = (DuLinkedList)malloc(sizeof(DuLNode));
    L = NULL;

    while (1)
    {
        printf("\n\n**************************************\n");
        printf("*     �������ִ�����²�����         *\n");
        printf("*     1.����������                   *\n");
        printf("*     2.��������                     *\n");
        printf("*     3.ͷ�巨                       *\n");
        printf("*     4.β�巨                       *\n");
        printf("*     5.ɾ����һ���ڵ㲢����ɾ������ *\n");
        printf("*     6.��ӡ����                     *\n");
        printf("*     7.�˳�����                     *\n");
        printf("**************************************\n");
        printf("��ѡ��˵����:");
        option = IfNum();
        switch (option)
        {
        case 1:
        {
            if (L)
            {
                printf("\n�Ѵ���һ��˫������ִ�д˲���ǰ�������ٴ�����\n");
            }
            else
            {
                if (InitList_DuL(&L))
                {
                    printf("\n������ɣ��������һ������\n");
                }
                else
                {
                    printf("�����ڴ�ʧ��");
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
                printf("\n��δ�����������ȿ� 1 ������\n");
            }
            else
            {
                DuLinkedList new;
                if (InitList_DuL(&new))
                {
                    printf("\n�½ڵ㴴���ɹ������������ݣ�");
                    new->data = IfNum();

                    if (InsertBeforeList_DuL(L, new))
                    {
                        printf("����ɹ�\n");
                    }
                    else
                    {
                        printf("����ʧ��\n");
                    }
                }
                else
                {
                    printf("\n����ʧ��\n");
                }
            }

            break;
        }

        case 4:
        {
            if (!L)
            {
                printf("\n��δ�����������ȿ� 1 ������\n");
            }
            else
            {
                DuLinkedList new;
                if (InitList_DuL(&new))
                {
                    printf("\n�½ڵ㴴���ɹ������������ݣ�");
                    new->data = IfNum();

                    if (InsertAfterList_DuL(L, new))
                    {
                        printf("����ɹ�\n");
                    }
                    else
                    {
                        printf("����ʧ��\n");
                    }
                }
                else
                {
                    printf("\n����ʧ��\n");
                }
            }

            break;
        }

        case 5:
        {
            if (!L)
            {
                printf("\n��δ�����������ȿ� 1 ������\n");
            }
            else
            {
                ElemType e;

                if (DeleteList_DuL(L, &e))
                {
                    printf("\n����ɾ���ɹ���ɾ��������Ϊ��%d\n",e);
                }
                else
                {
                    printf("\n����ɾ��ʧ�ܣ�\n");
                }
            }

            break;
        }

        case 6:
        {
            if (!L)
            {
                printf("\n��δ�����������ȿ� 1 ������\n");
            }
            else
            {
                TraverseList_DuL(L, push);
            }
            break;
        }

        case 7:
        {
            printf("\n�����˳����򣬰ݰݣ�");
            exit(0);
            break;
        }

        default:
            printf("\nû�����ѡ�������ѡ��\n");
            break;
        }
    }
    return 0;
}