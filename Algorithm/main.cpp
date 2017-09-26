// Created by cooper on 2017/9/19
// Copyright @ 2017 cooper.

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<time.h>
#include<ctype.h>
#include<assert.h>

#include"bign.h"

#define LOCAL
#define INF 1000000000
#define MAXN 1000 + 10
#define HUNDRED 100 + 10
#define MAX 10
#define LONGEST 5000 + 10

using namespace std;

#pragma region function 
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
int keyboard[HUNDRED];
char english_word[HUNDRED];
char output_word[HUNDRED];
void practice_3_8()
{
	//method 1   自己
	int index = 0;
	//初始化
	for (int i = 0; i < 26; i++)
	{
		if ((i >= 0 && i <= 14) || (i >= 19 && i <= 21))
			keyboard[i] = i % 3 + 1;
		else if ((i >= 15 && i <= 18))
			keyboard[i] = (i - 15) % 4 + 1;
		else if (i >= 22 && i <= 25)
			keyboard[i] = (i - 22) % 4 + 1;
	}

	scanf_s("%s", english_word, HUNDRED-1);
	//printf("%s", english_word);
	for (int i = 0; i < strlen(english_word); i++)
	{
		output_word[index++] = english_word[i];
		output_word[index++] = keyboard[english_word[i] - 'a'] + '0';
	}

	for (int i = 0; i < index; i++)
		printf("%c", output_word[i]);

	//method 2  网上
/*	char word[MAXN], *p, *keyBd[8] = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	int i, j, len;
	fgets(word, sizeof(word), stdin);
	len = strlen(word);
	for (i = 0; i<len; i++)
	{
		for (j = 0; j<8; j++)
		{
			if (p = strchr(keyBd[j], word[i]))
			{
				printf("%c%d", word[i], p - keyBd[j] + 1);
			}
		}
	}*/
}

//组合数
int f(int m)
{
	int result = 1;
	for (int i = 1; i <= m; i++)
	{
		result *= i;
	}
	return result;
}
void fun_4_1()
{
	int m, n;
	scanf_s("%d %d", &m, &n);
	printf("%d\n", f(n) / (f(m)*f(n - m)));
}

//孪生素数
bool prime_number(int n)
{
	int m;
	assert(n >= 0);
	if (n == 1) return false;
	m = floor(sqrt(n) + 0.5); //
	for (int i = 2; i <= m; i++)
		if (n%i == 0)  return false;
	return true;
}
void fun_4_2()
{
	int m;
	scanf_s("%d", &m);
	for (int i = m-2 ; i >= 3; i--)
	{
		if (prime_number(i)&& prime_number(i + 2))
		{
			printf("%d %d", i, i + 2);
			break;
		}
	}

}

//指针变量交换
void pointer_swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void fun_4_5()
{
	int a, b;
	scanf_s("%d %d", &a, &b);
	pointer_swap(&a,&b);
	printf("%d %d", a, b);
}

//WERTYU
void fun_5_1()
{
	char* key = "'1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	char c;
	int i;
	while ((c = getchar()) != EOF)
	{
		for (i = 0; key[i] && key[i] != c; i++);
		if (key[i])  putchar(key[i - 1]);
		else putchar(c);
	}
}

//TeX括号
void fun_5_2()
{
	int i = 0,flag = 1;
	char c;
	while ((c = getchar()) != EOF)
	{
		if (c == '"') 
		{
			printf("%s", flag ? "``" : "''"); 
			flag = !flag;
		}
		else
			printf("%c", c);
	}
}

#pragma endregion
//周期串
char duplicate_word[HUNDRED];
void fun_5_3()
{
	scanf_s("%s", duplicate_word, HUNDRED - 1);
	int len = strlen(duplicate_word);
	for (int i = 1; i <= len; i++)
	{
		if (len%i == 0)
		{
			int ok = 1;
			for (int j = i; j < len; j++)
			{
				if (duplicate_word[j] != duplicate_word[j%i])
				{
					ok = 0;
					break;
				}
			}
			if (ok)
			{
				printf("%d\n", i); break;
			}
		}
	}
}

//小学生算数
void fun_5_4()
{
	int a, b;
	while (scanf_s("%d %d", &a, &b) == 2)
	{
		if (!a && !b)  return;
		int c = 0, ans = 0;
		for (int i = 9; i >= 0; i--)
		{
			c = (a % 10 + b % 10 + c) > 9 ? 1 : 0;
			ans += c;
			a /= 10, b /= 10;
		}
		printf("%d\n", ans);
	}
}

//阶乘的精确值
const int maxn_f = 3000;
int factorial[maxn_f];
void fun_5_5()
{
	int n;
	scanf_s("%d", &n);
	memset(factorial, 0, maxn);

	factorial[0] = 1;
	int s, c;
	for (int i = 2; i <= n; i++)
	{
		c = 0;
		for (int j = 0; j < maxn; j++)
		{
			s = factorial[j] * i + c;
			factorial[j] = s % 10;
			c = s / 10;
		}
	}

	int i;
	for (i = maxn - 1; i >= 0; i--) if (factorial[i]) break;
	for (int j = i; j >= 0; j--) printf("%d", factorial[j]);
	printf("\n");
}



void main()
{
	bign a(99), b(99);
	cout << (a*b).str() << endl;
	system("pause");
}  