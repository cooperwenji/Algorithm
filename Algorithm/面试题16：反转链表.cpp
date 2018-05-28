#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x, ListNode* n):val(x), next(n) {}
};

ListNode* ReverseList(ListNode* pHead) {
	if (pHead == NULL || pHead->next == NULL)
		return pHead;

	ListNode* previous = NULL;
	ListNode* current = pHead;
	ListNode* next;

	while (current != NULL) {
		next = current->next;
		if (current == pHead) {
			current->next = NULL;
			previous = pHead;
		}
		else {
			current->next = previous;
			previous = current;
		}
		current = next;
	}
	return previous;
}

//int main(int argc, char** argv) {
//	ListNode node4(4, NULL);
//	ListNode node3(3, &node4);
//	ListNode node2(2, &node3);
//	ListNode head(1, &node2);
//	
//	ListNode* result = ReverseList(NULL);
//
//	while (result != NULL) {
//		printf("%d ", result->val);
//		result = result->next;
//	}
//
//	system("pause");
//	return 0;
//}



