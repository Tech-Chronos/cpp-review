//
// Created by 有趣的中国人 on 2025/9/18.
//
#include <iostream>

#ifndef TEST_9_18_25_RBTREE_H
#define TEST_9_18_25_RBTREE_H

using namespace std;

enum colour
{
    RED,
    BLACK
};


template <class V>
struct RBTreeNode
{
    typedef RBTreeNode<V> Node;
    explicit RBTreeNode(const V& kv)
      :_left(nullptr)
      ,_right(nullptr)
      ,_parent(nullptr)
      ,_kv(kv)
      ,_col(RED)
    {}

    Node* _left;
    Node* _right;
    Node* _parent;
    V _kv;
    colour _col;
};

template <class V, class Ref, class Ptr>
struct __RBTreeIterator
{
    typedef RBTreeNode<V> Node;
    typedef __RBTreeIterator<V, Ref, Ptr> Self;


    Ref operator*()
    {
        return _node->_kv;
    }

    Ptr operator->()
    {
        return &_node->_kv;
    }

    bool operator!=(const Self& self)
    {
        return _node != self._node;
    }

    bool operator==(const Self& self)
    {
        return _node == self._node;
    }

    Self& operator++()
    {
        Node* cur = _node;
        // 如果右边不为空，下一个访问右子树的最左节点；
        if (cur && cur->_right)
        {
            Node* leftMin = cur->_right;
            while (leftMin->_left)
            {
                leftMin = leftMin->_left;
            }
            _node = leftMin;
        }
        // 如果右子树为空，下一个访问孩子是父亲左的祖先
        else if (cur && !cur->_right)
        {
            Node* parent = cur->_parent;
            while (parent && cur == parent->_right)
            {
                cur = parent;
                parent = parent->_parent;
            }

            _node = parent;
        }
        return *this;
    }

    Self& operator--()
    {
        Node* cur = _node;
        if (cur && cur->_left)
        {
            Node* leftMost = cur->_left;
            while (leftMost->_right)
            {
                leftMost = leftMost->_right;
            }
            _node = leftMost;
        }
        else if (cur && !cur->_left)
        {
            Node* parent = cur->_parent;
            while(parent && cur == parent->_left)
            {
                cur = parent;
                parent = parent->_parent;
            }

            _node = cur;
        }
        return *this;
    }
public:
    Node* _node;
};

template <class K, class V, class KeyOfV>
class RBTree
{
public:
    typedef RBTreeNode<V> Node;
    typedef __RBTreeIterator<V, V&, V*> Iterator;
    typedef __RBTreeIterator<V, const V&, const V*> Const_Iterator;
public:
    RBTree() = default;

    RBTree(const RBTree<K, V, KeyOfV>& rb)
    {
        _root = copy(rb._root);
    }

    ~RBTree()
    {
        Destroy(_root);
    }

    // mp1 = mp3
    RBTree<K, V, KeyOfV>& operator=(RBTree<K, V, KeyOfV> replace_rb)
    {
        swap(_root, replace_rb._root);
        return *this;
    }

    Iterator begin()
    {
        Node* cur = _root;
        while (cur && cur->_left)
        {
            cur = cur->_left;
        }

        return Iterator(cur);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }

    Const_Iterator begin() const
    {
        Node* cur = _root;
        while (cur && cur->_left)
        {
            cur = cur->_left;
        }

        return Const_Iterator(cur);
    }

    Const_Iterator end() const
    {
        return Const_Iterator(nullptr);
    }

    pair<Iterator , bool> Insert(const V& kv)
    {
        Node* cur = _root;
        Node* parent = nullptr;

        KeyOfV kov;
        if (_root == nullptr)
        {
            cur = new Node(kv);
            _root = cur;
            _root->_col = BLACK;

            Iterator it(_root);
            return {it, true};
        }
        while (cur)
        {
            if (kov(kv) > kov(cur->_kv))
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (kov(kv) < kov(cur->_kv))
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                //kov(cur->_kv) = kov(kv);
                return {Iterator(cur), false};
            }
        }
        cur = new Node(kv);
        Node* newnode = cur;
        if (kov(cur->_kv) > kov(parent->_kv))
        {
            cur->_parent = parent;
            parent->_right = cur;
        }
        else
        {
            cur->_parent = parent;
            parent->_left = cur;
        }
        //  调整连续的红色节点
        while (parent && parent->_col == RED)
        {
            Node* grandparent = parent->_parent;
            Node* uncle = nullptr;
            if (parent == grandparent->_left)
            {
                //         g(b)               g(r)
                //     p(r)     u(r)      p(b)    u(b)
                //  c(r)              c(r)
                uncle = grandparent->_right;
                if (uncle && uncle->_col == RED)
                {
                    parent->_col = uncle->_col = BLACK;
                    grandparent->_col = RED;
                    cur = grandparent;
                    parent = cur->_parent;
                }
                //       g(b)                g(r)
                //   p(r)     u(b)       p(b)     u(b)
                // c(r)               c(r)
                else if (!uncle || uncle->_col == BLACK)
                {
                    if (cur == parent->_left)
                    {
                        parent->_col = BLACK;
                        grandparent->_col = RED;
                        RotateR(grandparent);
                    }
                    //         g(b)               g(r)
                    //     p(r)    u(b)       c(b)     u(b)
                    //         c(r)        p(r)
                    else if (cur == parent->_right)
                    {
                        RotateL(cur);
                        cur->_col = BLACK;
                        grandparent->_col = RED;
                        RotateR(grandparent);
                    }
                    break;
                }
            }
            else
            {
                //      g
                //   u     p
                //            c
                uncle = grandparent->_left;
                if (uncle && uncle->_col == RED)
                {
                    parent->_col = uncle->_col = BLACK;
                    grandparent->_col = RED;
                    cur = grandparent;
                    parent = cur->_parent;
                }
                else if (!uncle || uncle->_col == BLACK)
                {
                    //       g(b)               g(r)
                    //   u(b)    p(r)       u(b)     p(b)
                    //              c(r)                c(r)
                    if (cur == parent->_right)
                    {
                        parent->_col = BLACK;
                        grandparent->_col = RED;
                        RotateL(grandparent);
                        break;
                    }
                    else if (cur == parent->_left)
                    {
                        //       g(b)           g(r)
                        //    u(b)   p(r)    u(b)  c(b)
                        //        c(r)               p(r)
                        RotateR(parent);
                        cur->_col = BLACK;
                        grandparent->_col = RED;
                        RotateL(grandparent);
                        break;
                    }
                }
            }
        }
        _root->_col = BLACK;

