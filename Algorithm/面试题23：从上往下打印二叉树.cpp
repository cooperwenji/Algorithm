#include<iostream>
#include<vector>
#include<queue>
#include<stdlib>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

std::vector<int> PrintFromTopToBottom(TreeNode* root) {
	if (root == NULL)
		return std::vector<int>();

	std::vector<int> result;
	std::queue<TreeNode> printQueue;
	printQueue.push(*root);

	TreeNode* current = NULL;

	while (!printQueue.empty()) {
		current = &(printQueue.front());
		printQueue.pop();
		result.push_back(current->val);
		if (current->left != NULL) printQueue.push(*(current->left));
		if (current->right != NULL) printQueue.push(*(current->right));
	}
	return result;
}
