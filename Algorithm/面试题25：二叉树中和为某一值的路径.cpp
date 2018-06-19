#include<iostream>
#include<vector>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

void FindPathImpl(TreeNode* root, int expectNumber, std::vector<int>& path, std::vector<std::vector<int>>& result) {
	if (root->left == NULL && root->right == NULL) {
		if (root->val == expectNumber) {
			path.push_back(root->val);
			result.push_back(path);
			path.pop_back();
			return;
		}else {
			return;
		}
	}

	path.push_back(root->val);
	int childExpectNumber = expectNumber - root->val;
	if (root->left != NULL)
		FindPathImpl(root->left, childExpectNumber, path, result);

	if (root->right != NULL)
		FindPathImpl(root->right, childExpectNumber, path, result);

	path.pop_back();
}

std::vector<std::vector<int>> FindPath(TreeNode* root, int expectNumber) {
	std::vector<std::vector<int>> result;
	if (root == NULL)
		return result;

	std::vector<int> path;
	FindPathImpl(root, expectNumber, path, result);

	return result;
}

//int main(int argc, char** argv){
//	TreeNode node10(10), node5(5), node4(4), node7(7), node12(12);
//	node10.left = &node5;
//	node10.right = &node12;
//	node5.left = &node4;
//	node5.right = &node7;
//
//	std::vector<std::vector<int>> result;
//	result = FindPath(&node10, 22);
//
//	for (int i = 0; i < result.size(); i++) {
//		std::vector<int>& path = result[i];
//		for (int j = 0; j < path.size(); j++){
//			printf("%d ", path[j]);
//		}
//		printf("\n");
//	}
//	
//	system("pause");
//	return 0;
//}