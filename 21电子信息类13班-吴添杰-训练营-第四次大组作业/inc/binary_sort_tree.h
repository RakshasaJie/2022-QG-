/**
 * Created by Rakshasa on 2022/4/13.
 */

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define true 1
#define false 0
#define succeed 1
#define failed 0

#define M 100

#define Status int

typedef int ElemType;

typedef struct Node
{
    ElemType value;
    ElemType visnum;
    struct Node *left, *right;
} Node, *NodePtr;

typedef struct BinarySortTree
{
    NodePtr root;
} BinarySortTree, *BinarySortTreePtr;

/**
 * BST initialize 初始化树
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr);

/**
 * BST insert 插入数字
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr, ElemType);

/**
 * BST delete 删除数字
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr, ElemType);

/**
 * BST search 查找数字
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr, ElemType);

/**
 * BST preorder traversal without recursion 迭代先序遍历
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr, void (*visit)(NodePtr));

/**
 * BST preorder traversal with recursion 递归先序遍历
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(BinarySortTreePtr, void (*visit)(NodePtr));

/**
 * BST inorder traversal without recursion 迭代中序遍历
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(BinarySortTreePtr, void (*visit)(NodePtr));

/**
 * BST inorder traversal with recursion 递归中序遍历
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(BinarySortTreePtr, void (*visit)(NodePtr));

/**
 * BST preorder traversal without recursion 迭代后序遍历
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(BinarySortTreePtr, void (*visit)(NodePtr));

/**
 * BST postorder traversal with recursion 递归后序遍历
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(BinarySortTreePtr, void (*visit)(NodePtr));

/**
 * BST level order traversal 层序遍历
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr, void (*visit)(NodePtr));

#endif // BINARYSORTTREE_BINARY_SORT_TREE_H
