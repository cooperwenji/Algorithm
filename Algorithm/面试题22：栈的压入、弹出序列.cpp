#include<iostream>
#include<vector>
#include<stack>
bool IsPopOrder(std::vector<int> pushV, std::vector<int> popV) {
	if (pushV.size() == 0 || popV.size() == 0)
		return false;

	int currentPushV = 0;
	int currentPopV = 0;
	int pushLen = pushV.size();
	int popLen = popV.size();
	std::stack<int> assistStack;

    assistStack.push(pushV[currentPushV++]);

	while (currentPushV <= pushLen && assistStack.size()!=0) {
		if (popV[currentPopV] != assistStack.top()) { //�����ǰջ��Ԫ�ز��ǵ���Ԫ��
			if (currentPushV < pushLen) {//������ջ���Ԫ�أ�ֱ����Ԫ�����
				assistStack.push(pushV[currentPushV++]);
			}
			else {
				return false;
			}
		}
		else {  //�����ǰջ��Ԫ�ؼ�Ϊ����Ԫ��
			assistStack.pop();
			currentPopV++;
		}
	}
	return true;
}

