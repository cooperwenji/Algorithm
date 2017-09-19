#include<iostream>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

#define LOCAL
#define INF 1000000000
#define MAXN 1000 + 10
#define HUNDRED 100 + 10
#define MAX 10
#define LONGEST 5000 + 10

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

void fun_2_9()
{
	double i;
	for (i = 0; i != 10; i += 0.1)
		printf("%.3lf\n", i);
}

int ice[MAXN];
//开灯问题
void fun_3_1()  
{
	int n, k;
	int first = 1;
	scanf_s("%d%d", &n, &k);
	if (k > n || n > 1000)
	{
		printf("The k is larger than n");
		return;
	}

	memset(ice, 0, n + 1);
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; i*j <= n; j++)
		{
			if (ice[i*j] == 0)
				ice[i*j] = 1;
			else
				ice[i*j] = 0;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (ice[i])
		{
			if (first)	first = 0;
			else
				printf(" ");
			printf("%d", i);
		}
	}
}

int snake[MAX][MAX];
//蛇形填数
void fun_3_3()   
{
	memset(snake, 0, sizeof(snake));
	int n, x, y;
	scanf_s("%d", &n);
	int value = 1;

	snake[x = 0][y = n - 1] = value;
	while (value < n*n)
	{
		while (x+1 < n && snake[x+1][y] == 0) { snake[++x][y] = ++value; }
		while (y - 1 >= 0 && snake[x][y - 1] == 0) { snake[x][--y] = ++value; }
		while (x - 1 >= 0 && snake[x - 1][y] == 0) { snake[--x][y] = ++value; }
		while (y + 1 < n && snake[x][y + 1] == 0) { snake[x][++y] = ++value; }
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", snake[i][j]);
		}
		printf("\n");
	}
}

//竖式问题
void fun_3_4()  
{
	char s[20], buf[99];
	int abc, de, x, y, z, ok;
	int count = 0;
	scanf_s("%s", s, 10);

	for (abc = 111; abc <= 999; abc++)
	{
		for (de = 11; de <= 99; de++)
		{
			x = abc * (de % 10);
			y = abc * (de / 10);
			z = abc * de;
			sprintf_s(buf, "%d%d%d%d%d", abc, de, x, y, z);
			ok = 1;
			for (int i = 0; i < strlen(buf); i++)
			{
				if (strchr(s, buf[i]) == NULL)
					ok = 0;
			}
			if (ok)
			{
				printf("<%d>\n", count);
				printf("%5d\nX%4d\n-------\n%5d\n%-4d\n-------\n%5d\n", abc, de, x, y, z);
				count++;
			}
			
		}
	}
	printf("The number of solutions = %d\n", count);
}

char buf[LONGEST];
char s[LONGEST];
char p[LONGEST];
//最长回文字符串
void fun_3_5()  
{
	fgets(buf, sizeof(s), stdin);
	int buf_len = strlen(buf);
	int m = 0;
	for (int i = 0; i < buf_len; i++)
	{
		if (isalpha(buf[i]))
		{
			p[m] = i;
			s[m++] = toupper(buf[i]);
		}
	}

	int max = -1;
	int x, y;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; i - j >= 0 && i + j < m; j++)
		{
			if (s[i - j] != s[i + j]) break;
			if (2 * j + 1 > max)
			{
				max = 2 * j + 1;
				x = p[i - j];
				y = p[i + j];
			}
		}
		for (int j = 0; i - j >= 0 && i + j + 1 < m; j++)
		{
			if (s[i - j] != s[i + j + 1]) break;
			if (2 * j + 2 > max)
			{
				max = 2 * j + 1;
				x = p[i - j];
				y = p[i + j + 1];
			}
		}
	}

	for (int i = x; i <= y; i++)
	{
		printf("%c", buf[i]);
	}
	

}

int score[MAXN];
int count[MAX];
//分数统计
void practice_3_1()   
{
	int num, m = 0,  max = -1;
	memset(score, 0, sizeof(score));
	memset(::count, 0, sizeof(::count));
	while (scanf_s("%d", &num) == 1)
	{
		score[num]++;
	}
	for (int i = 0; i <= 100; i++)
	{
		if (score[i] > max)
		{
			max = score[i];
			::count[m = 0] = i;
		}
		else if (score[i] == max)
		{
			::count[++m] = i;
		}
	}

	for (int i = 0; i <= m; i++)
	{
		printf("the maximun number showing in the list is %d\n", ::count[i]);
	}
}

