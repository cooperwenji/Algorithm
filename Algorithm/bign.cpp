#include "bign.h"

bign::bign() 
{ 
	memset(s, 0, sizeof(s)); len = 1, symbol = 1; 
}

bign::bign(int num) 
{
	*this = num;
}

bign::bign(const char* num) 
{ 
	*this = num; 
}

bign bign::operator = (const char* num)
{
	len = strlen(num);
	assert(len > 0);


	for (int i = 0; i < len; i++)
		s[i] = num[len - i - 1] - '0';
	return *this;
}

bign bign::operator = (int num)
{
	char s[maxn];
	sprintf_s(s, "%d", num);
	*this = s;
	return *this;
}

bign bign::operator = (const bign& b)
{
	len = b.len;
	for (int i = 0; i < b.len; i++)
	{
		s[i] = b.s[i];
	}
	return *this;
}

std::string bign::str() const
{
	std::string res = "";
	for (int i = 0; i < len; i++) res = (char)(s[i] + '0') + res;
	if (res == "") res = "0";
	return res;
}

bign bign::operator- (const bign& b)const
{
	bign c;  c.len = 0;
	bign opera_a = *this;
	bign opera_b = b;
	int ok = 1;
	if (opera_a.len < opera_b.len)
	{
		bign temp = opera_a;
		opera_a = opera_b;
		opera_b = temp;
		ok = -1;
	}

	for (int i = 0, g = 0; i < opera_a.len; i++)
	{
		int x = opera_a.s[i] - g;
		if (i < opera_b.len) x -= opera_b.s[i];
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

bign bign::operator+= (const bign& b)
{
	*this = *this + b;
	return *this;
}

bign bign::operator+ (const bign& b)const
{
	bign c;
	c.len = 0;

	for (int i = 0, g = 0; g || i < max_int(len, b.len); i++)
	{
		int x = g;
		if (i < len) x += s[i];
		if (i < b.len) x += b.s[i];
		c.s[c.len++] = x % 10;
		g = x / 10;
	}

	return c;
}

bign bign::operator* (const bign& b)const
{
	//method 1 自己写
	bign* b_arrary = new bign[b.len];
	bign temp(0);
	for (int i = 0; i < b.len; i++)
	{
		int x, c = 0;
		b_arrary[i].len = 0;
		for (int z = 0; z < i; z++)
			b_arrary[i].s[b_arrary[i].len++] = 0;
		for (int j = 0; j < len; j++)
		{
			x = s[j] * b.s[i] + c;
			b_arrary[i].s[b_arrary[i].len++] = x % 10;
			c = x / 10;
		}
		if(c>0) b_arrary[i].s[b_arrary[i].len++] = c;
		//std::cout << b_arrary[i].str() << std::endl;
		temp += b_arrary[i];
	}
	delete[] b_arrary;
	return temp;

	//method 2 网上
/*	bign c; c.len = len + b.len;                   //这个方法是（0，0）位置相乘的结果在0，（1，0）相乘的结果在1
	for (int i = 0; i < len; i++)                  //（0，1）相乘的结果也在1，随后将这些结果累加，取余为该位置的结果，
		for (int j = 0; j < b.len; j++)            //除以10作为进量给下一位置相加。
			c.s[i + j] += s[i] * b.s[j];
	for (int k = 0; k < c.len - 1; k++) {
		c.s[k + 1] += c.s[k] / 10;
		c.s[k] %= 10;
	}
	return c;*/
}

bool bign::operator <(const bign& b)const 
{
	if (len != b.len) return len < b.len;
	for (int i = len - 1; i >= 0; i--)
		if (s[i] != b.s[i]) return s[i] < b.s[i];
	return false;
}

bool bign::operator >(const bign& b)const
{
	return b < *this;
}

bool bign::operator<=(const bign& b)const
{
	return !(b < *this);
}

bool bign::operator>=(const bign& b)const
{
	return !(*this < b);
}

bool bign::operator==(const bign& b)const
{
	return (b >= *this) && (b <= *this);
}

bool bign::operator!=(const bign& b)const
{
	return b > *this || b < *this;
}





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