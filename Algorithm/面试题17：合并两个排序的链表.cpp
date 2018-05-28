#include<iostream>
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x, ListNode* n) :val(x), next(n) {}
};

ListNode* Merge_iteratively(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;

	ListNode* newHead = NULL;
	ListNode* newPointer = NULL;
	if (pHead1->val < pHead2->val) {
		newHead = pHead1;
		pHead1 = pHead1->next;
	}
	else {
		newHead = pHead2;
		pHead2 = pHead2->next;
	}
	newPointer = newHead;

	while (pHead1 != NULL || pHead2 != NULL) {
		if (pHead1 == NULL) {
			newPointer->next = pHead2;
			break;
		}else if (pHead2 == NULL) {
			newPointer->next = pHead1;
			break;
		}

		//先处理一般情况：
		if (pHead1->val < pHead2->val) {
			newPointer->next = pHead1;
			pHead1 = pHead1->next;
		}
		else {
			newPointer->next = pHead2;
			pHead2 = pHead2->next;
		}
		newPointer = newPointer->next;
	}

	return newHead;
}

ListNode* Merge_recursively(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;

	ListNode* mergeHead = NULL;
	if (pHead1->val < pHead2->val) {
		mergeHead = pHead1;
		mergeHead->next = Merge_recursively(pHead1->next, pHead2);
	}
	else {
		mergeHead = pHead2;
		mergeHead->next = Merge_recursively(pHead1, pHead2->next);
	}
	return mergeHead;
}

//int main(int argc, char** argv) {
//	ListNode node7(7, NULL);
//	ListNode node5(5, &node7);
//	ListNode node3(3, &node5);
//	ListNode head1(1, &node3);
//
//	ListNode node8(8, NULL);
//	ListNode node6(6, &node8);
//	ListNode node4(4, &node6);
//	ListNode head2(2, &node4);
//
//	ListNode* mergeList = Merge_recursively(&head1, &head2);
//
//	while (mergeList != NULL) {
//		printf("%d ", mergeList->val);
//		mergeList = mergeList->next;
//	}
//
//	system("pause");
//	return 0;
//
//}

