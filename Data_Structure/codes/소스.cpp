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

	for (unsigned int i = 0; i < buffer.length(); i++) // ���� ��buffer�� ���̸�ŭ ����
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
			while (stack[sIdx--] != '(') { // '('�� ������ top�� �ϳ��� --�ϸ鼭 Ȯ�� ')'�� ã��
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

	string result_str; // ������� ��ȯ�� string ����
	string exp; // ���� ��� �ִ� string ����

	while (!in.eof()) {
		getline(in, exp); // �� �� �� �о�ͼ� result_str�� �ִ´�

		converter(exp, result_str);
		cout << "Converter clear" << endl;
		cout << "exp : " << exp << endl;
        cout << result_str << endl;
	}
	cout << "Program end" << endl;

	return 0;
}
