#include<iostream>

/// <summary>
/// ���жϵ���base�ǲ��ǵ���0ʱ������ֱ��дbase==0��
/// ������Ϊ�ڼ�����ڱ�ʾС��ʱ������float��double��С����������
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
	// ��������base��������ָ���Ǹ�����ʱ����ʾ�����Ƿ�
	if (equal(base, 0.0) && exponent < 0)
		throw std::exception("invalid input!");

	unsigned int absExponent = (unsigned int)exponent;
	// ��ָ��Ϊ������ʱ��������η��Ľ��֮����ȡ����
	if (exponent < 0)
		absExponent = (unsigned int)-exponent;
	
	double result = PowerWithUnsignedExponent(base, absExponent);

	if (exponent < 0)
		result = 1.0 / result;

	return result;
}



