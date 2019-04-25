#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

main(){
    int user, com, win;
    srand((unsigned int) time(NULL));
    cout << "Lets Gawibawibo \nPick one (Scissors = 0, Rock = 1, Paper = 2) : ";
    cin >> user;
    com = rand()%3;

    cout << "User's : " << user << "\nComputer's : " << com << endl;

    if (user == (com+1)%3)
        cout << "User win!" << endl;
    else if (com == (user+1)%3)
        cout << "Computer win!" << endl;
    else 
        cout << "Draw!" << endl;
    
    return 0;
}
