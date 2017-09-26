#ifndef BIGN_H
#define BIGN_H
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<assert.h>

#include"algorithm_tool.h"

//高精度运算类bign;
const int maxn = 1000;
class bign               //暂时没处理符号的问题
{
public:
	bign();
	bign(int num);
	bign(const char* num);

	bign operator = (const char* num);
	bign operator = (int num);
	bign operator = (const bign& b);

	bign operator+ (const bign& b)const;
	bign operator+= (const bign& b);
	bign operator- (const bign& b)const;
	bign operator* (const bign& b)const;

	bool operator <(const bign& b)const;
	bool operator >(const bign& b)const;
	bool operator <=(const bign& b)const;
	bool operator >=(const bign& b)const;
	bool operator !=(const bign& b)const;
	bool operator ==(const bign& b)const;

	std::string str() const;

private:
	int len;
	int symbol;
	int s[maxn];
};
#endif // !BIGN_H
