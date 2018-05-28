#include<iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

void Mirror(TreeNode *pRoot) {
	if (pRoot == NULL || (pRoot->left == NULL&&pRoot->right == NULL))
		return;

	TreeNode* temp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = temp;

	if (pRoot->left) Mirror(pRoot->left);
	if (pRoot->right) Mirror(pRoot->right);
}



