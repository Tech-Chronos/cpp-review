//
// Created by 有趣的中国人 on 2025/9/3.
//
#include <iostream>
#include <vector>

#ifndef TEST_9_3_25_RBTREE_H
#define TEST_9_3_25_RBTREE_H

enum colour
{
    RED,
    BLACK
};

template <class K, typename V>
class RBTreeNode
{
    typedef RBTreeNode<K, V> Node;
public:
    Node* _left;
    Node* _right;
    Node* _parent;

    colour _col;
    std::pair<K,V> _kv;

    RBTreeNode(const std::pair<K,V>& kv)
      :_left(nullptr)
      ,_right(nullptr)
      ,_parent(nullptr)
      ,_col(RED)
      ,_kv(kv)
    {}
};

template <class K, typename V>
class RBTree
{
    typedef RBTreeNode<K, V> Node;
public:
    bool Insert(const std::pair<K,V>& kv)
    {
        if (_root == nullptr)
        {
            _root = new Node(kv);
            _root->_col = BLACK;
            return true;
        }
        Node* cur = _root;
        Node* parent = nullptr;
        while (cur)
        {
            if (kv.first > cur->_kv.first)
            {
                parent = cur;
                cur = cur->_right;
            }
            else
            {
                parent = cur;
                cur = cur->_left;
            }
        }
        cur = new Node(kv);
        cur->_parent = parent;
        if (cur->_kv.first > parent->_kv.first)
        {
            parent->_right = cur;
        }
        else
        {
            parent->_left = cur;
        }

        while (parent && parent->_col == RED)
        {
            Node *grandparent = parent->_parent;
            Node *uncle = nullptr;

            if (parent == grandparent->_left)
            {
                // 叔叔在右边
                uncle = grandparent->_right;
                // 叔叔存在且是红色
                if (uncle && uncle->_col == RED)
                {
                    parent->_col = uncle->_col = BLACK;
                    grandparent->_col = RED;
                    cur = grandparent;
                    parent = cur->_parent;
                }
                // 叔叔不存在或者叔叔存在为黑色
                else
                {
                    if (cur == parent->_left)
                    {
                        parent->_col = BLACK;
                        grandparent->_col = RED;
                        RotateR(grandparent);
                    }
                    else
                    {
                        cur->_col = BLACK;
                        grandparent->_col = RED;
                        RotateL(parent);
                        RotateR(grandparent);
                    }
                    break;
                }
            }
            else
            {
                // 叔叔在左边
                uncle = grandparent->_left;
                // 叔叔存在且为红色
                if (uncle && uncle->_col == RED)
                {
                    parent->_col = uncle->_col = BLACK;
                    grandparent->_col = RED;
                    cur = grandparent;
                    parent = cur->_parent;
                }
                // 叔叔不存在或者叔叔存在为黑色
                else
                {
                    //
                    //      g
                    //    u    p
                    //           c
                    if (cur == parent->_right)
                    {
                        parent->_col = BLACK;
                        grandparent->_col = RED;
                        RotateL(grandparent);
                    }
                    //        g
                    //     u      p
                    //          c
                    //
                    else
                    {
                        cur->_col = BLACK;
                        grandparent->_col = RED;
                        RotateR(parent);
                        RotateL(grandparent);
                    }
                    break;
                }
            }
        }
        _root->_col = BLACK;
    }

    // 中序遍历
    void InOrder()
    {
        _InOrder(_root);
    }

    // 判断平衡
    // 入口：检查整棵树黑高是否一致
    bool IsBlackHeightBalanced()
    {
        Node* cur = _root;
        int target = 0;
        while (cur)
        {
            if (cur->_col == BLACK)
            {
                ++target;
            }
            cur = cur->_left;
        }
        // 第一次到 NIL 时记录基准黑高
        return _IsBalanced(_root, 0, target);
    }

private:
    // DFS：沿路径累计黑节点数，到 NIL 时与 target 比较
    bool _IsBalanced(Node* node, int blackCnt, int& target)
    {
        if (!node)
        {
            if (target == -1)       // 第一次到 NIL：记录基准
                target = blackCnt;
            return blackCnt == target;
        }

        if (node->_col == BLACK)
            ++blackCnt;             // ★ 先计入当前结点，再分别递归左右

        bool leftOK  = _IsBalanced(node->_left,  blackCnt, target);
        bool rightOK = _IsBalanced(node->_right, blackCnt, target);
        return leftOK && rightOK;
    }


    void _InOrder(Node* root)
    {
        if (!root)
            return;
        _InOrder(root->_left);
        std::cout << root->_kv.first << " -> " << root->_kv.second << std::endl;
        _InOrder(root->_right);
    }

    void RotateL(Node* root)
    {
        //           c
        //   subL         subR
        //            subRL
        Node* cur = root;
        Node* subR = cur->_right;
        Node* subRL = subR->_left;

        // 首先将subRL变成cur的右子树
        if (subRL)
        {
            subRL->_parent = cur;
        }
        cur->_right = subRL;

        // 然后把cur变成subR的左子树
        subR->_left = cur;
        Node* ppNode = cur->_parent;

        cur->_parent = subR;
        if (ppNode)
        {
            subR->_parent = ppNode;
            if (cur == ppNode->_left)
            {
                ppNode->_left = subR;
            }
            else
            {
                ppNode->_right = subR;
            }
        }
        else
        {
            _root = subR;
            subR->_parent = nullptr;
        }
    }

    void RotateR(Node* root)
    {
        //           c
        //   subL         subR
        //       subLR
        Node* cur = root;
        Node* subL = cur->_left;
        Node* subLR = subL->_right;

        // 将cur变成subL的右边
        subL->_right = cur;
        Node* ppNode = cur->_parent;

        if (ppNode)
        {
            subL->_parent = ppNode;
            if (cur == ppNode->_left)
            {
                ppNode->_left = subL;
            }
            else
            {
                ppNode->_right = subL;
            }
        }
        else
        {
            _root = subL;
            subL->_parent = nullptr;
        }

        cur->_parent = subL;

        // subLR变成cur的左边
        cur->_left = subLR;
        if (subLR)
        {
            subLR->_parent = cur;
        }

    }
private:
    Node* _root = nullptr;
};

#endif //TEST_9_3_25_RBTREE_H
