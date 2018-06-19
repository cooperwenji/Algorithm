#include<iostream>

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

void CloneNodes(RandomListNode* pHead) {
	RandomListNode* pNode = pHead;

	while (pNode != NULL) {
		RandomListNode* newNode = new RandomListNode(pNode->label);
		newNode->next = pNode->next;
		pNode->next = newNode;

		pNode = newNode->next;
	}
}

void CloneRandomNodes(RandomListNode* pHhead) {
	RandomListNode* pNode = pHhead;

	while (pNode != NULL) {
		if (pNode->random != NULL) {
			pNode->next->random = pNode->random->next;
		}
		pNode = pNode->next->next;
	}
}

RandomListNode* detatchCLoneList(RandomListNode* pHead) {
	RandomListNode* cloneListNode = NULL;
	RandomListNode* pNode = pHead;
	RandomListNode* cloneListHead = NULL;

	if (pNode != NULL) {
		cloneListHead = cloneListNode = pNode->next;
		pNode->next = cloneListNode->next;
		pNode = pNode->next;
	}
	while (pNode!= NULL) {
		cloneListNode->next = pNode->next;
		cloneListNode = cloneListNode->next;
		pNode->next = cloneListNode->next;
		pNode = pNode->next;
	}

	return cloneListHead;
}


RandomListNode* Clone(RandomListNode* pHead)
{
	 if (pHead == NULL)
		return NULL;

	CloneNodes(pHead);
	CloneRandomNodes(pHead);
	return detatchCLoneList(pHead);
}
//
//int main(int argc, char** argv) {
//	RandomListNode node1(1), node2(2), node3(3), node4(4), node5(5);
//	node1.next = &node2;
//	node2.next = &node3;
//	node3.next = &node4;
//	node4.next = &node5;
//
//	node1.random = &node3;
//	node2.random = &node5;
//	node4.random = &node2;
//
//	RandomListNode* newList = Clone(&node1);
//
//	printf("%d ", newList->label);
//	printf("%d ", newList->random->label);
//	printf("%d ", newList->random->next->label);
//	printf("%d ", newList->random->next->random->label);
//	printf("%d ", newList->random->next->random->random->label);
//	system("pause");
//	return 0;
//}