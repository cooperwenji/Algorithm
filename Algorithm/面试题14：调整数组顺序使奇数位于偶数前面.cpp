#include<iostream>
#include<vector>

// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序,
//使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分.
void ReOrderOddEven(int *pData, unsigned int length) {
	if (pData == NULL || length <= 0)
		return;

	int firstEven = 0;
	int lastOdd = length - 1;

	while (firstEven < lastOdd) {
		while ((pData[firstEven] & 0x1)&&firstEven<lastOdd)
			firstEven++;

		while (((pData[lastOdd] & 0x1) == 0) && firstEven<lastOdd)
			lastOdd--;

		if (firstEven < lastOdd) {
			int temp = pData[firstEven];
			pData[firstEven] = pData[lastOdd];
			pData[lastOdd] = temp;
		}
	}
}

// true为偶数， false为奇数
bool isEven(int num) {
	return (num & 0x1) == 0;
}

// 考虑扩展性，
void ReOrder(int *pData, unsigned int length, bool (*func)(int)) {
	if (pData == NULL || length <= 0)
		return;

	int firstEven = 0;
	int lastOdd = length - 1;

	while (firstEven < lastOdd) {
		while ( !func(pData[firstEven]) && firstEven < lastOdd)
			firstEven++;

		while ( func(pData[lastOdd]) && firstEven < lastOdd)
			lastOdd--;

		if (firstEven < lastOdd) {
			int temp = pData[firstEven];
			pData[firstEven] = pData[lastOdd];
			pData[lastOdd] = temp;
		}
	}
}

//与上面题目一样，多了条件：奇数、偶数之间的相对顺序保持不变。
void reOrderArray(std::vector<int> &array) {
	if (array.empty())
		return;

	int begin = 0;
	int second = begin + 1;
	int len = array.size();

	while (begin < len && second<len) {
		while (begin < len && !isEven(array[begin])) {
			begin++;
		}
		second = begin + 1;
		while (second < len && isEven(array[second])) {
			second++;
		}

		if (second < len) {
			int temp = array[second];
			for (int i = second-1; i >= begin; i--) {
				array[i + 1] = array[i];
			}
			array[begin] = temp;
		}
	}

}


//
//int main(int argc, char** argv) {
//	std::vector<int> a{ 1,2,3,4,5 };
//
//	reOrderArray(a);
//
//	for (int i = 0; i < a.size(); i++) {
//		printf("%d ", a[i]);
//	}
//	system("pause");
//	return 0;
//}

