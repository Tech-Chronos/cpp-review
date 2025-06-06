#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <set>
using namespace std;

// 逆波兰表达式
// https://leetcode.cn/problems/evaluate-reverse-polish-notation/submissions/634844579/
class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        int right = 0;
        int left = 0;
        set<string> oper = {"+","-","*","/"};
        stack<int> st;
        for (size_t i = 0; i < tokens.size(); ++i)
        {
            if (oper.find(tokens[i]) != oper.end())
            {
                // 操作符
                if (tokens[i] == "+")
                {
                    if (st.empty())
                    {
                        right = stoi(tokens[i - 1]);
                    }
                    else
                    {
                        right = st.top();
                        st.pop();
                    }
                    left = stoi(tokens[i - 2]);
                    int val = left + right;
                    st.push(val);
                }
                else if (tokens[i] == "-")
                {
                    if (st.empty())
                    {
                        right = stoi(tokens[i - 1]);
                    }
                    else
                    {
                        right = st.top();
                        st.pop();
                    }
                    left = stoi(tokens[i - 2]);
                    int val = left - right;
                    st.push(val);
                }
                else if (tokens[i] == "*")
                {
                    if (st.empty())
                    {
                        right = stoi(tokens[i - 1]);
                    }
                    else
                    {
                        right = st.top();
                        st.pop();
                    }
                    left = stoi(tokens[i - 2]);
                    int val = left * right;
                    st.push(val);
                }
                else if (tokens[i] == "/")
                {
                    if (st.empty())
                    {
                        right = stoi(tokens[i - 1]);
                    }
                    else
                    {
                        right = st.top();
                        st.pop();
                    }
                    left = stoi(tokens[i - 2]);
                    int val = left / right;
                    st.push(val);
                }
            }
        }
        return st.top();
    }
};

// 栈的压入、弹出序列
// https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&&tqId=11174&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
/*
* @param pushV int整型vector
* @param popV int整型vector
* @return bool布尔型
*/
bool IsPopOrder(vector<int>& pushV, vector<int>& popV)
{
    // write code here
    size_t pushi = 0;
    size_t popi = 0;
    stack<int> st;
    while (pushi < pushV.size())
    {
        st.push(pushV[pushi++]);
        while (!st.empty() && st.top() == popV[popi])
        {
            cout << "popi -> " << popi << endl;
            ++popi;
            st.pop();
        }
    }
    return st.empty();
}

// 最小栈
// https://leetcode.cn/problems/min-stack/submissions/634804561/
class MinStack {
public:
    void push(int val)
    {
        _st.push(val);
        if (_minst.empty() || val <= _minst.top())
        {
            _minst.push(val);
        }
    }

    void pop()
    {
        if (_st.top() == _minst.top())
        {
            _minst.pop();
        }
        _st.pop();
    }

    int top()
    {
        return _st.top();
    }

    int getMin()
    {
        return _minst.top();
    }
private:
    stack<int> _st;
    stack<int> _minst;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main()
{
    return 0;
}
