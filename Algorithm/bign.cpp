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