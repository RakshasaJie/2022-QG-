#include "../inc/binary_sort_tree.h"
#include <stdio.h>
#include <stdlib.h>

Status BST_init(BinarySortTreePtr bt)
{
    if (bt->root == NULL || bt == NULL)
    {
        bt->root = (NodePtr)malloc(sizeof(Node));
        if (bt->root == NULL)
        {
            printf("malloc failed\n\t");
            return failed;
        }
        bt->root->left = NULL;
        bt->root->right = NULL;
        printf("������ͷ���ڵ��Ԫ��ֵ:");
        scanf("%d", &bt->root->value);
        printf("\t");
        printf("�����ɹ�\n\t");
        return succeed;
    }
    else
    {
        printf("�����Ѿ���ʼ��\n\t");
        return failed;
    }
}

Status BST_insert(BinarySortTreePtr bt, ElemType value)
{
    if (bt->root == NULL || bt == NULL)
    {
        printf("δ��ʼ����!\n\t");
        return failed;
    }

    NodePtr p = bt->root;
    NodePtr q = NULL;
    while (p) // �ҵ��������λ��
    {
        if (p->value == value)
        {
            printf("��ֵ�Ѿ���������!\n\t");
            return false;
        }
        else if (value < p->value)
        {
            q = p;
            p = p->left;
        }
        else
        {
            q = p;
            p = p->right;
        }
    } // �˳�ѭ������ʱpָ��գ�����Ҫһ��ָ���丸�ڵ��q

    // �ٽ���һ���ж�
    if (value < q->value)
    {
        NodePtr p1 = (NodePtr)malloc(sizeof(Node));
        q->left = p1;
        p1->value = value;
        p1->left = NULL;
        p1->right = NULL;
    }
    else
    {
        NodePtr p1 = (NodePtr)malloc(sizeof(Node));
        q->right = p1;
        p1->value = value;
        p1->left = NULL;
        p1->right = NULL;
    }

    return succeed;
}

Status BST_delete(BinarySortTreePtr bt, ElemType value)
{
    if (bt->root == NULL || bt == NULL)
    {
        printf("δ��ʼ����!\n\t");
        return failed;
    }

    NodePtr p = bt->root;
    NodePtr q = NULL; // ���ڵ�
    while (p)         // �ҵ���ɾ������λ��
    {
        if (value < p->value)
        {
            q = p;
            p = p->left;
        }
        else if (value > p->value)
        {
            q = p;
            p = p->right;
        }
        else
            break;
    }

    if (p == NULL)
    {
        printf("��Ԫ�ز�������\n\t");
        return failed;
    }

    if (p->left == NULL) // ��ɾ�����Ҷ�ӽڵ����ֻ���Һ���
    {
        if (p == bt->root) // ɾ�����Ǹ����
        {
            bt->root = p->right;
        }
        else if (p == q->left)
        {
            q->left = p->right;
        }
        else
        {
            q->right = p->right;
        }
    }
    else if (p->right == NULL) // ��ɾ���ֻ������
    {
        if (p == bt->root) // ɾ�����Ǹ����
        {
            bt->root = p->left;
        }
        else if (p == q->left)
        {
            q->left = p->left;
        }
        else
        {
            q->right = p->left;
        }
    }
    else // ���Һ��Ӷ�����
    {
        // �ҵ�����������Сֵ
        NodePtr k = p->right;
        q = p;
        while (k->left)
        {
            q = k;
            k = k->left;
        }
        // �滻
        p->value = k->value;
        // ����
        if (k == q->left)
        {
            q->left = k->right;
        }
        else if (k == q->right)
        {
            q->right = k->right;
        }
        p = k;
    }
    free(p);
    p = NULL;

    printf("ɾ���ɹ�\n\t");
    return succeed;
}

Status BST_search(BinarySortTreePtr bt, ElemType value)
{
    if (bt->root == NULL || bt == NULL)
    {
        printf("δ��ʼ����!\n\t");
        return failed;
    }

    NodePtr p = bt->root;
    while (p != NULL)
    {
        if (value == p->value)
        {
            printf("���д��ڴ���ֵ\n\t");
            return succeed;
        }
        else if (value < p->value)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }

    printf("δ���������ҵ�����ֵ\n\t");
    return failed;
}

// ��������
void visit(NodePtr n)
{
    printf("%d ", n->value);
    return;
}

Status RecursionPreTravel(NodePtr node, void (*visit)(NodePtr))
{
    if (node == NULL)
    {
        return failed;
    }
    else
    {
        visit(node);
        RecursionPreTravel(node->left, visit);
        RecursionPreTravel(node->right, visit);
        return succeed;
    }
}

Status BST_preorderR(BinarySortTreePtr bt, void (*visit)(NodePtr))
{
    if (bt->root == NULL || bt == NULL)
    {
        printf("δ��ʼ����!\n\t");
        printf("����ʧ��\n\t");
        return failed;
    }
    else
    {
        printf("�ݹ�����������Ϊ:\n\t");
        RecursionPreTravel(bt->root, visit);
        printf("\n\t");
        printf("�����ɹ�\n\t");
        return succeed;
    }
}

Status RecursionInTravel(NodePtr node, void (*visit)(NodePtr))
{
    if (node == NULL)
    {
        return failed;
    }
    else
    {
        RecursionInTravel(node->left, visit);
        visit(node);
        RecursionInTravel(node->right, visit);
        return succeed;
    }
}

