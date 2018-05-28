#include<iostream>

int  NumberOf1(int n) {
	int count = 0;
	while (n) {
		if (n & 1)
			count++;
		n = n >> 1;
	}
	return count;
}

int  NumberOf2(int n) {
	int count = 0;

	unsigned int flag = 1;
	while(flag){
		if (n&flag) {
			count++;
		}
		flag = flag << 1;
	}
	return count;
}

int  NumberOf3(int n) {
	int count = 0;
	while (n) {
		count++;
		n = n&(n - 1);
	}
	return count;
}

bool IntPower(int n) {
	return ((n&(n - 1))==0)&&(n!=0);
}

int countChange(int m, int n) {
	int temp = m^n;
	int count = 0;

	while (temp) {
		temp = temp&(temp - 1);
		count++;
	}

	return count;
}

//int main(int argc, char** argv) {
//	printf("%d ", countChange(13, 10));
//	system("pause");
//	return 0;
//}
