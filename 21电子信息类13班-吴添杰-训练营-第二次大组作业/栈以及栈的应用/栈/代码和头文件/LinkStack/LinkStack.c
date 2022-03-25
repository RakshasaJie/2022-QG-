#include "../head/LinkStack.h"
#include <stdio.h>
//链栈

//初始化栈
Status initLStack(LinkStack *s)
{
    if (!s)
    {
        printf("分配内存失败\n");
        return ERROR;
    }
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

//判断栈是否为空
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

//得到栈顶元素
Status getTopLStack(LinkStack *s, ElemType *e)
{
    if (isEmptyLStack(s))
    {
        printf("\n栈内为空\n");
        return ERROR;
    }
    *e = s->top->data;
    return SUCCESS;
}

//清空栈
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

//销毁栈
Status destroyLStack(LinkStack *s)
{
    clearLStack(s);
    free(s);
    return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack *s, int *length)
{
    *length = s->count;
    return SUCCESS;
}

//入栈
Status pushLStack(LinkStack *s, ElemType data)
{
    // 要存入data，所以要分配空间
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    p->next = s->top;
    p->data = data;
    s->top = p;
    s->count++;
    return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s, ElemType *data)
{
    if (isEmptyLStack(s))
    {
        printf("\n栈内为空\n");
        return ERROR;
    }
    *data = s->top->data;
    LinkStackPtr p = s->top;
    s->top = s->top->next;
    free(p);
    s->count--;
    return SUCCESS;
}
