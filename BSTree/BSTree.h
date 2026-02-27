//
// Created by dsj on 2026/2/26.
//

#ifndef BSTREE_BSTREE_H
#define BSTREE_BSTREE_H
#include <iostream>

template <class T>
class BSTree;

template <class T>
class BSTreeNode
{
public:
    friend class BSTree<T>;

    BSTreeNode(const T& val = T())
        :_val(val)
        ,_left(nullptr)
        ,_right(nullptr)
        ,_parent(nullptr)
    {}

    T& Get()
    {
        return _val;
    }

private:
    T _val;
    BSTreeNode* _left;
    BSTreeNode* _right;
    BSTreeNode* _parent;
};

template <class T>
class BSTree
{
public:
    typedef BSTreeNode<T> Node;
private:
    void RotateR(Node* parent)
    {
        Node* subL = parent->left;
        Node* subLR = subL->_right;
        // 1.
        parent->_left = subLR;
        if (subLR)
        {
            subLR->_parent = parent;
        }

        // 2.
        subL->_right = parent;

        // 3.
        Node* ppNode = parent->parent;
        parent->_parent = subL;

        // 4.
        if (!ppNode)
        {
            subL = _root;
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
    }
public:
    bool insert(const T& val)
    {
        Node* newnode = new Node(val);
        if (_root == nullptr)
        {

            _root = newnode;
            return true;
        }
        Node* cur = _root;
        Node* parent = nullptr;
        while (cur)
        {
            if (val > cur->_val)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (val < cur->_val)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
                return false;
        }
        if (val > parent->_val)
        {
            parent->_right = newnode;
        }
        else
        {
            parent->_left = newnode;
        }
        return true;
    }

    void InOrder()
    {
        _InOrder(_root);
    }

    Node* find(const T& val)
    {
        if (!_root)
            return nullptr;

        Node* cur = _root;
        while (cur)
        {
            if (val > cur->_val)
                cur = cur->_right;
            else if (val < cur->_val)
                cur = cur->_left;
            else
                return cur;
        }
        return nullptr;
    }

    bool erase(const T& val)
    {
        Node* cur = _root;
        Node* parent = cur;
        while (cur)
        {
            if (val > cur->_val)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (val < cur->_val)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                // 左边为空
                if (!cur->left)
                {
                    if (cur == _root)
                    {
                        _root = cur->_right;
                    }
                    else
                    {
                        if (parent->_right == cur)
                        {
                            parent->_right = cur->_right;
                        }
                        else if (parent->_left == cur)
                        {
                            parent->_left = cur->_right;
                        }
                    }
                    delete cur;
                    cur = nullptr;
                    return true;
                }
                // 右边为空
                else if (!cur->_right)
                {
                    if (cur == _root)
                    {
                        _root = cur->left;
                    }
                    else
                    {
                        if (parent->_left == cur)
                        {
                            parent->_left = cur->_left;
                        }
                        else
                        {
                            parent->_right = cur->_left;
                        }
                    }
                    delete cur;
                    cur = nullptr;
                    return true;
                }
                // 左右都不为空
                else
                {
                    // 找右边的最小
                    Node* RightMinNode = cur->_right;
                    Node* RightMinNodeParent = cur;
                    while (RightMinNode->_left)
                    {
                        RightMinNodeParent = RightMinNode;
                        RightMinNode = RightMinNode->_left;
                    }
                    cur->val = RightMinNode->_val;

                    if (RightMinNodeParent->_left == RightMinNode)
                    {
                        RightMinNodeParent->_left = RightMinNode->_right;
                    }
                    else
                    {
                        RightMinNodeParent->_right = RightMinNode->_right;
                    }
                    delete RightMinNode;
                    RightMinNode = nullptr;
                    return true;
                }
            }
        }
        return false;
    }
private:
    void _InOrder(Node* root)
    {
        if (!root)
            return;
        _InOrder(root->_left);
        std::cout << root->_val << " ";
        _InOrder(root->_right);
    }

private:
    Node* _root = nullptr;
};

#endif //BSTREE_BSTREE_H