char word[MAXN];
//单词的长度
void practice_3_2()  
{
	int m = 0, count = 0, sum = 0;
	bool flag = false;
	char c;
	while (1)
	{
		scanf_s("%c", &c, 1);
		if (c == '\n' || c == EOF)
			break;
		word[m++] = c;
	}
	
	for (int i = 0; i < m; i++)
	{
		if (isalpha(word[i]))
		{
			sum++;
			flag = true;
		}
		else
		{
			if (flag)
			{
				count++;
				flag = false;
			}
		}
	}
	if (flag)
		count++;

	printf("%d\n%d\n%.3f\n", sum, count, (sum*1.0) / count);

}

//乘积的末3位
char product[HUNDRED];
void practice_3_3()
{
	int num, flag, sum = 1;
	while (1)
	{
		flag = scanf_s("%d", &num);
		if (flag == EOF) break;
		if (flag == 1)
		{
			sum *= num % 1000;
		}
		else
		{
			scanf_s("%s", product, HUNDRED-1);
		}
	}

	printf("%.3d", sum);
}

//计算器
char calculator[HUNDRED];
void practice_3_4()
{
	//method 1
	/*int middle;
	fgets(calculator, HUNDRED - 1, stdin);

	for (int i = 0; i < strlen(calculator); i++)
	{
		if (calculator[i] == '+' || calculator[i] == '-' || calculator[i] == '*')
		{
			middle = i;
			break;
		}
	}

	int num_1 = 0;
	for (int i = 0; i < middle; i++)
	{
		if (calculator[i] == ' ')
			continue;
		num_1 = num_1 * 10 + calculator[i] - '0';
	}

	int num_2 = 0;
	for (int i = middle + 1; i < strlen(calculator) - 1; i++)
	{
		if (calculator[i] == ' ')
			continue;
		num_2 = num_2 * 10 + calculator[i] - '0';
	}

	int result;
	switch (calculator[middle])
	{
	case '-':result = num_1 - num_2; break;
	case '+':result = num_1 + num_2; break;
	case '*':result = num_1 * num_2; break;
	default:break;
	}

	printf("%d", result);*/


	//method 2
	int a, b, result;
	char operator_o;
	scanf_s("%d", &a);
	scanf_s("%c", &operator_o,1);
	while (operator_o == ' ')
		scanf_s("%c", &operator_o,1);
	scanf_s("%d", &b);

	switch (operator_o)
	{
	case '-':result = a - b; break;
	case '+':result = a + b; break;
	case '*':result = a*b; break;
	default:break;
	}
	printf("%d", result);
}

//旋转
char rotate[HUNDRED][HUNDRED];
char result[MAX][MAX];
void practice_3_5()
{
	//method 1
	int flag = 0, count = HUNDRED;
	char member;
	for (int i = 0; i < HUNDRED; i++)
	{
		if (i == count) break;
		count = 0;
		for (int j = 0; j < HUNDRED; j++)
		{
			scanf_s("%c", &member);
			if (member == ' ')
				continue;
			else if (member >= 'a'&&member <= 'z')
			{
				::rotate[i][count++] = member;	
			}
			else if (member == '\n')
			{
				break;
			}
		}
	}

	for (int j = count -1; j >= 0; j--)
	{
		for (int i = 0; i < count; i++)
			printf("%c ", ::rotate[i][j]);
		printf("\n");
	}
}

//进制转换1
char base1[HUNDRED];
void practice_3_6()
{
	int out, m = 0;
	int b, n;
	scanf_s("%d %d", &b, &n);
	char c;
	while (n != 0)
	{
		out = n % b;
		n = n / b;
		base1[m++] = out + '0';
	}
	for (int i = strlen(base1)-1; i >=0 ; i--)
		printf("%c", base1[i]);
}

//进制转换2
void practice_3_7()
{
	int n, b, last, result = 0, i = 0;
	scanf_s("%d %d", &b, &n);
	if (n == 0)
		printf("%d", n);
	while (n != 0)
	{
		last = n % 10;
		n /= 10;
		result += last*pow(b, i++);
	}
	printf("%d\n", result);
}

//手机键盘
void practice_3_8()
{

}

void main()
{
	practice_3_7();
	system("pause");
}