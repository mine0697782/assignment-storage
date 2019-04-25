/**************************************************************
* Name : 정민재
* Student ID : 20181688
* Program ID : Hw2
* Description : Infix 형태로 입력된 식을 Postfix로 바꾸고 계산하는것
* Variables : Converter - 한줄 입력을 인자로 넣어 새로운 배열에 결과를 넣는 함수
*
***************************************************************/

#include<iostream>
#include<fstream>
//#include<ctype.h>
#include<stdlib.h>
#include<string>
using namespace std;

char buffer[80], result[80];

/*************************************************************
* function : Converter
* description : 입력받은 line의 각 숫자와 연산자를 구분하여 새로운 배열로 만들기 위해 사용함
* variables : sIndx, idx, i  <=  각각 다른 배열의 인덱스로 사용
*             stack <= 입력받은 연산자를 임시로 넣어놓는 스택
*             buffer - 파일을 한줄씩 읽어 넣는 배열
*             result - 변환한 식을 넣는 배열
*
**************************************************************/
void converter(/*char *buffer, char result[]*/){
    int sIdx = 0, idx = 0, i = 0;
    char stack[10];
    int shut = 10;
    cout << "Converter Enter" << endl;
    while (buffer[i] != '\0' && buffer[i] != '\n') {
        if (shut-- == 0)  break;
        cout << "Now Result : " << result << endl;
        cout << "Now Stack : " << stack << endl;

        cout << "Converter While Enter" << endl;
        if (isdigit(buffer[i])){
            result[idx++] = buffer[i++];
            cout << "Converter While 1. " << endl;
        }
        else if (buffer[i] == '('){
            stack[sIdx++] = buffer[i];
            cout << "Converter While 2. " << endl;
        }
        else if (buffer[i] == ')'){
            cout << "Converter While 3. " << endl;
            while(stack[--sIdx] != '('){
                cout << "Converter while Finding (" << endl;
                result[idx++] = stack[sIdx];
            }
        }
        else if (buffer[i] == ' '){
            cout << "Converter While continue" << endl;
            continue;
        }
        else if (buffer[i] == '$'){
            cout << "Converter While Escape" << endl;
            break;
        }
        else {
            cout << "Converter While 4. " << endl;
            if (sIdx > 0) {
                result[idx++] = stack[--sIdx];
                stack[sIdx++] = buffer[i];
            }
        }
    }
    cout << "Converter While End" << endl;
    result[idx++] = stack[sIdx];
    result[idx] = '\0';
    return;
}


main(){
    //char buffer[80], output[80];
    char token;
    int i = 0;
    ifstream in;
    in.open("Hw2_example.txt");
    cout << "Program start" <<endl;

    //in.getline(buffer, 80);
    //cout << buffer << endl;
    
    while(in.getline(buffer, 80)) {

        cout << "First while" << endl;
        cout << buffer << endl;
        /**/
        converter(/*buffer, output*/);
        cout << "Converter clear" << endl;
        while(result[i++] != '\0'){
            cout << result[i-1] << " ";
        }
        /**/
    }
    cout << "Program end" << endl;
    
    return 0;
}
