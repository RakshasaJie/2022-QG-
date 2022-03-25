#include "../head/LinkStack.h"
#include <stdio.h>
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s)
{
    if (!s)
    {
        printf("�����ڴ�ʧ��\n");
        return ERROR;
    }
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s)
{
    if (!s->top)
    {
        return SUCCESS;
    }
    else
    {
        return ERROR;
    }
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s, ElemType *e)
{
    if (isEmptyLStack(s))
    {
        printf("\nջ��Ϊ��\n");
        return ERROR;
    }
    *e = s->top->data;
    return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s)
{
    LinkStackPtr p;
    p = s->top;
    while (s->top)
    {
        s->top = s->top->next;
        free(p);
        p = s->top;
    }
    s->count = 0;
    return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s)
{
    clearLStack(s);
    free(s);
    return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s, int *length)
{
    *length = s->count;
    return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack *s, ElemType data)
{
    // Ҫ����data������Ҫ����ռ�
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    p->next = s->top;
    p->data = data;
    s->top = p;
    s->count++;
    return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s, ElemType *data)
{
    if (isEmptyLStack(s))
    {
        printf("\nջ��Ϊ��\n");
        return ERROR;
    }
    *data = s->top->data;
    LinkStackPtr p = s->top;
    s->top = s->top->next;
    free(p);
    s->count--;
    return SUCCESS;
}
