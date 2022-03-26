#include "../head/LQueue.h"

// *************************************************************************
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

// 选择入队数据类型
void ChooseType(LQueue *Q)
{
    char cho;
    int flag = 0;

    printf("请选择队列的数据类型：\n[1]  int\n[2]  char\n[3]  double\n");
    printf("或者按 [4] 退出程序\n");
    while (flag == 0)
    {
        cho = IfNum();
        switch (cho)
        {
        case 1:
            Q->data_size = sizeof(int);
            flag = 1;
            break;
        case 2:
            Q->data_size = sizeof(char);
            flag = 1;
            break;
        case 3:
            Q->data_size = sizeof(double);
            flag = 1;
            break;
        case 4:
            printf("\n您已退出程序，拜拜！");
            exit(0);
            break;
        default:
            printf("请输入正确的指令！\n");
            break;
        }
    }
}
// *********************************************************************

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param     :    Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
    Node *p = NULL;
    p = (Node *)malloc(sizeof(Node)); // 申请头结点内存
    if (!p)
    {
        printf("初始化失败\n");
    }
    else
    {
        p->next = NULL;
        Q->front = Q->rear = p;
        Q->length = 0;
        printf("初始化完成\n");
    }
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param      :   Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
    if (IsEmptyLQueue(Q))
    {
        return;
    }
    else
    {
        ClearLQueue(Q);
    }
    free(Q->front);
    free(Q->rear);
    return;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param     :    Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
    if (Q->front == Q->rear)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param  :       Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
    if (IsEmptyLQueue(Q))
    {
        return FALSE;
    }
    memcpy(e, Q->front->next->data, Q->data_size);

    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param    :     Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
    return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param     :    Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (!p)
    {
        printf("申请内存失败！\n");
        return FALSE;
    }
    else
    {
        p->data = (void *)malloc(Q->data_size); // 分配内存
        memcpy(p->data, data, Q->data_size);
        p->next = NULL;
        Q->rear->next = p;
        Q->rear = Q->rear->next;
        Q->length++;
        return TRUE;
    }
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param     :    Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
    if (IsEmptyLQueue(Q))
    {
        return FALSE;
    }
    Node *p = (Node *)malloc(sizeof(Node));
    p = Q->front->next;
    Q->front->next = p->next;
    if (!Q->front->next)
    {
        Q->rear = Q->front;
    }
    free(p);
    Q->length--;
    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param     :    Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
    if (IsEmptyLQueue(Q))
    {
        return;
    }
    Node *p, *q;
    Q->rear = Q->front;
    // for (p = Q->front->next; p; p = p->next)
    // {
    //     q = p;
    //     free(q);
    //     Q->length--;
    // }
    p = Q->front->next; 
	while (NULL != p) {
		q = p;
		p = p->next;
		free(q);
	}
    free(p);
    return;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param     :    Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q, size_t size))
{
    if (IsEmptyLQueue(Q))
    {
        return FALSE;
    }
    Node *p;
    for (p = Q->front->next; p; p = p->next)
    {
        foo(p->data, Q->data_size);
    }
    return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param     :    q 指针q

 *  @notice      : None
 */
void LPrint(void *q, size_t size)
{
    if (size == sizeof(int))
    {
        printf("%d ", *(int *)q);
    }
    else if (size == sizeof(char))
    {
        printf("%c ", *(char *)q);
    }
    else if (size == sizeof(double))
    {
        printf("%lf ", *(double *)q);
    }
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
// LQUEUE_H_INCLUDED
