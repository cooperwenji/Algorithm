#include<iostream>
#include<stdio.h>

#define LENGTH 4
bool find(int array_2d[][LENGTH], int rows, int columns, int target);

//int main(int argc, char** argv) {
//	int array_2d[LENGTH][LENGTH];
//	int target;
//	for (int i = 0; i < LENGTH; i++)
//		for (int j = 0; j < LENGTH; j++)
//			std::cin >> array_2d[i][j];
//
//	std::cin >> target;
//
//	if (!find(NULL, LENGTH, LENGTH, target)) {
//		printf("The number %d isn't in the array", target);
//	}
//	else {
//		printf("The number %d is in the array", target);
//	}
//	system("pause");
//	return 0;
//}

bool 
find(int array_2d[][LENGTH], int rows, int columns, int target) {
	int i = 0;       //ÐÐ
	int j = columns-1;    //ÁÐ

	if (array_2d != NULL && rows > 0 && columns > 0) {
		while (i <= rows - 1 && j >= 0) {
			if (array_2d[i][j] == target) {
				return true;
			}
			else if (array_2d[i][j] > target) {
				j--;
			}
			else {
				i++;
			}
		}
	}
	return false;
}