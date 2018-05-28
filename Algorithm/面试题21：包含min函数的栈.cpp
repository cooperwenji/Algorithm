#include<iostream>
#include<stack>
#include<assert.h>

class MinStack {
public:
	void push(int value) {
		dataStack.push(value);
		if (minStack.size() == 0 || value < minStack.top())
			minStack.push(value);
		else
			minStack.push(minStack.top());
	}
	void pop() {
		assert(dataStack.size() > 0 && minStack.size() > 0);
		dataStack.pop();
		minStack.pop();
	}
	int top() {
		assert(dataStack.size() > 0 && minStack.size() > 0);
		return dataStack.top();
	}
	int min() {
		assert(dataStack.size() > 0 && minStack.size() > 0);
		return minStack.top();
	}
private:
	std::stack<int> dataStack;
	std::stack<int> minStack;
};

//
//int main(int argc, char** argv) {
//	std::stack<int> s;
//	printf("%d ", s.top());
//	system("pause");
//	return 0;
//}

