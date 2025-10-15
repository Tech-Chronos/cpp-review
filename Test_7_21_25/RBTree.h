//
// Created by 有趣的中国人 on 2025/7/21.
//
#include <iostream>
#include <string>
using namespace std;

#ifndef TEST_7_21_25_RBTREE_H
#define TEST_7_21_25_RBTREE_H

enum colour
{
    RED,
    BLACK
};

template <class K, class V>
class RBNode
{
    typedef RBNode<K, V> Node;
public:
    RBNode()
      :_left(nullptr)
      ,_right(nullptr)
      ,_parent(nullptr)
      ,colour(RED)
    {}

    RBNode(const pair<K,V>& kv)
            :_left(nullptr)
            ,_right(nullptr)
            ,_parent(nullptr)
            ,colour(RED)
            ,_kv(kv)
    {}

    Node* _left;
    Node* _right;
    Node* _parent;

    pair<K, V> _kv;
    colour colour;
};

template <class K, class V>
class RBTree
{
    typedef RBNode<K, V> Node;
public:
    RBTree()
      :_root(nullptr)
    {}

    Node* find(const K& key)
    {
        Node* cur = _root;
        while (cur)
        {
            if (cur->_kv.first > key)
            {
                cur = cur->_left;
            }
            else if (cur->_kv.first < key)
            {
                cur = cur->_right;
            }
            else
                return cur;
        }
        return cur;
    }

    bool insert(const pair<K, V>& kv)
    {
        Node* cur = _root;
        if (cur == nullptr)
        {
            cur = new Node(kv);
            cur->colour = BLACK;
            _root = cur;
            return true;
        }
        else
        {
            Node* parent = nullptr;
            while (cur)
            {
                if (cur->_kv.first > kv.first)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else if (cur->_kv.first < kv.first)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else
                {
                    return false;
                }
            }
            Node* newnode = new Node(kv);
            if (kv.first > parent->_kv.first)
            {
                parent->_right = newnode;
                newnode->_parent = parent;
            }
            else
            {
                parent->_left = newnode;
                newnode->_parent = parent;
            }
            cur = newnode;
            while (cur)
            {
                parent = cur->_parent;
                Node* grandparent = parent->_parent;
                if (!grandparent)
                    return true;
                Node* uncle = nullptr;

                if (parent == grandparent->_left)
                {
                    uncle = grandparent->_right;
                }
                else
                {
                    uncle = grandparent->_right;
                }

                if (parent->colour == RED)
                {
                    if (uncle && uncle->colour == RED)
                    {
                        parent->colour = uncle->colour = BLACK;
                        grandparent->colour = RED;
                        cur = grandparent;
                        continue;
                    }
                    else if ((uncle && uncle->colour == BLACK) || (!uncle))
                    {
                        if (cur == parent->_left && parent == grandparent->_left)
                        {
                            parent->colour = BLACK;
                            grandparent->colour = RED;
                            RotateRight(grandparent);
                            cur = parent;
                        }
                        else if (cur == parent->_right && parent == grandparent->_right)
                        {
                            parent->colour = BLACK;
                            grandparent->colour = RED;
                            RotateLeft(grandparent);
                            cur = parent;
                        }
                        else if (cur == parent->_right && parent == grandparent->_left)
                        {
                            parent->colour = BLACK;
                            grandparent->colour = RED;
                            RotateLeft(parent);
                            RotateRight(grandparent);
                            cur = parent;
                        }
                        else if (cur == parent->_left && parent == grandparent->_right)
                        {
                            parent->colour = BLACK;
                            grandparent->colour = RED;
                            RotateRight(parent);
                            RotateLeft(grandparent);
                            cur = parent;
                        }
                    }
                    _root->colour = BLACK;
                }
            }
        }

    }

    void InOrder()
    {
        _InOrder(_root);
    }

private:
    void printRBTree(Node* cur)
    {
        cout << cur->_kv.first << " : " << cur->_kv.second << endl;
    }

    void _InOrder(Node* root)
    {
        if (!root)
        {
            return;
        }
        _InOrder(root->_left);
        printRBTree(root);
        _InOrder(root->_right);
    }

    void RotateRight(Node* root)
    {
        Node* cur = root;
        Node* subL = cur->_left;
        Node* subLR = subL->_right;

        cur->_left = subLR;
        if (subLR)
            subLR->_parent = cur;
        subL->_right = cur;
        Node* ppNode = cur->_parent;
        cur->_parent = subL;

        if (!ppNode)
        {
            _root = subL;
            return;
        }

        if (cur == ppNode->_left)
        {
            cur->_parent = ppNode;
            subL = ppNode->_left;
        }
        else
        {
            cur->_parent = ppNode;
            subL = ppNode->_right;
        }
    }

    void RotateLeft(Node* root)
    {
        Node* cur = root;
        Node* subR = cur->_right;
        Node* subRL = subR->_left;

        cur->_right = subRL;
        if (subRL)
            subRL->_parent = cur;

        subR->_left = cur;
        Node* ppNode = cur->_parent;
        cur->_parent = subR;

        if (!ppNode)
        {
            _root = subR;
            return;
        }

        if (ppNode->_left == cur)
        {
            ppNode->_left = subR;
        }
        else
        {
            ppNode->_right = subR;
        }
    }
private:
    Node* _root;
};
#endif //TEST_7_21_25_RBTREE_H
