#include<iostream>

using namespace std;

main(){
    int money, cost, change;
    int coin, num;

    cout << "Your money : ";
    cin >> money;
    cout << "Good's cost : ";
    cin >> cost;
    change = money - cost;
    cout << "Change is : " << change << endl;

    coin = 100;
    while(change){
        cout << coin << " coin's number : " << change/coin << endl;
        change %= coin;
        coin = (coin==100 ? 50 : 10);
    }
    return 0;
}
