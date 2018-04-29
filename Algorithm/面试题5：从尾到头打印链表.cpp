#include<iostream>
#include<stack>

struct ListNode {
	int m_nKey;
	ListNode* m_pNext;

	ListNode(int key, ListNode* next) :m_nKey(key), m_pNext(next) {}
};

void printListReversingly_Iteratively(ListNode* pHead);
void printListReversingly_Recursively(ListNode* pNode);

int main(int argc, char** argv) {
	ListNode m_1(1, NULL);
	ListNode m_2(2, NULL);
	ListNode m_3(3, NULL);
	m_1.m_pNext = &m_2;
	m_2.m_pNext = &m_3;

	printListReversingly_Recursively(&m_1);

	system("pause");
	return 0;
}

void
printListReversingly_Iteratively(ListNode* pHead) {
    if (pHead == NULL)
		return;

	std::stack<ListNode*> m_stack;

	while (pHead != NULL) {
		m_stack.push(pHead);
		pHead = pHead->m_pNext;
	}

	while (!m_stack.empty()) {
		printf("%d ", m_stack.top()->m_nKey);
		m_stack.pop();
	}
	return;
}

void
printListReversingly_Recursively(ListNode* pNode) {
	if (pNode == NULL)
		return;

	printListReversingly_Recursively(pNode->m_pNext);
	printf(" %d", pNode->m_nKey);

	return;
}
