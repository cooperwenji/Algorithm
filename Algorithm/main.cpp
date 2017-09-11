#include<iostream>
#include<stdio.h>

using namespace std;

void main()
{
	int n, count = 0;
	scanf_s("%d", &n, 1);

	while (n > 1)
	{
		if (n % 2 == 1)
			n = 3 * n + 1;
		else
			n /= 2;

		count++;
	}

	printf("%d\n", count);
	printf("%d", INT_MAX);
	system("pause");
}