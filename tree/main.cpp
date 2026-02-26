#include <iostream>
#include <queue>
#include "tree.h"

dsj::TreeNode<int>* ConstructTree()
{
    dsj::TreeNode<int>* root = new dsj::TreeNode<int>(1);
    root->_left = new dsj::TreeNode<int>(2);
    root->_right = new dsj::TreeNode<int>(3);
    root->_left->_left = new dsj::TreeNode<int>(4);
    root->_left->_right = new dsj::TreeNode<int>(5);
    return root;
}

// 前序
void PreOrder(const dsj::TreeNode<int>* root)
{
    if (!root)
        return;
    std::cout << root->_val << " ";
    PreOrder(root->_left);
    PreOrder(root->_right);
}

// 中序
void InOrder(const dsj::TreeNode<int>* root)
{
    if (!root)
        return;
    InOrder(root->_left);
    std::cout << root->_val << " ";
    InOrder(root->_right);
}

// 后序遍历
void PostOrder(const dsj::TreeNode<int>* root)
{
    if (!root)
        return;
    PostOrder(root->_left);
    PostOrder(root->_right);
    std::cout << root->_val << " ";
}

// 层序遍历
void LevelOrder(dsj::TreeNode<int>* root)
{
    if (!root)
        return;
    std::queue<dsj::TreeNode<int>*> q;
    q.push(root);
    while (!q.empty())
    {
        dsj::TreeNode<int>* cur = q.front();
        std::cout << cur->_val << " ";
        q.pop();

        if (cur->_left)
            q.push(cur->_left);
        if (cur->_right)
            q.push(cur->_right);
    }
}

void test_order()
{
    dsj::TreeNode<int>* root = ConstructTree();

    std::cout << "PreOrder -> ";
    PreOrder(root);
    std::cout << "\n";

    std::cout << "InOrder -> ";
    InOrder(root);
    std::cout << "\n";

    std::cout << "PostOrder -> ";
    PostOrder(root);
    std::cout << "\n";

    std::cout << "LevelOrder -> ";
    LevelOrder(root);
    std::cout << "\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
// 计算高度
int Height(dsj::TreeNode<int>* root)
{
    if (!root)
        return 0;
    int left_height = Height(root->_left) + 1;
    int right_height = Height(root->_right) + 1;

    return std::max(left_height, right_height);
}

int maxDepth(dsj::TreeNode<int>* root)
{
    if (!root) return 0;

    return std::max(maxDepth(root->_left),
               maxDepth(root->_right)) + 1;
}

void test_height()
{
    dsj::TreeNode<int>* root = ConstructTree();
    std::cout << maxDepth(root);
}

/////////////////////////////////////////////////////////////////////////////////////////
// -1 表示非平衡，运用后序遍历
int Check(dsj::TreeNode<int>* root)
{
    if (!root)
        return 0;

    int left_height = Check(root->_left);
    if (left_height == -1)
        return -1;

    int right_height = Check(root->_right);
    if (right_height == -1)
        return -1;

    if (std::abs(left_height - right_height) > 1)
    {
        return -1;
    }

    return std::max(left_height, right_height) + 1;
}

// 判断是否平平衡
bool IsBalanced()
{
    dsj::TreeNode<int>* root = new dsj::TreeNode(1);
    root->_left = new dsj::TreeNode(2);
    root->_left->_left = new dsj::TreeNode(3);
    root->_left->_left->_left = new dsj::TreeNode(4);
    root->_left->_left->_left->_left = new dsj::TreeNode(5);
    return Check(root) != -1;
}


/////////////////////////////////////////////////////////////////////////////////////////
// 节点个数
int BinaryTreeSize(dsj::TreeNode<int>* root)
{
    if (!root)
        return 0;
    int l = BinaryTreeSize(root->_left);
    int r = BinaryTreeSize(root->_right);

    return l + r + 1;
}

// 叶子节点
int BinaryTreeLeafSize(dsj::TreeNode<int>* root)
{
    if (!root)
        return 0;
    int l = BinaryTreeLeafSize(root->_left);
    int r = BinaryTreeLeafSize(root->_right);

    if (l == 0 && r == 0)
    {
        return 1;
    }
    return l + r;
}

int BinaryTreeLevelKSize1(dsj::TreeNode<int>* root, int k)
{
    if (!root || k <= 0)
        return 0;
    if (k == 1)
        return 1;
    return BinaryTreeLevelKSize1(root->_left, k - 1) + BinaryTreeLevelKSize1(root->_right, k - 1);
}

int BinaryTreeLevelKSize2(dsj::TreeNode<int>* root, int k)
{
    std::queue<dsj::TreeNode<int>*> q;
    q.push(root);
    int level = 1;

    while (!q.empty())
    {
        size_t size = q.size();
        if (level == k)
            return size;

        while (size--)
        {
            dsj::TreeNode<int>* cur = q.front();
            q.pop();

            if (cur->_left)
                q.push(cur->_left);
            if (cur->_right)
                q.push(cur->_right);
        }
        ++level;
    }
    return 0;
}


dsj::TreeNode<int>* BinaryTreeFind(dsj::TreeNode<int>* root, int x)
{
    if (!root)
        return nullptr;

    if (root->_val == x)
    {
        return root;
    }
    dsj::TreeNode<int>* left = BinaryTreeFind(root->_left, x);
    if (left)
        return left;
    return BinaryTreeFind(root->_right, x);
}

int main()
{
    dsj::TreeNode<int>* root = ConstructTree();
    std::cout << "BinaryTreeSize(root): " << BinaryTreeSize(root) << std::endl;

    std::cout << "BinaryTreeLeafSize(root): " << BinaryTreeLeafSize(root) << std::endl;

    std::cout << "BinaryTreeLevelKSize(root): " << BinaryTreeLevelKSize1(root, 4) << std::endl;
    std::cout << "BinaryTreeLevelKSize(root): " << BinaryTreeLevelKSize2(root, 1) << std::endl;

    std::cout << "BinaryTreeFind: " << BinaryTreeFind(root, 3)->_val;
    return 0;
}
