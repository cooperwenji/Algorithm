#include<iostream>

int Min(int* numbers, int length);
int minFind(int* numbers, int first, int last);

//int main(int argc, char** argv) {
//	int numbers[] = { 3,4,5,1,2 };
//	printf("%d ", Min(numbers, sizeof(numbers) / sizeof(int)));
//
//	system("pause");
//	return 0;
//}

int
Min(int* numbers, int length) {
	if (numbers == NULL || length <= 0)
		throw new std::exception("input is incorrect!");

	int first = 0;
	int last = length - 1;
	int indexMid = first;  //

	while (numbers[first] >= numbers[last]) {

		indexMid = (first + last) / 2;
		
        if (last - first == 1) {
			indexMid = last;
			break;
		}

		if (numbers[first] == numbers[last] && numbers[indexMid] == numbers[first])
			return minFind(numbers, first, last);

		if (numbers[indexMid] >= numbers[first])
			first = indexMid;
		else if (numbers[indexMid] <= numbers[last])
			last = indexMid;
	}

	return numbers[indexMid];
}

int 
minFind(int* numbers, int first, int last) {
	int temp = numbers[first];

	for (int i = first; i <= last; i++) {
		if (numbers[i] < temp)
			temp = numbers[i];
	}
	return temp;
}