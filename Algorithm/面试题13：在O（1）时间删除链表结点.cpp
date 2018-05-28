#include<iostream>

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {
	if (pListHead == NULL || pToBeDeleted == NULL)
		return;

	if (pToBeDeleted->m_pNext != NULL) {
		ListNode* next = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = next->m_nValue;
		pToBeDeleted->m_pNext = next->m_pNext;

		delete next;
		next = NULL;
	}
	else if (pToBeDeleted == *pListHead) { //只有一个头结点
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	else {  
		ListNode* current = *pListHead;
		while (current->m_pNext != pToBeDeleted) {
			current = current->m_pNext;
		}
		current->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}
