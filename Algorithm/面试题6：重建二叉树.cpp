#include<iostream>

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;

	BinaryTreeNode(int value, BinaryTreeNode* left, BinaryTreeNode* right) :m_nValue(value), m_pLeft(left), m_pRight(right) {}
};

BinaryTreeNode* construct(int* preorder, int* inorder, int length);
BinaryTreeNode* constructCore(int* StartPreorder, int* EndPreorder, int* StartInorder, int* EndInorder);

void preorder_recursive1(BinaryTreeNode* current);

//int main(int argc, char** argv) {
//	int preorder[] = { 1,2,4,7,3,5,6,8 };
//	int indorder[] = { 4,7,2,1,5,3,8,6 };
//
//	BinaryTreeNode* head= construct(preorder, indorder, sizeof(preorder) / sizeof(int));
//
//	preorder_recursive1(head);
//
//	system("pause");
//	return 0;
//
//}


BinaryTreeNode* 
construct(int* preorder, int* inorder, int length) {
	if (preorder == NULL || inorder == NULL || length <= 0) {
		return NULL;
	 }

	return constructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}
BinaryTreeNode* 
constructCore(int* StartPreorder, int* EndPreorder, int* StartInorder, int* EndInorder) {
	
	int rootValue = StartPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode(rootValue, NULL, NULL);

	if (StartPreorder == EndPreorder) {
		if (StartInorder == EndInorder&& *StartPreorder == *StartInorder)
			return root;
		else {
			throw std::exception("Invalid input");
		}
	}

	//在中序遍历中找到根节点的值
	int left_len = 0;
	int* current = StartInorder;
	while (*current != rootValue && current<=EndInorder) {
		current++;
	}

	if (current == EndInorder&& *current != rootValue)
		throw std::exception("Invalid input");

	int leftLength = current - StartInorder;
	int* leftPreorderEnd = StartPreorder + leftLength;
	if (leftLength > 0) {  //构建左子树
		root->m_pLeft = constructCore(StartPreorder + 1, leftPreorderEnd, StartInorder, current - 1);
	}
	if (left_len < EndPreorder - StartPreorder) {  //构建右子树
		root->m_pRight = constructCore(leftPreorderEnd + 1, EndPreorder, current+1, EndInorder);
	}
	return root;

}

void
preorder_recursive1(BinaryTreeNode* current) {
	if (current == NULL)
		return;

	printf("%d ", current->m_nValue);
	preorder_recursive1(current->m_pLeft);
	preorder_recursive1(current->m_pRight);
}