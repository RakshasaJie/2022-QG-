#include "../head/LQueue.h"

// *************************************************************************
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

// ѡ�������������
void ChooseType(LQueue *Q)
{
    char cho;
    int flag = 0;

    printf("��ѡ����е��������ͣ�\n[1]  int\n[2]  char\n[3]  double\n");
    printf("���߰� [4] �˳�����\n");
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
            printf("\n�����˳����򣬰ݰݣ�");
            exit(0);
            break;
        default:
            printf("��������ȷ��ָ�\n");
            break;
        }
    }
}
// *********************************************************************

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param     :    Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
    Node *p = NULL;
    p = (Node *)malloc(sizeof(Node)); // ����ͷ����ڴ�
    if (!p)
    {
        printf("��ʼ��ʧ��\n");
    }
    else
    {
        p->next = NULL;
        Q->front = Q->rear = p;
        Q->length = 0;
        printf("��ʼ�����\n");
    }
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param      :   Q ����ָ��Q
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
 *    @description : �������Ƿ�Ϊ��
 *    @param     :    Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param  :       Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param    :     Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
    return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param     :    Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (!p)
    {
        printf("�����ڴ�ʧ�ܣ�\n");
        return FALSE;
    }
    else
    {
        p->data = (void *)malloc(Q->data_size); // �����ڴ�
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
 *    @description : ���Ӳ���
 *    @param     :    Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param     :    Q ����ָ��Q
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
 *    @description : ������������
 *    @param     :    Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param     :    q ָ��q

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
