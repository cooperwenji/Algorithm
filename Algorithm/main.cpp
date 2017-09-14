#include<iostream>
#include<stdio.h>
#include<time.h>

#define LOCAL
#define INF 1000000000
using namespace std;

void fun_2_2()  //存在乘法溢出的问题。
{
	int n, count = 0;
	scanf_s("%d", &n);

	while (n > 1)
	{
		if (n % 2 == 1)
			n = 3 * n + 1;
		else
			n /= 2;

		count++;
	}

	printf("%d\n", count);
	//printf("%d", INT_MAX);
}  

void fun_2_3()
{
	//取余操作对加法、减法和乘法的结果没有影响。
	int n, sum = 0;
	scanf_s("%d", &n);
	clock_t start, finish;
	start = clock();
	for (int i = 1; i <= n; i++)
	{
		int factorial = 1;
		for (int j = 1; j <= i; j++)
		{
			factorial *= j;
		}
		sum += factorial;
	}

	finish = clock();
	printf("%d\n", sum % 1000000);
	printf("Time used = %.2lf\n", (double)(finish - start) / CLOCKS_PER_SEC);
}

void fun_2_3_separate_remain()
{
	//取余操作对加法、减法和乘法的结果没有影响。
	const int MOD = 1000000;
	int n, sum = 0;
	clock_t start, finish;

	scanf_s("%d", &n);

	start = clock();
	for (int i = 1; i <= n; i++)
	{
		int factorial = 1;
		for (int j = 1; j <= i; j++)
		{
			factorial = (factorial*j) % MOD;
		}
		sum = (sum + factorial) % MOD;
	}
	printf("%d\n", sum);

	finish = clock();
	printf("Time used = %.2lf\n", (double)(finish - start) / CLOCKS_PER_SEC);
}

void fun_2_8()
{
	FILE *instream, *outstream;
#ifdef LOCAL
	freopen_s(&instream,"data.in.txt", "r", stdin);   //重定向标准输入输出;
    freopen_s(&outstream,"data.out.txt", "w", stdout);
	
#endif // LOCAL
	int a, sum = 0, max = -INF, min = INF, n = 0;

	while (scanf_s("%d", &a) == 1)
	{
		if (a > max)
			max = a;
		else if (a < min)
			min = a;
		
		sum += a;
		//printf("a = %d, min = %d, max = %d", a, min, max);  
		n++;
	}
	printf("%d %d %.3lf\n", min, max, ((double)sum) / n);
}


void main()
{
	fun_2_8();
	system("pause");
}