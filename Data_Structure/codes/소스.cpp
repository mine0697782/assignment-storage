#include<iostream>
#include<fstream>
#include<ctype.h>
#include<stdlib.h>
#include <string>
using namespace std;

//char buffer[80], result[80];

void converter(string buffer, string &result) {
	int sIdx = -1, idx = 0, i = 0;
	char stack[10];
	int shut = 10;
	cout << "Converter Enter" << endl;

	for (unsigned int i = 0; i < buffer.length(); i++) // 받은 식buffer의 길이만큼 루프
	{
		cout << "Now Result : " << result << endl;
		cout << "Now Stack : " << stack << endl;

		if (isdigit(buffer[i])) {
			result.push_back(buffer[i]);
			cout << "Converter While 1. " << endl;
		}
		else if (buffer[i] == '(') {
			stack[++sIdx] = buffer[i];
			cout << "Converter While 2. " << endl;
		}
		else if (buffer[i] == ')') {
			cout << "Converter While 3. " << endl;
			while (stack[sIdx--] != '(') { // '('를 만나면 top을 하나씩 --하면서 확인 ')'를 찾음
				cout << "Converter while Finding (" << endl;
				result.push_back(stack[sIdx]);
				cout << "Current top index of Stack : " << sIdx << endl;
			}
		}
		
	    else if (buffer[i] == '$') {
			cout << "Converter While Escape" << endl;
			break;
		}
		else {
			cout << "Converter While 4. " << endl;
			if (sIdx >= -1) {
			    cout <<"stack Item : "<< stack[sIdx] << endl;
                result.push_back(stack[sIdx--]);
                stack[++sIdx] = buffer[i];
			}
		}
	}
	result.push_back(stack[sIdx]);
	return;
}


int main() {
	//char buffer[80], output[80];
	char token;
	int i = 0;
	ifstream in("data.txt");
	cout << "Program start" << endl;

	string result_str; // 결과값을 반환할 string 변수
	string exp; // 식을 담고 있는 string 변수

	while (!in.eof()) {
		getline(in, exp); // 한 줄 씩 읽어와서 result_str에 넣는다

		converter(exp, result_str);
		cout << "Converter clear" << endl;
		cout << "exp : " << exp << endl;
        cout << result_str << endl;
	}
	cout << "Program end" << endl;

	return 0;
}