Status BST_inorderR(BinarySortTreePtr bt, void (*visit)(NodePtr))
{
    if (bt->root == NULL || bt == NULL)
    {
        printf("δ��ʼ����!\n\t");
        printf("����ʧ��\n\t");
        return failed;
    }
    else
    {
        printf("�ݹ�����������Ϊ:\n\t");
        RecursionInTravel(bt->root, visit);
        printf("\n\t");
        printf("�����ɹ�\n\t");
        return succeed;
    }
}

Status RecursionPostTravel(NodePtr node, void (*visit)(NodePtr))
{
    if (node == NULL)
    {
        return failed;
    }
    else
    {
        RecursionPostTravel(node->left, visit);
        RecursionPostTravel(node->right, visit);
        visit(node);
        return succeed;
    }
}

Status BST_postorderR(BinarySortTreePtr bt, void (*visit)(NodePtr))
{
    if (bt->root == NULL || bt == NULL)
    {
        printf("δ��ʼ����!\n\t");
        printf("����ʧ��\n\t");
        return failed;
    }
    else
    {
        printf("�ݹ����������Ϊ:\n\t");
        RecursionPostTravel(bt->root, visit);
        printf("\n\t");
        printf("�����ɹ�\n\t");
        return succeed;
    }
}

typedef struct stack
{
    NodePtr elements[M];
    int top;
} seqstack; //����һ�����������͵�ַ��ջ�����������ʱ��׷�ٵ����ĵ�ַ��

seqstack s; //����ջ

void initL() //��ʼ��ջ
{
    s.top = 0;
}

void pushL(NodePtr temp) //��ջ����
{
    s.elements[s.top++] = temp;
}

NodePtr popL() //ȡջ������ջ��
{
    return s.elements[--s.top];
}

int emptyL() //�жϿ�ջ
{
    return s.top == 0;
}

Status BST_preorderI(BinarySortTreePtr bt, void (*visit)(NodePtr))
{
    if (bt->root == NULL || bt == NULL)
    {
        printf("δ��ʼ����!\n\t");
        return failed;
    }

    printf("����(�ǵݹ�)����������Ϊ:\n\t");

    NodePtr p = bt->root;
    while (p || s.top != 0)
    {
        while (p) // �ȱ������ӣ������
        {
            visit(p);
            pushL(p);
            p = p->left;
        }
        // �����ӱ������ȡջ�������Һ���
        // ��ʱѭ����û�н������ٱ����������ӣ�ֱ������ȫ����������
        if (s.top != 0)
        {
            p = popL();
            p = p->right;
        }
    }

    printf("\n\t");
    printf("�����ɹ�\n\t");
    return succeed;
}

Status BST_inorderI(BinarySortTreePtr bt, void (*visit)(NodePtr))
{
    if (bt->root == NULL || bt == NULL)
    {
        printf("δ��ʼ����!\n\t");
        return failed;
    }

    printf("����(�ǵݹ�)����������Ϊ:\n\t");

    NodePtr p = bt->root;
    while (p || s.top != 0)
    {
        while (p) // �ȱ������ӣ�����������ջ����
        {
            pushL(p);
            p = p->left;
        }
        // ������ջ������ȡջ�������ջ��Ԫ�أ������Һ���
        if (s.top != 0)
        {
            p = popL();
            visit(p);
            p = p->right;
        }
    }

    printf("\n\t");
    printf("�����ɹ�\n\t");
    return succeed;
}

Status BST_postorderI(BinarySortTreePtr bt, void (*visit)(NodePtr))
{
    if (bt->root == NULL || bt == NULL)
    {
        printf("δ��ʼ����!\n\t");
        return failed;
    }

    printf("����(�ǵݹ�)����������Ϊ:\n\t");

    NodePtr p = bt->root;
    while (p || s.top != 0)
    {
        while (p)
        {
            p->visnum = 1; // ��ǰ�ڵ��״α�����
            pushL(p);
            p = p->left;
        }
        if (s.top != 0)
        {
            p = popL();
            if (p->visnum == 1) // ��һ�γ�����ջ��
            {
                p->visnum++;
                pushL(p);
                p = p->right;
            }
            else
            {
                if (p->visnum == 2) //�ڶ���������ƿգ���ֹ������ѭ��
                {
                    visit(p);
                    p = NULL;
                }
            }
        }
    }

    printf("\n\t");
    printf("�����ɹ�\n\t");
    return succeed;
}

typedef struct Queue
{
    NodePtr numQ[M];
    int front;
    int rear;
} Queue;

Queue Q;

void initQ()
{ //��ʼ������
    Q.front = 0;
    Q.rear = 0;
}

void pushQ(NodePtr root)
{ //���
    Q.numQ[++Q.rear] = root;
}

NodePtr popQ()
{ //����
    return Q.numQ[++Q.front];
}

int emptyQ()
{ //�ж϶����Ƿ�Ϊ��
    return Q.rear == Q.front;
}

Status BST_levelOrder(BinarySortTreePtr bt, void (*visit)(NodePtr))
{
    if (bt->root == NULL || bt == NULL)
    {
        printf("δ��ʼ����!\n\t");
        return failed;
    }

    printf("��α������Ϊ:\n\t");

    NodePtr p = bt->root;
    pushQ(p);
    while (!emptyQ())
    {
        p = popQ();
        visit(p);
        if (p->left)
        {
            pushQ(p->left);
        }
        if (p->right)
        {
            pushQ(p->right);
        }
    }

    printf("\n\t");
    printf("�����ɹ�\n\t");
    return succeed;
}