        return {Iterator(newnode), true};
    }

    void InOrder()
    {
        // 如果外面直接调用，要传入root进来，但是外面不知道。
        _InOrder(_root);
    }

    bool IsBalance()
    {
        if (_root->_col != BLACK)
        {
            cout << "根节点不是黑色！" << endl;
            return false;
        }

        Node* cur = _root;
        int black_num = 0;
        while (cur)
        {
            if (cur->_col == BLACK)
            {
                ++black_num;
            }
            cur = cur->_left;
        }
        cout << "black_num: " << black_num << endl;
        // 这里同理
        return _IsBalance(_root, 0, black_num);
    }
private:
    void Destroy(Node* root)
    {
        // 析构函数用后序遍历
        if (root == nullptr)
            return;
        Destroy(root->_left);
        Destroy(root->_right);

        delete root;
        root = nullptr;
    }

    Node* copy(Node* root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        // 调用Node构造函数
        Node* newroot = new Node(root->_kv);
        newroot->_col = root->_col;

        newroot->_left = copy(root->_left);
        if (newroot->_left != nullptr)
        {
            newroot->_left->_parent = newroot;
        }

        newroot->_right = copy(root->_right);
        if (newroot->_right != nullptr)
        {
            newroot->_right->_parent = newroot;
        }

        return newroot;
    }

    // 检测平衡，主要是下面几点
    // 1. 每条路径上有相同数量的黑色节点
    // 2. 不存在连续的红色节点
    // 3. 根节点是黑色的
    // 4. 中序遍历是有序的（已经检查过了）
    bool _IsBalance(Node* root, int black_num, int accurate_num)
    {
        KeyOfV kov;
        Node* cur = root;
        if (!cur)
        {
            if (black_num != accurate_num)
            {
                cout << "存在不同数量的黑色节点" << endl;
                return false;
            }
            return true;
        }

        if (cur->_col == RED)
        {
            Node* parent = cur->_parent;
            if (parent && parent->_col == RED)
            {
                cout << "存在连续的红色节点，位置：" << kov(cur->_kv) << ": " << cur->_kv.second << endl;
                return false;
            }
        }

        // 这边用前序遍历，因为要算出根节点的黑色节点的数量之后再传给左右子树。
        if (cur->_col == BLACK)
        {
            ++black_num;
        }
        bool ret1 = _IsBalance(cur->_left, black_num, accurate_num);
        bool ret2 = _IsBalance(cur->_right,black_num, accurate_num);

        return ret1 & ret2;
    }

    void _InOrder(Node* root)
    {
        KeyOfV kov;
        if (!root)
        {
            return;
        }
        _InOrder(root->_left);
        cout << kov(root->_kv) << endl;
        _InOrder(root->_right);
    }

    void RotateR(Node* root)
    {
        //        cur
        //   subL
        //       subLR
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
            subL->_parent = nullptr;
            _root = subL;
        }
        else
        {
            subL->_parent = ppNode;
            if (ppNode->_left == cur)
            {
                ppNode->_left = subL;
            }
            else
            {
                ppNode->_right = subL;
            }
        }
    }

    void RotateL(Node* root)
    {
        //    cur
        //        subR
        //    subRL
        Node* cur = root;
        Node* subR = cur->_right;
        Node* subRL = subR->_left;

        cur->_right = subRL;
        if (subRL)
            subRL->_parent = cur;

        Node* ppNode = cur->_parent;
        subR->_left = cur;
        cur->_parent = subR;

        if (!ppNode)
        {
            subR->_parent = nullptr;
            _root = subR;
        }
        else
        {
            subR->_parent = ppNode;
            if (ppNode->_left == cur)
            {
                ppNode->_left = subR;
            }
            else
            {
                ppNode->_right = subR;
            }
        }
    }


private:
    Node* _root = nullptr;
};
#endif //TEST_9_18_25_RBTREE_H
