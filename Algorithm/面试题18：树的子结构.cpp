#include <iostream>
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

void preorder_recursive(TreeNode* current) {
	if (current == NULL)
		return;

	printf("%d ", current->val);
	preorder_recursive(current->left);
	preorder_recursive(current->right);
}

bool DoesTree1HadTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
	if (!pRoot2)
		return true;

	if (!pRoot1)
		return false;

	if (pRoot1->val != pRoot2->val)
		return false;

	return DoesTree1HadTree2(pRoot1->left, pRoot2->left) && DoesTree1HadTree2(pRoot1->right, pRoot2->right);
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	bool result = false;

	if(pRoot1 != NULL&& pRoot2 != NULL) {
		if (pRoot1->val == pRoot2->val) {
			result = DoesTree1HadTree2(pRoot1, pRoot2);
		}
		if (!result)
			result = HasSubtree(pRoot1->left, pRoot2);
		if (!result)
			result = HasSubtree(pRoot1->right, pRoot2);
	}

	return result;
}

//
//int main(int argc, char** argv) {
//	TreeNode* treeA = new TreeNode(8);
//	TreeNode* tree8 = new TreeNode(8);
//	TreeNode* tree7 = new TreeNode(7);
//	TreeNode* tree9 = new TreeNode(9);
//	TreeNode* tree2 = new TreeNode(2);
//	TreeNode* tree4 = new TreeNode(4);
//	TreeNode* tree71 = new TreeNode(7);
//	treeA->left = tree8;
//	treeA->right = tree7;
//	tree8->left = tree9;
//	tree8->right = tree2;
//	tree2->left = tree4;
//	tree2->right = tree71;
//
//	TreeNode* treeB = new TreeNode(8);
//	TreeNode* treeB9 = new TreeNode(9);
//	TreeNode* treeB2 = new TreeNode(2);
//	treeB->left = treeB9;
//	treeB->right = treeB2;
//
//
//
//	bool result = HasSubtree(treeA, treeB);
//	printf("%d ", result);
//
//	system("pause");
//	return 0;
//}

