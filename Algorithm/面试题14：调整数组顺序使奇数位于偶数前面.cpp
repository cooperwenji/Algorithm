#include<iostream>
#include<vector>

// ��Ŀ������һ���������飬ʵ��һ�����������������������ֵ�˳��,
//ʹ����������λ�������ǰ�벿�֣�����ż��λ������ĺ�벿��.
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

// trueΪż���� falseΪ����
bool isEven(int num) {
	return (num & 0x1) == 0;
}

// ������չ�ԣ�
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

//��������Ŀһ��������������������ż��֮������˳�򱣳ֲ��䡣
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

