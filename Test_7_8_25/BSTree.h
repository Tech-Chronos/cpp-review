//
// Created by 有趣的中国人 on 2025/7/8.
//
#ifndef TEST_7_8_25_BSTREE_H
#define TEST_7_8_25_BSTREE_H
#include <iostream>
using namespace std;

template <class K>
class BSNode
{
public:
    explicit BSNode(const K& k = K())
      :_left(nullptr)
      ,_right(nullptr)
      ,key(k)
    {}

public:
    BSNode* _left;
    BSNode* _right;
    K key;
};

template<class T>
class BSTree
{
    typedef BSNode<T> Node;
public:
    bool find(const T& val)
    {
        Node* cur = _root;
        while (cur)
        {
            if (val < cur->key)
            {
                cur = cur->_left;
            }
            else if (val > cur->key)
            {
                cur = cur->_right;
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    bool insert(const T& val)
    {
        Node* newnode = new Node(val);
        if (!_root)
        {
            _root = newnode;
        }
        else
        {
            Node* cur = _root;
            Node* parent = nullptr;
            while (cur)
            {
                if (val < cur->key)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else if (val > cur->key)
                {
                    parent = cur;
                    cur = cur->_right;
                }
            }
            if (val < parent->key)
            {
                parent->_left = newnode;
            }
            else
            {
                parent->_right = newnode;
            }
        }
    }

    bool erase(const T& val)
    {
        Node* cur = _root;
        Node* parent = nullptr;
        while (cur)
        {
            if (val < cur->key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else if (val > cur->key)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (val == cur->key)
            {
                // 左孩子为空
                if (cur->_left == nullptr)
                {
                    if (cur == _root)
                        _root = cur->_right;
                    else
                    {
                        if (parent->_left == cur)
                        {
                            parent->_left = cur->_right;
                        }
                        else if (parent->_right == cur)
                        {
                            parent->_right = cur->_right;
                        }
                    }
                    delete cur;
                    return true;
                }
                // 右孩子为空
                else if (cur->_right == nullptr)
                {
                    if (cur == _root)
                        _root = cur->_left;
                    else
                    {
                        if (parent->_left == cur)
                        {
                            parent->_left = cur->_left;
                        }
                        else if (parent->_right == cur)
                        {
                            parent->_right = cur->_left;
                        }
                    }
                    delete cur;
                    return true;
                }
                // 左右孩子均不为空，找左子树最大结点
                // 或者右子树最小节点
                else
                {
                    Node* rightmin = cur->_right;
                    // rightminparent 不能给空指针，因为如果删除的节点的右孩子没有左孩子
                    // 也就是说不会进下面的循环，那么 rightminparent 就是空指针
                    // 就是野指针访问
                    Node* rightminparent = cur;
                    while (rightmin->_left)
                    {
                        rightminparent = rightmin;
                        rightmin = rightmin->_left;
                    }
                    swap(rightmin->key, cur->key);
                    if (rightmin == rightminparent->_left)
                        rightminparent->_left = rightmin->_right;
                    else if (rightmin == rightminparent->_right)
                        rightminparent->_right = rightmin->_right;
                    delete rightmin;
                    return true;
                }
            }
        }
        return false;
    }

    // 中序遍历
    void PrintBSTree(Node* node)
    {
        cout << node->key << " ";
    }

    void InOrder()
    {
        _InOrder(_root);
        cout << endl;
    }
private:
    void _InOrder(Node* node)
    {
        if (node)
        {
            _InOrder(node->_left);
            PrintBSTree(node);
            _InOrder(node->_right);
        }
        return;
    }

    Node* _root = nullptr;
};

#endif //TEST_7_8_25_BSTREE_H
