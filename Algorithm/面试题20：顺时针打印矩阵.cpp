#include<iostream>
#include<vector>
using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
	int top, bottom, left, right;
	top = left = 0;
	right = matrix[0].size() - 1;
	bottom = matrix.size() - 1;

	vector<int> result;

	while (left <= right && bottom >= top) {
		for (int i = left; i <= right; i++) {
			printf("%d ", matrix[top][i]);
			result.push_back(matrix[top][i]);
		}
			
		top++;
		if (top > bottom) break;

		for (int j = top; j <= bottom; j++) {
			printf("%d ", matrix[j][right]);
			result.push_back(matrix[j][right]);
		}
		right--;
		if (right < left) break;

		for (int i = right; i >= left; i--) {
			printf("%d ", matrix[bottom][i]);
			result.push_back(matrix[bottom][i]);
		}
		bottom--;
		if(bottom<top) break;

		for (int j = bottom; j >= top; j--) {
			printf("%d ", matrix[j][left]);
			result.push_back(matrix[j][left]);
		}
		left++;
		if (left > right) break;
	}

	return result;
}

//int main(int argc, char** argv) {
//	vector<vector<int>> matrix;
//	vector<int> result;
//
//	matrix.resize(4);
//	for (int i = 0; i < 4; i++) {
//		matrix[i].resize(4);
//	}
//	int count = 1;
//	for (int i = 0; i < 4; i++)
//		for (int j = 0; j < 4; j++)
//			matrix[i][j] = count++;
//
//	vector<vector<int>> matrix2;
//
//	result = printMatrix(matrix);
//
//	//for (int i = 0; i < 4; i++)
//	//	for (int j = 0; j < 4; j++)
//	//		printf("%d ", matrix[i][j]);
//
//	system("pause");
//	return 0;
//}
