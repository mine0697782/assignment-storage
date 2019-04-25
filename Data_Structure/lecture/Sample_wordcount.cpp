
#include <iostream>
#include <fstream>    // for ifstream, open
#include <stdlib.h>     // for exit 

using namespace std;


void main()
{
	void countWord(char buffer[], int &wc);

	ifstream infile;
	char buffer[80]; 	int wc;  int total = 0;

	infile.open("lab1.txt", ios::in);       								// Ȩ���������� lab2.txt download ���� ��
	if (infile.fail()) {cout << "can't open the input file" << endl;	exit(1);	}

	while (infile.getline(buffer, 80)) {
		cout << buffer << endl;
		countWord(buffer, wc);
		cout << "The number of words : " << wc << endl;
		total = total + wc;
	}
	cout << endl<<endl<<"The total number of words: " << total << endl<<endl;
}

void countWord(char buffer[], int &wc)
{

	const int IN = 1;                // �ܾ ���۵Ǹ� status = IN �� ��
	const int OUT = 0;               // �ܾ� ���̸� status = OUT �� ��

	int i = 0;
	int state = OUT;      // �ܾ ���۵��� �ʾҴٴ� ��

	wc = 0;

	while (buffer[i] != '\0') {
		if (isalpha(buffer[i])) {
			if (state == OUT) {
				++wc;
				state = IN;
			}                   // �����̰� state = IN �̸� do nothing 
		}
		else if (buffer[i] == ' ')
			state = OUT;
		i++;
	}
}