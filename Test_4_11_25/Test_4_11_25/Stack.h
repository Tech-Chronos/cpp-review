#pragma once
#include <iostream>
using namespace std;

struct Stack
{
public:
	int top;
	int capacity;
	int* s;
};

static inline void CheckCapacity(Stack& st)
{
	if (st.capacity == 0)
	{
		st.s = (int*)malloc(4 * sizeof(int));
		st.capacity = 4;
	}
	else if (st.top == st.capacity)
	{
		st.capacity = 2 * st.capacity;
		st.s = (int*)realloc(st.s, st.capacity * sizeof(int));
	}
}

static inline void InitStack(Stack& st)
{
	st.s = nullptr;
	st.capacity = 0;
	st.top = -1;
}

static inline void PushStack(Stack& st, int val)
{
	CheckCapacity(st);
	st.s[++st.top] = val;
}

static inline void PopStack(Stack& st)
{
	--st.top;
}

static inline int TopStack(Stack& st)
{
	return st.s[st.top];
}

static inline void DestroyStack(Stack& st)
{
	st.s = nullptr;
	free(st.s);
	st.capacity = 0;
	st.top = -1;
}
