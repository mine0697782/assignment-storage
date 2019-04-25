/*********************************************************
* Name : 정민재
* Student ID : 20181688
* Program ID : HomeWork1-2
* Description : 키워드와 값을 입력받아서 알맞는 연산을 하는 것
* Algorithm : x
* Functions : x
* Variables : n1, n2 - 두 개의 값을 입력받아 저장하는 변수
*             in - 파일을 여는 변수
*             nums - 입력을 저장하는 2차원 배열
*
**********************************************************/
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

main(){
    ifstream in;
    in.open("Hw1-2.txt");
    string word[7];
    double nums[7][2];
    
    for (int i=0; i<7; i++){
        in >> word[i];
        if (word[i] != "circle")
           in >> nums[i][0]
              >> nums[i][1];
        else
            in >> nums[i][0];
    }

    for (int i=0; i<7; i++){
        if (word[i] == "triangle"){
            printf("%.2f \n", (nums[i][0]*nums[i][1])/2);
        } else if (word[i] == "rectangle") {
            printf("%.2f \n", nums[i][0]*nums[i][1]);
        } else if (word[i] == "circle") {
            printf("%.2f \n", (nums[i][0]*nums[i][0])*3.14);
        }
    }
    /*
    for(int i=0; i<7; i++){
        in >> word;
        if (word == "triangle"){
            in >> n1 >> n2;
            printf("%.2f \n",(n1*n2)/2);
        } else if (word == "rectangle") {
            in >> n1 >> n2;
            printf("%.2f \n", n1*n2);
        } else if (word == "circle") {
            in >> n1;
            printf("%.2f \n", (n1*n1)*3.14);
        }
    }
    */
}
