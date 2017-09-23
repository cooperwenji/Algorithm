#ifndef BIGN_H
#define BIGN_H
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>

#include"algorithm_tool.h"


const int maxn = 1000;
class bign
{
public:
	bign() { memset(s, 0, sizeof(s)); len = 1; }

	bign operator = (const char* num)
	{
		len = strlen(num);
		for (int i = 0; i < len; i++)
			s[i] = num[len - i - 1] - '0';
		return *this;
	}
	bign operator = (int num)
	{
		char s[maxn];
		sprintf_s(s, "%d", num);
		*this = s;
		return *this;
	}
	bign operator = (const bign& b)
	{

	}


	bign(int num) { *this = num; };
	bign(const char* num) { *this = num; }

	bign operator+ (const bign& b)const
	{
		bign c;
		c.len = 0;
		
		for (int i = 0, g = 0; g || i < max(len,b.len) ; i++)
		{
			int x = g;
			if (i < len) x += s[i];
			if (i < b.len) x += b.s[i];
			c.s[c.len++] = x % 10;
			g = x / 10;
		}

		return c;
	}
	bign operator+= (const bign& b)
	{
		*this = *this + b;
		return *this;
	}
	bign operator- (const bign& b)const
	{
		bign c;  c.len = 0;
		for (int i = 0, g = 0; i < len; i++)
		{
			int x = s[i] - g;
			if (i < b.len) x = x - b.s[i];
			if (x >= 0) g = 0;
			else
			{
				g = 1;
				x += 10;
			}
			c.s[c.len++] = x;
		}
		return c;
	}
	
	std::string str() const
	{
		std::string res = "";
		for (int i = 0; i < len; i++) res = (char)(s[i] + '0') + res;
		if (res == "") res = "0";
		return res;
	}

	int len;
	int s[maxn];
private:
	
};

std::istream& operator >> (std::istream&in, bign& x)
{
	std::string s;
	in >> s;
	x = s.c_str();
	return in;
}

std::ostream& operator << (std::ostream& out, const bign& x)
{
	out << x.str();
	return out;
}

#endif // !BIGN_H
