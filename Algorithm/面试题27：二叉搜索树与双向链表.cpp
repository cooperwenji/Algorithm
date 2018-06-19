#include<iostream>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

void ConvertToList(TreeNode* pRootOfTree, TreeNode** pLastNodeInList) {
	if (pRootOfTree == NULL)
		return;

	TreeNode* pCurrent = pRootOfTree;

	if (pCurrent->left != NULL)
		ConvertToList(pCurrent->left, pLastNodeInList);

	pCurrent->left = *pLastNodeInList;
	if (*pLastNodeInList != NULL)
		(*pLastNodeInList)->right = pCurrent;

	*pLastNodeInList = pCurrent;

	if (pCurrent->right != NULL)
		ConvertToList(pCurrent->right, pLastNodeInList);
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	TreeNode* pLastNodeInList = NULL;
	ConvertToList(pRootOfTree, &pLastNodeInList);

	TreeNode* pHeadNodeInList = pLastNodeInList;
	while (pHeadNodeInList != NULL&&pHeadNodeInList->left != NULL)
		pHeadNodeInList = pHeadNodeInList->left;

	return pHeadNodeInList;

}