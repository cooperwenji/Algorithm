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
		if (popV[currentPopV] != assistStack.top()) { //如果当前栈顶元素不是弹出元素
			if (currentPushV < pushLen) {//往辅助栈添加元素，直到有元素相等
				assistStack.push(pushV[currentPushV++]);
			}
			else {
				return false;
			}
		}
		else {  //如果当前栈顶元素即为弹出元素
			assistStack.pop();
			currentPopV++;
		}
	}
	return true;
}

