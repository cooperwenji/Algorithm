#include<iostream>
#include<vector>
#include<algorithm>

bool VerifySquenceOfBST(std::vector<int> sequence) {
	if (sequence.empty())
		return false;

	int root = sequence[sequence.size() - 1];
	int i = 0;
	for (; i < sequence.size()-1; i++)
		if (sequence[i] > root)
			break;

	int j = i;
	for (; j < sequence.size()-1; j++)
		if (sequence[j] < root)
			return false;

	bool left = true;
	if (i > 0) {
		std::vector<int> leftSequence;
		leftSequence.insert(leftSequence.begin(), sequence.begin(), sequence.begin() + i);

		//printf("leftSequence's length : %d \n", leftSequence.size());
		//for (int len = 0; len < leftSequence.size(); len++) {
		//	printf("%d ", leftSequence[len]);
		//}
		//printf("\n");

		left = VerifySquenceOfBST(leftSequence);
	}

	bool right = true;
	if (i<sequence.size()-1) {
		std::vector<int> rightSequence;
		rightSequence.insert(rightSequence.begin(), sequence.begin() + i, sequence.begin() + j);

		/*printf("RightSequence's length : %d \n", rightSequence.size());
		for (int len = 0; len < rightSequence.size(); len++) {
			printf("%d ", rightSequence[len]);
		}
		printf("\n");*/
		
		right = VerifySquenceOfBST(rightSequence);
	}

	return (left&&right);
}

//
//int main(int argc, char** argv) {
//	std::vector<int> testData = { 5,7,6,9,11,10,8 };
//	bool resutlt = VerifySquenceOfBST(testData);
//
//	printf("result: %d", resutlt);
//	system("pause");
//	return 0;
//}