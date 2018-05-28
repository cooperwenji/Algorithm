#include<iostream>
#include<memory.h>

bool Increment(char* ditgits, int length) {
	bool Maxflag = false;
	int nSum;
	int takeOver = 0;

	for (int i = length - 1; i >= 0; i--) {
		nSum = ditgits[i] - '0' + takeOver;
		if (i == length - 1)
			nSum++;

		if (nSum >= 10) {
			if (i == 0) {
				Maxflag = true;
			}
			else {
				takeOver = 1;
				nSum -= 10;
				ditgits[i] = nSum + '0';
			}
		}
		else {
			ditgits[i] = nSum + '0';
			takeOver = 0;
			break;
		}
	}
	return Maxflag;
}

void PrintDigits(char* ditgits, int length) {
	bool firstNumber1 = false;
	for (int i = 0; i < length; i++) {
		if (ditgits[i] != '0' && !firstNumber1) {
			firstNumber1 = true;
		}
		if (firstNumber1) {
			printf("%c", ditgits[i]);
		}
	}
	printf(" ");
}

void print1ToMaxDigits(int n) {
	if (n <= 0)
		return;

	char* ditgits = new char[n + 1];
	memset(ditgits, '0', n);
	ditgits[n] = '\0';

	while (!Increment(ditgits, n)) {
		PrintDigits(ditgits, n);
	}

	delete[] ditgits;
	return;
}

void print1ToMaxDitgits_Recursive(char* numbers, int length, int index) {
	if (index == length - 1) {
		PrintDigits(numbers, length);
		return;
	}

	for (int i = 0; i <= 9; i++) {
		numbers[index + 1] = i + '0';
		print1ToMaxDitgits_Recursive(numbers, length, index + 1);
	}
}

void print1ToMaxDitgits_Recursively(int n) {
	if (n <= 0)
		return;

	char* numbers = new char[n + 1];
	memset(numbers, '0', n);
	numbers[n] = '\0';

	for (int i = 0; i <= 9; i++) {
		numbers[0] = i + '0';
		print1ToMaxDitgits_Recursive(numbers, n, 0);
	}

	delete[] numbers;
}

//void BigNumberAdd(char* num1, char* num2, char* result) {
//	if (num1 == NULL && num2 == NULL)
//		return;
//
//	if (num1 == NULL) {
//		//resultָ��num2��
//		//return ����;
//	}
//	else if (num2 == NULL) {
//		//resultָ��num1;
//		//return ����;
//	}
//
//	//����num1��num2����Ϊ�յ����
//	bool PositiveFlag = true;
//	int len1 = strlen(num1);
//	int len2 = strlen(num2);
//	int len;
//
//	//�����鳤�ķ���num1, ����̵ķ���num2
//	if(num1[0]=='-'&&(len1-1)<len2)
//
//	if (num1[0] == '-'&&num2=='-') {
//		PositiveFlag = false;
//		len = (len1 > len2 ? len1 : len2)+1;
//	}
//	else if (num1[0] != '-'&&num2 != '-') {
//		len = len1 > len2 ? len1 : len2;
//	}
//	else { //һ��һ�������
//		if (num1[0] == '-' && (len1 - 1) > len2)
//			PositiveFlag = false;
//	}
//
//
//	
//
//
//}


//int main(int argc, char** argv) {
//
//
//	system("pause");
//	return 0;
//}
