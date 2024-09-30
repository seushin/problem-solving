/*
 * https://leetcode.com/problems/design-a-stack-with-increment-operation
 */
#include <vector>

class CustomStack
{
private:
	std::vector<int> stack;
	int maxSize;
	int top;

public:
	CustomStack(int maxSize) : stack(maxSize), maxSize(maxSize), top(0) {}

	void push(int x)
	{
		if (top < maxSize)
			stack[top++] = x;
	}

	int pop()
	{
		if (top == 0)
			return -1;
		return stack[--top];
	}

	void increment(int k, int val)
	{
		int n = std::min(k, top);

		for (int i = 0; i < n; ++i)
		{
			stack[i] += val;
		}
	}
};
