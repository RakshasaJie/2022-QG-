#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h> // malloc

// 1.�����ʼ����������һ���ձ�
Status InitList(LinkedList *L)
{
    *L = (LinkedList)malloc(sizeof(LNode));
    if (!(*L))
    {
        return ERROR;
    }

    // ��ͷ�ڵ��ָ�����ÿ�
    (*L)->next = NULL;
    return SUCCESS;
}

// 2.��L�е�i��Ԫ��ǰ��������Ԫ��e
int ListInsert(LinkedList *L, int i, int e)
{
    LNode *p, *s;
    p = *L;
    int j = 1;
    while (p && j < i) // ��λ
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
    {
        printf("\n�������󣬵� %d ��Ԫ�ز����ڣ������²�����\n\n", i);
        return 0;
    }

    s = (LinkedList)malloc(sizeof(LNode)); // �����½ڵ�
    s->data = e;
    s->next = p->next;
    p->next = s;

    printf("\n�������\n\n");
    return 0;
}

// 3.�������
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
        printf("\n��δ��������\n\n");
    }
}

// 4.������ת
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

// 5.�ҵ��������е�
int GetMid(LinkedList L)
{
    LinkedList slow, fast;
    slow = fast = L->next;
    if (!fast)
    {
        printf("\n������Ϊ��\n");
        return 0;
    }
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("\n�м�ڵ�Ϊ��%d\n", slow->data);
    return 0;
}

// 6.�ж��Ƿ�ɻ�
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

        // ��ָ������
        if (slow == fast)
        {
            return SUCCESS;
        }
    }
    return ERROR;
}

// 7.ɾ���ڵ�ȡֵ
int ListDelete(LinkedList *L, int i, int *e)
{
    LinkedList p, q;
    p = *L;
    int j = 1;
    while (p->next && j < i) // ������λ
    {
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i)
    {
        printf("\n�������󣬵� %d ��Ԫ�ز����ڣ������²�����\n\n", i);
        return 0;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);

    printf("\n�������\n\n");
    return 0;
}

// 8.��ż��ת
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

// 9.��ѯ�����Ƿ��ڱ��в���ȡ�����ݵ�λ�����
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
        printf("\n�������ڱ��еĵ� %d ��λ��\n\n", j);
        return 0;
    }
    else
    {
        printf("\n�����ݲ��ڴ˱���\n\n");
        return 0;
    }
}

// 10.����ѭ������
LinkedList CycleList(LinkedList *L)
{
    if (!(*L)->next)
    {
        printf("\n�˱�Ϊ��\n");
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
    printf("\n����ɹ�\n");
    return *L;
}

// 0.����ɾ������
void DestroyList(LinkedList *L)
{
    LinkedList p, First;
    // �������ɻ�
    if (IsLoopList(*L))
    {
        First = (*L)->next;
        // �ͷ�ͷ��㣬������һ���ڵ�
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
            // ����L��ָ��
            p = *L;
            // Lָ������ָ����
            *L = (*L)->next;
            // ɾ��ԭ��L��ָ��
            free(p);
        }
    }
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

int main(void)
{
    int option;
    LinkedList L = NULL;
    while (1)
    {
        printf("\n\n**************************************************************\n");
        printf("*  �������ִ�����²��������ȴ����������ٽ���������������    *\n");
        printf("*  1.����������               * *             2.�����½ڵ�   *\n");
        printf("*  3.�������                 * *             4.������ת   *\n");
        printf("*  5.�ҵ��������е�           * *             6.�ж��Ƿ�ɻ� *\n");
        printf("*  7.ɾ���ڵ�ȡֵ             * *             8.��ż��ת     *\n");
        printf("*                     9.��ѯ�����Ƿ��ڱ���                   *\n");
        printf("*                     10.����ѭ������                        *\n");
        printf("*                     0.ɾ�������˳�ϵͳ                   *\n");
        printf("**************************************************************\n");
        printf("��ѡ��˵����:");

        option = IfNum();

        switch (option)
        {
        case 1:
        {
            if (L)
            {
                printf("\n�Ѵ���һ��������ִ�д˲���ǰ�������ٴ�����\n");
            }
            else
            {
                if (InitList(&L))
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
            if (!L)
            {
                printf("\n��δ�����������ȿ� 1 ������\n");
            }
            else
            {
                if (IsLoopList(L))
                {
                    printf("\n�������Ѿ��ɻ����޷�ִ�����²�����\n\n");
                    continue;
                }

                int i, e;
                printf("\n�㽫�ڵ�i��Ԫ��ǰ��������Ԫ��e\n");
                printf("������������i��");
                i = IfNum();
                printf("\n������������e��");
                e = IfNum();
                ListInsert(&L, i, e);
            }

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
                if (IsLoopList(L))
                {
                    printf("\n�������Ѿ��ɻ����޷�ִ�����²�����\n\n");
                    continue;
                }

                DisplayList(L);
                printf("\n��ӡ��ɣ��������һ������\n\n");
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
                if (IsLoopList(L))
                {
                    printf("\n�������Ѿ��ɻ����޷�ִ�����²�����\n\n");
                    continue;
                }

                ReverseList(&L);
                printf("\n��ת��ɣ��������һ������\n\n");
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
                if (IsLoopList(L))
                {
                    printf("\n�������Ѿ��ɻ����޷�ִ�����²�����\n\n");
                    continue;
                }

                GetMid(L);
                printf("\n�������һ������\n\n");
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
                int i;
                if (i = IsLoopList(L))
                {
                    printf("\n������ɻ�\n");
                }
                else
                {
                    printf("\n�������ɻ�\n");
                }
                printf("\n�������һ������\n\n");
            }

            break;
        }
        case 7:
        {
            if (!L)
            {
                printf("\n��δ�����������ȿ� 1 ������\n");
            }
            else
            {
                if (IsLoopList(L))
                {
                    printf("\n�������Ѿ��ɻ����޷�ִ�����²�����\n\n");
                    continue;
                }

                int i, e;
                printf("\n�㽫ɾ����i��Ԫ�ز�����Ԫ�ط���Ϊe\n");
                printf("������������i��");
                i = IfNum();
                ListDelete(&L, i, &e);
                printf("\ne = %d", e);
                printf("\n�������һ������\n\n");
            }

            break;
        }
        case 8:
        {
            if (!L)
            {
                printf("\n��δ�����������ȿ� 1 ������\n");
            }
            else
            {
                if (IsLoopList(L))
                {
                    printf("\n�������Ѿ��ɻ����޷�ִ�����²�����\n\n");
                    continue;
                }

                ReverseEvenList(&L);
                printf("\n��ż��ת��ɣ��������һ������\n\n");
            }

            break;
        }
        case 9:
        {
            if (!L)
            {
                printf("\n��δ�����������ȿ� 1 ������\n");
            }
            else
            {
                if (IsLoopList(L))
                {
                    printf("\n�������Ѿ��ɻ����޷�ִ�����²�����\n\n");
                    continue;
                }

                int e;
                printf("\n���������������ѯ�����ݣ�");
                e = IfNum();
                LocateNumElem(L, e);
                printf("\n�������һ������\n\n");
            }

            break;
        }
        case 10:
        {
            if (!L)
            {
                printf("\n��δ�����������ȿ� 1 ������\n");
            }
            else
            {
                if (IsLoopList(L))
                {
                    printf("\n�������Ѿ��ɻ����޷�ִ�����²�����\n\n");
                    continue;
                }

                CycleList(&L);
                printf("\n�������һ������\n\n");
            }
            break;
        }
        case 0: // ɾ�������˳�ϵͳ
        {
            DestroyList(&L);
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