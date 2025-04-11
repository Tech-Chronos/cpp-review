#pragma once

struct Stack
{
public:
	int top;
	int capacity;
	int* s;
};

void InitStack(Stack& st)
{
	st.s = nullptr;
	st.capacity = 4;
	st.top = -1;
}

void PushStack(Stack& st, int& val)
{
	st.s[++st.top] = val;
}
