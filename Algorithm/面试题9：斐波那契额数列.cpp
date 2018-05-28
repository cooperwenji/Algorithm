#include<iostream>
#include<math.h>

long long fibonacci_recursive(unsigned int n);

long long fibonacci_iterative(unsigned int n);

int jumpFloorII(int number);
//
//int main(int argc, char** argv) {
//	int temp1 = fibonacci_recursive(10);
//	int temp2 = fibonacci_iterative(10);
//
//	printf("%d \n%d", temp1, temp2);
//	system("pause");
//	return 0;
//}

long long
fibonacci_recursive(unsigned int n) {
	if (n <= 0)
		return 0;

	if (n == 1)
		return 1;

	return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

long long
fibonacci_iterative(unsigned int n) {
	long long fib0 = 0;
	long long fib1 = 1;
	long long fibN = 0;

	if (n <= 0)
		return fib0;
	else if (n == 1)
		return fib1;
	
	for (int i = 2; i <= n; i++) {
		fibN = fib1 + fib0;
		fib0 = fib1;
		fib1 = fibN;
	}
	return fibN;
}

int jumpFloor(int number) {   //青蛙跳台阶
	if (number == 1 || number == 2)
		return number;

	int f1 = 1;
	int f2 = 2;
	int fn = 0;

	for (int i = 3; i <= number; i++) {
		fn = f1 + f2;
		f1 = f2;
		f2 = fn;
	}
	return fn;
}

int jumpFloorII(int number) {  //变态台阶
	if (number <= 0)
		return number;

	return pow(2, number - 1);
}

int rectCover(int number) {   //小矩形覆盖
	if (number <= 0)
		return 0;

	if (number == 1 || number == 2)
		return number;

	int f1 = 1;
	int f2 = 2;
	int fn = 0;

	for (int i = 3; i <= number; i++) {
		fn = f1 + f2;
		f1 = f2;
		f2 = fn;
	}
	return fn;
}

