#include<iostream>
using namespace std;

main(){
    char name[100];
    char lang[200];

    cout << "이름은 무엇입니까? ";
    cin >> name;

    cout << "좋아하는 프로그래밍 언어는 무엇인가요? ";
    cin >> lang;
    
    int i = 0;
    while(1){
        if (name[i] == '\0')
            break;
        cout << name[i];
        i++;
    }
    cout << endl;
    cout << i << endl;

    cout << "내 이름은 " << name << " 입니다. \n";
    cout << "제일 좋아하는 언어는 " << lang << "입니다. " << endl;
    return 0;
}
