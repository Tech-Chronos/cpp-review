//
// Created by dsj on 2026/2/26.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H
#include <iostream>

namespace dsj
{
    template<class T>
    struct TreeNode
    {
    public:
        T _val;
        TreeNode *_left;
        TreeNode *_right;
    public:
        TreeNode(const T &val)
            : _val(val)
            , _left(nullptr)
            , _right(nullptr)
        {}
    };
}
#endif //TREE_TREE_H
