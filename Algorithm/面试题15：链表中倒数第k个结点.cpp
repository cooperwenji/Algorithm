#include<iostream>

struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == NULL || k == 0)
		return NULL;

	ListNode* first = pListHead;
	ListNode* distK = first;

	for (int i = 0; i < k - 1; i++) {
		if (distK->m_pNext == NULL) {
			return NULL;
		}
		distK = distK->m_pNext;
	}

	while (distK->m_pNext != NULL) {
		first = first->m_pNext;
		distK = distK->m_pNext;
	}

	return first;
}

ListNode* FindMiddleNode(ListNode* pListHead) {
	if (pListHead == NULL)
		return NULL;

	ListNode* oneStep = pListHead;
	ListNode* twoStep = pListHead->m_pNext;

	while (twoStep != NULL && twoStep->m_pNext != NULL) {
		oneStep = oneStep->m_pNext;
		twoStep = twoStep->m_pNext->m_pNext;
	}

	return oneStep;
}

bool isCircleList(ListNode* pListHead) {
	if (pListHead == NULL)
		return NULL;

	ListNode* oneStep = pListHead;
	ListNode* twoStep = pListHead->m_pNext;

	while (twoStep != NULL && twoStep->m_pNext != NULL) {
		if (twoStep == oneStep || twoStep->m_pNext == oneStep) {
			return true;
		}else{
			oneStep = oneStep->m_pNext;
			twoStep = twoStep->m_pNext->m_pNext;
		}
	}
	return false;
}



//int main(int argc, char** argv) {
//	ListNode head, node1, node2, node3, node4, tail;
//	tail.m_nValue = 6, tail.m_pNext = NULL;
//	node4.m_nValue = 5, node4.m_pNext = &tail;
//	node3.m_nValue = 4, node3.m_pNext = &node4;
//	node2.m_nValue = 3, node2.m_pNext = &node3;
//	node1.m_nValue = 2, node1.m_pNext = &node2;
//	head.m_nValue = 1, head.m_pNext = &node1;
//	tail.m_pNext = &head;
//
//	printf("%d ", isCircleList(&head));
//	system("pause");
//	return 0;
//	
//}

