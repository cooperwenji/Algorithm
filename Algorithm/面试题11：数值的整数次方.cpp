#include<iostream>

/// <summary>
/// 在判断底数base是不是等于0时，不能直接写base==0，
/// 这是因为在计算机内表示小数时（包括float和double型小数）都有误差。
/// </summary>

bool equal(double num1, double num2) {
	if (num1 - num2 < 0.0000001 && num1-num2>-0.0000001)
		return true;
	return false;
}

double PowerWithUnsignedExponent(double base, int exponent) {
	double result = 1.0;
	for (int i = 0; i < exponent; i++)
		result *= base;

	return result;
}

double PowerWithUnsignedExponentBest(double base, int exponent) {
	if (exponent == 0)
		return 1.0;
	if (exponent == 1)
		return base;

	double result = PowerWithUnsignedExponentBest(base, exponent >> 1);
	result *= result;
	if (exponent & 0x1)
		result *= base;

	return result;
}

double Power(double base, int exponent) {
	// 当底数（base）是零且指数是负数的时候提示参数非法
	if (equal(base, 0.0) && exponent < 0)
		throw std::exception("invalid input!");

	unsigned int absExponent = (unsigned int)exponent;
	// 当指数为负数的时候需算出次方的结果之后再取倒数
	if (exponent < 0)
		absExponent = (unsigned int)-exponent;
	
	double result = PowerWithUnsignedExponent(base, absExponent);

	if (exponent < 0)
		result = 1.0 / result;

	return result;
}



