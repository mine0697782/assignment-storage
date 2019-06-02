/*
* Banking System Ver 0.1
* 윤성우 열혈 C++ 교재 Chap01 p.53
* 내용 : OOP 단계별 프로젝트의 기본 틀
*/

#include<iostream>
#include<cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void ShowAllAccInfo();

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct {
    int accID;
    int balance;
    char cusName[NAME_LEN];
} Account;

Account accArr[100];
int accNum=0;

int main() {
    int choice;

    while(1){
        ShowMenu();
        cout << "선택 : ";
        cin >> choice;
        cout << endl;

        switch(choice) {
            case MAKE:
                MakeAccount();
                break;
            case DEPOSIT:
                DepositMoney();
                break;
            case WITHDRAW:
                WithdrawMoney();
                break;
            case INQUIRE:
                ShowAllAccInfo();
                break;
            case EXIT:
                return 0;
            default:
                cout << "Illegal selection..." << endl;
        }
    }
}

void ShowMenu(){
    cout << "-----Menu-----" << endl;
    cout << "1. 계좌개설 " << endl;
    cout << "2. 입 금 " << endl;
    cout << "3. 출 금 " << endl;
    cout << "4. 계좌정보 전체 출력 " << endl;
    cout << "5. 프로그램 종료 " << endl; 
}

void MakeAccount(){
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[계좌개설]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "이 름 : "; cin >> name;
    cout << "입금액 : "; cin >> balance;
    cout << endl;

    accArr[accNum].accID=id;
    accArr[accNum].balance = balance;
    strcpy(accArr[accNum].cusName, name);
    accNum++;
}












































