#include<iostream>
#include<vector>
#include<time.h>
#include<algorithm>
#include<functional>
#include<set>

int randomIndex_1(int left, int right) {
	srand((unsigned int)time(NULL));
	return rand() % (right - left + 1);
}

void swap_1(std::vector<int>&data, int aIndex, int bIndex) {
	int temp = data[aIndex];
	data[aIndex] = data[bIndex];
	data[bIndex] = temp;
}

int Partition_1(std::vector<int>& data, int left, int right) {
	if (data.empty() || left < 0 || right >= data.size())
		return -1;

	int index = randomIndex_1(left, right);
	swap_1(data, index, right);

	int small = left - 1;
	for (index = left; index < right; index++) {
		if (data[index] < data[right]) {
			small++;
			if (small != index)
				swap_1(data, small, index);
		}
	}
	swap_1(data, ++small, right);
 
	return small;
}

std::vector<int> GetLeastNumbers_Solution(std::vector<int> input, int k) {
	std::vector<int> result;
	if (input.empty() || input.size()<k)
		return result;

	int start = 0;
	int end = input.size() - 1;
	int index = Partition_1(input, start, end);
	while (index != k - 1) {
		if (index < k - 1) {
			start = index + 1;
			if(start>end) break;
			index = Partition_1(input, start, end);
		}
		else {
			end = index - 1;
			if (start > end) break;
			index = Partition_1(input, start, end);
		}
	}
	result.resize(k);
	std::copy(input.begin(), input.begin() + k, result.begin());
	return result;
}

typedef std::multiset<int, std::greater<int>> intSet;
typedef std::multiset<int, std::greater<int>>::iterator SetIterator;
std::vector<int> GetLeastNumbers_Solution2(std::vector<int> input, int k) {
	std::vector<int> result;
	if (input.empty() || input.size() < k)
		return result;

	int length = input.size();
	intSet kSet;
	kSet.clear();

	std::vector<int>::const_iterator itr = input.begin();
	for (; itr != input.end(); itr++) {
		if (kSet.size() < k) {
			kSet.insert(*itr);
		}
		else {
			SetIterator setItr = kSet.begin();
			if ((*itr) < (*setItr)) {
				kSet.erase(setItr);
				kSet.insert(*itr);
			}
		}
	}

	result.resize(k);
	std::copy(kSet.begin(), kSet.end(), result.begin());
	return result;
}

//int main(int argc, char** argv) {
//	std::vector<int> test{ 4,5,1,6,2,7,3,8 };
//	int k = 4;
//
//	std::vector<int> result;
//
//	result = GetLeastNumbers_Solution2(test, k);
//
//	std::vector<int>::iterator itr = result.begin();
//	for (; itr != result.end(); itr++) {
//		printf("%d ", *itr);
//	}
//	system("pause");
//	return 0;
//}