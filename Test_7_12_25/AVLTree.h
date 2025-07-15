//
// Created by 有趣的中国人 on 2025/7/12.
//
#include <iostream>
#include <string>
#include <vector>

#include <time.h>
#include <assert.h>

using namespace std;
#ifndef TEST_7_12_25_AVLTREE_H
#define TEST_7_12_25_AVLTREE_H

template <typename K, class V>
struct AVLTreeNode
{
    // 三叉链
    typedef AVLTreeNode<K, V> Node;

    Node* _left;
    Node* _right;
    Node* _parent;
    pair<K, V> _val;
    int _bf;

    explicit AVLTreeNode(const pair<K, V>& val)
      :_left(nullptr)
      ,_right(nullptr)
      ,_parent(nullptr)
      ,_val(val)
      ,_bf(0)
    {}
};

template <typename K, class V>
class AVLTree
{
    typedef AVLTreeNode<K, V> Node;
private:
    void RotateR(Node* parent)
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;

        parent->_left = subLR;
        if (subLR)
            subLR->_parent = parent;

        subL->_right = parent;
        Node* ppNode = parent->_parent;
        parent->_parent = subL;

        if (!ppNode)
        {
            _root = subL;
            subL->_parent = nullptr;
        }


        else
        {
            if (ppNode->_left == parent)
            {
                ppNode->_left = subL;
                subL->_parent = ppNode;
            }
            else
            {
                ppNode->_right = subL;
                subL->_parent = ppNode;
            }
        }
        parent->_bf = subL->_bf = 0;
    }

    void RotateL(Node* parent)
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;

        parent->_right = subRL;
        if (subRL)
            subRL->_parent = parent;

        subR->_left = parent;
        Node* ppNode = parent->_parent;
        parent->_parent = subR;

        if (!ppNode)
        {
            _root = subR;

            // 这里要更新 ！！！
            subR->_parent = nullptr;
        }

        else
        {
            if (ppNode->_left == parent)
            {
                ppNode->_left = subR;
                subR->_parent = ppNode;
            }
            else
            {
                ppNode->_right = subR;
                subR->_parent = ppNode;
            }
        }
        parent->_bf = subR->_bf = 0;
    }

    void RotateLR(Node* parent)
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;

        int bf = subLR->_bf;
        RotateL(subL);
        RotateR(parent);

        // 平衡因子的判断
        if (bf == -1)
        {
            subLR->_bf = 0;
            subL->_bf = 0;
            parent->_bf = 1;
        }
        else if (bf == 1)
        {
            subLR->_bf = 0;
            subL->_bf = -1;
            parent->_bf = 0;
        }
        else if (bf == 0)
        {
            subLR->_bf = subL->_bf = parent->_bf = 0;
        }
        else
        {
            assert(false);
        }
    }

    Node* RotateRL(Node* parent)
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;

        int bf = subRL->_bf;

        RotateR(subR);
        RotateL(parent);

        if (bf == 1)
        {
            subRL->_bf = 0;
            subR->_bf = 0;
            parent->_bf = -1;
        }
        else if (bf == -1)
        {
            subRL->_bf = 0;
            parent->_bf = 0;
            subR->_bf = 1;
        }
        else if (bf == 0)
        {
            subRL->_bf = 0;
            parent->_bf = 0;
            subR->_bf = 0;
        }
        else
        {
            assert(false);
        }
    }
public:
    AVLTree()
      :_root(nullptr)
    {}

    bool insert(const pair<K, V>& val)
    {
        if (!_root)
        {
            _root = new Node(val);
            return true;
        }
        else
        {
            Node* cur = _root;
            Node* parent = nullptr;
            while (cur)
            {
                if (val.first < cur->_val.first)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else if (val.first > cur->_val.first)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else
                    return false;
            }
            cur = new Node(val);
            if (val.first < parent->_val.first)
            {
                parent->_left = cur;
                cur->_parent = parent;
            }
            else if (val.first > parent->_val.first)
            {
                parent->_right = cur;
                cur->_parent = parent;
            }

            // 更新所有的父节点!!!!
            while (parent)
            {
                if (cur == parent->_left)
                    --parent->_bf;
                else
                    ++parent->_bf;

                if (parent->_bf == 0)
                    break;
                else if (parent->_bf == 1 || parent->_bf == -1)
                {
                    cur = parent;
                    parent = parent->_parent;
                }
                else if (parent->_bf == 2 || parent->_bf == -2)
                {
                    if (parent->_bf == -2 && cur->_bf == -1)
                        RotateR(parent);
                    else if (parent->_bf == 2 && cur->_bf == 1)
                        RotateL(parent);
                    else if (parent->_bf == -2 && cur->_bf == 1)
                    {
                        RotateLR(parent);
                    }
                    else if (parent->_bf == 2 && cur->_bf == -1)
                    {
                        RotateRL(parent);
                    }
                    break;
                }
                else
                {
                    assert(false);
                }
            }
        }
        return false;
    }

    Node* find(const K& key)
    {
        Node* cur = _root;
        while (cur)
        {
            if (key < cur->_val.first)
            {
                cur = cur->_left;
            }
            else if (key > cur->_val.first)
            {
                cur = cur->_right;
            }
            else
            {
                return cur;
            }
        }
        return nullptr;
    }

    void PrintAVL(Node* cur)
    {
        cout << cur->_val.first << " : " << cur->_val.second << endl;
    }

    void InOrder()
    {
        _InOrder(_root);
    }

    bool IsBalance()
    {
        return _IsBalance(_root);
    }

    int Height()
    {
        return _Height(_root);
    }

    int Size()
    {
        return _Size(_root);
    }

private:
    int _Size(Node* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return _Size(root->_left) + _Size(root->_right) + 1;
    }

//    int _Size(Node* root, int count = 0)
//    {
//        if (root == nullptr)
//        {
//            return count;
//        }
//        return _Size(root->_left, count + 1) + _Size(root->_right, count + 1);
//    }

    int _Height(Node* root)
    {
        if (root == nullptr)
            return 0;
        return max(_Height(root->_left), _Height(root->_right)) + 1;
    }

    bool _IsBalance(Node* root)
    {
        int left_height = _Height(root->_left);
        int right_height = _Height(root->_right);

        if (abs(left_height - right_height) < 2)
            return true;
        else
            return false;
    }

    void _InOrder(Node* root)
    {
        if (root)
        {
            _InOrder(root->_left);
            PrintAVL(root);
            _InOrder(root->_right);
        }
        return;
    }
    Node* _root;
};

#endif //TEST_7_12_25_AVLTREE_H
