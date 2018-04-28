#include<iostream>


void ReplaceBlank(char* str, int len);

int main(int argc, char** argv) {
	char str[21] = "we are happy.";

	ReplaceBlank(str, 21);
	std::cout << str << std::endl;

	system("pause");
	return 0;
}

void
ReplaceBlank(char* str, int len) {
	if (str == NULL && len<=0)
		return;

	int num_blank = 0;
	int actual_len = 0;

	while (str[actual_len] != '\0') {
		if (str[actual_len] == ' ')
			num_blank++;
		actual_len++;
	}

	int p1, p2;
	int new_len = actual_len + num_blank * 2;
	p1 = actual_len;
	p2 = new_len;

	if (new_len + 1 > len) //说明字符串后面的空间不足以扩展
		return;

	while (p1 < p2 && p1 >= 0) {
		if (str[p1] ==' ') {
			// 处理是空格的情况
			p1--;
			p2 = p2 - 3;
			str[p2 +1] = '%';
			str[p2 + 2] = '2';
			str[p2 + 3] = '0';
		}else {   // 这里不是空格的情况，仅仅复制
			str[p2--] = str[p1--];
		}
	}
	return;
}
