#ifndef BIGN_H
#define BIGN_H
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>

const int maxn = 1000;
struct bign
{
	int len, s[maxn];
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
		sprintf(s, "%d", num);
		*this = s;
		return *this;
	}

	bign(int num) { *this = num; };
	bign(const char* num) { *this = num; }
	bign operator+ (const bign& b)const
	{
		bign c;
		c.len = 0;

	}

	
	std::string str() const
	{
		std::string res = "";
		for (int i = 0; i < len; i++) res = (char)(s[i] + '0') + res;
		if (res == "") res = "0";
		return res;
	}
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
