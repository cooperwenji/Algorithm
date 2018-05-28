#include<iostream>
#include<stack>
#include<queue>

template<typename T> class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node);
	T deleteHead();

private:
	std::stack<T> stack1;
	std::stack<T> stack2;
};

template<typename T>
CQueue<T>::CQueue(void) {

}

template<typename T>
CQueue<T>::~CQueue(void) {

}

template<typename T>
void CQueue<T>::appendTail(const T& node) {
	stack1.push(node);
}

template<typename T>
T CQueue<T>::deleteHead() {
	if (stack2.size() <= 0) {
		while (!stack1.empty()) {
			T* temp = &stack1.top();
			stack1.pop();
			stack2.push(*temp);
		}
	}

	if (stack2.empty())
		throw new exception("queue is empty");

	T* result = &stack2.top();
	stack2.pop();
	return *result;
}

template<typename T>
class CStack {
public:
	CStack();
	~CStack();

	void push(const T& node);
	T top();
	void pop();

private:
	std::queue<T> queue1;
	std::queue<T> queue2;
};

template<typename T>
CStack<T>::CStack(){}

template<typename T>
CStack<T>::~CStack() {}

template<typename T>
void CStack<T>::push(const T& node) {
	if (!queue1.empty()) {
		queue2.push(node);
		while (!queue1.empty()) {
			T& temp = queue1.front();
			queue1.pop();
			queue2.push(node);
		}
	}
	else {
		queue1.push(node);
		while (!queue2.empty()) {
			T& temp = queue2.front();
			queue2.pop();
			queue1.push(node);
		}
	}
}

template<typename T>
T CStack<T>::top() {
	if (queue1.empty() && queue2.empty())
		throw std::exception("no more element");

	if (!queue1.empty()) {
		return queue1.front();
	}
	else {
		return queue2.front();
	}
}

template<typename T>
void  CStack<T>::pop() {
	if (queue1.empty() && queue2.empty())
		throw std::exception("no more element");

	if (!queue1.empty()) {
		queue1.pop();
	}
	else {
		queue2.pop();
	}

}

//int main(int argc, char** argv) {
//	CQueue<int> que;
//	int a, b;
//	a = 1;
//	b = 2;
//	que.appendTail(a);
//	que.appendTail(b);
//
//	int emp = que.deleteHead();
//	printf("%d ", emp);
//	
//	system("pause");
//	return 0;
//}

