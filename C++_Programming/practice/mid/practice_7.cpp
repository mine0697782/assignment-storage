#include<iostream>
#include<cmath>

using namespace std;

main(){
    int num1, num2, div, small;//, root;
    int i;

    cout << "Enter two integer : ";
    cin >> num1 >> num2;

    small = num1>num2 ? num1 : num2;
    //root = sqrt(num1>num2 ? num1 : num2);
    i = 1;
    while(i<=small){
        if (num1%i == 0 && num2%i == 0)
            div = i;
        i++;
    }
    cout << "The biggest divider is " << div << endl;
    return 0;
}
