#include<iostream>
#include<stack>

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;

	BinaryTreeNode(int value, BinaryTreeNode* left, BinaryTreeNode* right):m_nValue(value),m_pLeft(left),m_pRight(right){}
};

// recursive 
void preorder_recursive(BinaryTreeNode* current);
void inorder_recursive(BinaryTreeNode* current);
void postorder_recursive(BinaryTreeNode* current);

// non-recursive
void preorder_iterative(BinaryTreeNode* current);
void inorder_iterative(BinaryTreeNode* current);
void postorder_iterative(BinaryTreeNode* current);

//
//int main(int argc, char** argv) {
//	BinaryTreeNode l1(4, NULL, NULL);
//	BinaryTreeNode l2(8, NULL, NULL), l3(12, NULL, NULL), l4(16, NULL, NULL);
//	BinaryTreeNode l5(6, &l1, &l2), l6(14, &l3, &l4);
//	BinaryTreeNode head(10, &l5, &l6);
//
//	inorder_iterative(&head);
//	system("pause");
//	return 0;
//}

void
preorder_recursive(BinaryTreeNode* current) {
	if (current == NULL)
		return;

	printf("%d ", current->m_nValue);
	preorder_recursive(current->m_pLeft);
	preorder_recursive(current->m_pRight);
}

void 
inorder_recursive(BinaryTreeNode* current) {
	if (current == NULL)
		return;

	inorder_recursive(current->m_pLeft);
	printf("%d ", current->m_nValue);
	inorder_recursive(current->m_pRight);
}

void 
postorder_recursive(BinaryTreeNode* current) {
	if (current == NULL)
		return;

	postorder_recursive(current->m_pLeft);
	postorder_recursive(current->m_pRight);
	printf("%d ", current->m_nValue);
}

void
preorder_iterative(BinaryTreeNode* current) {
	std::stack<BinaryTreeNode*> tree_stack;
	while (current != NULL || !tree_stack.empty()) {
		if (current != NULL) { //结点不为空，将结点压入栈，并指向其左子结点，
			printf("%d ", current->m_nValue);
			tree_stack.push(current);
			current = current->m_pLeft;
		}
		else { //结点为空的情况，就去处理栈顶的结点
			current = tree_stack.top();
			tree_stack.pop();
			current = current->m_pRight;
		}
	}
}

void
inorder_iterative(BinaryTreeNode* current) {
	std::stack<BinaryTreeNode*> tree_stack;
	while (current != NULL || !tree_stack.empty()) {
		if (current != NULL) {
			tree_stack.push(current);
			current = current->m_pLeft;
		}
		else {
			current = tree_stack.top();
			tree_stack.pop();
			printf("%d ", current->m_nValue);
			current = current->m_pRight;
		}
	}
}

void
postorder_iterative(BinaryTreeNode* head) {

}