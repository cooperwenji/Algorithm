#include<iostream>
#include<vector>
#include<time.h>
#include<exception>

int randomIndex(int left, int right) {
	srand((int)time(NULL));
	return rand() % (right - left + 1);
}

void swap(std::vector<int>& numbers, int aIndex, int bIndex) {
	int temp = numbers[aIndex];
	numbers[aIndex] = numbers[bIndex];
	numbers[bIndex] = temp;
}

int Partition(std::vector<int>& data, int left, int right) {
	if (data.empty() || left < 0 || right >= data.size())
		throw new std::exception("Invalid Parameters");

	int index = randomIndex(left, right);
	swap(data, index, right);

	int small = left - 1;
	for (index = left; index < right; index++) {
		if (data[index] < data[right]) {
			small++;
			if (small != index)
				swap(data, small, index);
		}
	}
	swap(data, ++small, right);

	return small;
}

bool CheckMoreThanHalf(std::vector<int>&numbers, int number) {
	int halfNum = numbers.size() >> 1;
	int count = 0;


	std::vector<int>::iterator itr = numbers.begin();
	for (; itr != numbers.end(); itr++) {
		if (*itr == number)
			count++;
		if (count > halfNum)
			return true;
	}
	return false;
}

int MoreThanHalfNum_Solution(std::vector<int> numbers) {
	if (numbers.empty())
		throw new std::exception("empty input array!");

	int length = numbers.size();
	
	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = Partition(numbers, start, end);
	while (index != middle) {
		if (index < middle) {
			start = index + 1;
			index = Partition(numbers, start, end);
		}
		else {
			end = index - 1;
			index = Partition(numbers, start, end);
		}
	}

	int result = numbers[middle];
	if (!CheckMoreThanHalf(numbers, result))
		result = 0;
	return result;
}

int MoreThanHalfNum_Solution2(std::vector<int> numbers) {
	if (numbers.empty())
		return 0;

	int result = numbers[0];
	int count = 1;
	for (int i = 1; i < numbers.size(); i++) {
		if (count == 0) {
			result = numbers[i];
			count = 1;
		}
		else if (result == numbers[i])
			count++;
		else
			count--;
	}

	if (!CheckMoreThanHalf(numbers, result))
		result = 0;
	return result;
}

//int main(int argc, char** argv) {
//	std::vector<int> test{ 4,2,1,4,2,4 };
//
//	int result = MoreThanHalfNum_Solution(test);
//	printf("result: %d", result);
//
//	system("pause");
//	return 0;
//}

