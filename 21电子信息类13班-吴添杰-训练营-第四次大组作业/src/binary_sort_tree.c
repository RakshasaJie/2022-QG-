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
        printf("请输入头顶节点的元素值:");
        scanf("%d", &bt->root->value);
        printf("\t");
        printf("创建成功\n\t");
        return succeed;
    }
    else
    {
        printf("此树已经初始化\n\t");
        return failed;
    }
}

Status BST_insert(BinarySortTreePtr bt, ElemType value)
{
    if (bt->root == NULL || bt == NULL)
    {
        printf("未初始化树!\n\t");
        return failed;
    }

    NodePtr p = bt->root;
    NodePtr q = NULL;
    while (p) // 找到插入结点的位置
    {
        if (p->value == value)
        {
            printf("此值已经存在树中!\n\t");
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
    } // 退出循环，此时p指向空，故需要一个指向其父节点的q

    // 再进行一次判断
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
        printf("未初始化树!\n\t");
        return failed;
    }

    NodePtr p = bt->root;
    NodePtr q = NULL; // 父节点
    while (p)         // 找到待删除结点的位置
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
        printf("此元素不在树中\n\t");
        return failed;
    }

    if (p->left == NULL) // 待删结点是叶子节点或者只有右孩子
    {
        if (p == bt->root) // 删除的是根结点
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
    else if (p->right == NULL) // 待删结点只有左孩子
    {
        if (p == bt->root) // 删除的是根结点
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
    else // 左右孩子都存在
    {
        // 找到右子树的最小值
        NodePtr k = p->right;
        q = p;
        while (k->left)
        {
            q = k;
            k = k->left;
        }
        // 替换
        p->value = k->value;
        // 连接
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

    printf("删除成功\n\t");
    return succeed;
}

Status BST_search(BinarySortTreePtr bt, ElemType value)
{
    if (bt->root == NULL || bt == NULL)
    {
        printf("未初始化树!\n\t");
        return failed;
    }

    NodePtr p = bt->root;
    while (p != NULL)
    {
        if (value == p->value)
        {
            printf("树中存在此数值\n\t");
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

    printf("未能在树中找到此数值\n\t");
    return failed;
}

// 遍历函数
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
        printf("未初始化树!\n\t");
        printf("遍历失败\n\t");
        return failed;
    }
    else
    {
        printf("递归先序遍历结果为:\n\t");
        RecursionPreTravel(bt->root, visit);
        printf("\n\t");
        printf("遍历成功\n\t");
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
        printf("未初始化树!\n\t");
        printf("遍历失败\n\t");
        return failed;
    }
    else
    {
        printf("递归中序遍历结果为:\n\t");
        RecursionInTravel(bt->root, visit);
        printf("\n\t");
        printf("遍历成功\n\t");
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
        printf("未初始化树!\n\t");
        printf("遍历失败\n\t");
        return failed;
    }
    else
    {
        printf("递归后序遍历结果为:\n\t");
        RecursionPostTravel(bt->root, visit);
        printf("\n\t");
        printf("遍历成功\n\t");
        return succeed;
    }
}

typedef struct stack
{
    NodePtr elements[M];
    int top;
} seqstack; //定义一个储存树类型地址的栈，方便遍历的时候追踪到树的地址。

seqstack s; //定义栈

void initL() //初始化栈
{
    s.top = 0;
}

void pushL(NodePtr temp) //入栈操作
{
    s.elements[s.top++] = temp;
}

NodePtr popL() //取栈顶并出栈顶
{
    return s.elements[--s.top];
}

int emptyL() //判断空栈
{
    return s.top == 0;
}

Status BST_preorderI(BinarySortTreePtr bt, void (*visit)(NodePtr))
{
    if (bt->root == NULL || bt == NULL)
    {
        printf("未初始化树!\n\t");
        return failed;
    }

    printf("迭代(非递归)现序遍历结果为:\n\t");

    NodePtr p = bt->root;
    while (p || s.top != 0)
    {
        while (p) // 先遍历左孩子，并输出
        {
            visit(p);
            pushL(p);
            p = p->left;
        }
        // 当左孩子遍历完后，取栈顶，找右孩子
        // 此时循环还没有结束，再遍历它的左孩子，直至孩子全部遍历结束
        if (s.top != 0)
        {
            p = popL();
            p = p->right;
        }
    }

    printf("\n\t");
    printf("遍历成功\n\t");
    return succeed;
}

Status BST_inorderI(BinarySortTreePtr bt, void (*visit)(NodePtr))
{
    if (bt->root == NULL || bt == NULL)
    {
        printf("未初始化树!\n\t");
        return failed;
    }

    printf("迭代(非递归)中序遍历结果为:\n\t");

    NodePtr p = bt->root;
    while (p || s.top != 0)
    {
        while (p) // 先遍历左孩子，所有左孩子入栈结束
        {
            pushL(p);
            p = p->left;
        }
        // 左孩子入栈结束，取栈顶，输出栈顶元素，遍历右孩子
        if (s.top != 0)
        {
            p = popL();
            visit(p);
            p = p->right;
        }
    }

    printf("\n\t");
    printf("遍历成功\n\t");
    return succeed;
}

Status BST_postorderI(BinarySortTreePtr bt, void (*visit)(NodePtr))
{
    if (bt->root == NULL || bt == NULL)
    {
        printf("未初始化树!\n\t");
        return failed;
    }

    printf("迭代(非递归)后序遍历结果为:\n\t");

    NodePtr p = bt->root;
    while (p || s.top != 0)
    {
        while (p)
        {
            p->visnum = 1; // 当前节点首次被访问
            pushL(p);
            p = p->left;
        }
        if (s.top != 0)
        {
            p = popL();
            if (p->visnum == 1) // 第一次出现在栈顶
            {
                p->visnum++;
                pushL(p);
                p = p->right;
            }
            else
            {
                if (p->visnum == 2) //第二次输出并制空，防止陷入死循环
                {
                    visit(p);
                    p = NULL;
                }
            }
        }
    }

    printf("\n\t");
    printf("遍历成功\n\t");
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
{ //初始化队列
    Q.front = 0;
    Q.rear = 0;
}

void pushQ(NodePtr root)
{ //入队
    Q.numQ[++Q.rear] = root;
}

NodePtr popQ()
{ //出队
    return Q.numQ[++Q.front];
}

int emptyQ()
{ //判断对列是否为空
    return Q.rear == Q.front;
}

Status BST_levelOrder(BinarySortTreePtr bt, void (*visit)(NodePtr))
{
    if (bt->root == NULL || bt == NULL)
    {
        printf("未初始化树!\n\t");
        return failed;
    }

    printf("层次遍历结果为:\n\t");

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
    printf("遍历成功\n\t");
    return succeed;
}