#include "stack.h"


int main()
{
//    cout << "string" << endl;
//    string str = "白月光";
//    cout << str << endl;
//    str += "朱砂痣";
//    cout << str << endl;

    dsj::Stack<int> st;
    st.Push(1);
    st.Push(2);
//    st.Push(3);
    st.Pop();
    st.Pop();
//    st.Pop();
    return 0;
}
