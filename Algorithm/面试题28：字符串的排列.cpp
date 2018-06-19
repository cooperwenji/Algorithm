#include<iostream>
#include<vector>
#include<set>
#include<string>

void PermutationImpl(std::string str, int index, std::set<std::string>& result) {
	int length = str.size();
	
	if (index == length) {
		result.insert(str);
	}
	else {
		for (int i = index; i < length; i++) {
			char temp = str[i];
			str[i] = str[index];
			str[index] = temp;

			PermutationImpl(str, index + 1, result);

			temp = str[i];
			str[i] = str[index];
			str[index] = temp;
		}
	}
}

// permutation
std::vector<std::string> Permutation(std::string str) {
	std::set<std::string> result;
	std::vector<std::string> return_result;

	if (str.empty())
		return return_result;

	PermutationImpl(str, 0, result);

	std::set<std::string>::iterator itr;
	for (itr = result.begin(); itr != result.end(); itr++) {
		return_result.push_back(*itr);
	}

	return return_result;
}


// combination                                
void CombinationImpl(std::string str_result, int len, std::set<char> characterSet, std::vector<std::string>& result) {
	if (len == 0)
		result.push_back(str_result);

	std::set<char>::iterator itr = characterSet.begin();
	for (; itr != characterSet.end();) {
		char temp = *itr;
		std::set<char>::iterator temp_itr = itr++;
		str_result += temp;
		characterSet.erase(temp_itr);

		CombinationImpl(str_result, len - 1, characterSet, result);
		str_result = str_result.substr(0, str_result.size() - 1);
	}
}

std::vector<std::string> Combination(std::string str) {
	std::vector<std::string> result;
	std::set<char> characterSet;

	if (str.empty())
		return result;

	int strLen = str.size();
	for (int i = 0; i < strLen; i++) {
		characterSet.insert(str[i]);
	}

	std::string str_result = "";
	for (int i = 1; i <= strLen; i++) {
		CombinationImpl(str_result, i, characterSet, result);
	}

	return result;
}

//int main(int argc, char** argv) {
//	std::string testData("aa");
//	std::vector<std::string> result;
//
//	//printf("%s \n", testData.c_str());
//	result = Permutation(testData);
//
//	int len = result.size();
//	for (int i = 0; i < len; i++) {
//		printf("%s\n", result[i].c_str());
//	}
//	system("pause");
//	return 0;
//
//}

//void main() {
//	std::string str = "abc";
//	std::vector<std::string> result = Combination(str);
//	
//	std::vector<std::string>::iterator itr = result.begin();
//	for (; itr != result.end(); itr++) {
//		printf("%s \n", (*itr).c_str());
//	}
//
//
//	system("pause");
//}

