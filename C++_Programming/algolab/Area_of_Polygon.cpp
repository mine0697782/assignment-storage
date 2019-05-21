#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

main(){
    int t, n;
    int sum, result;
    ifstream in;
    in.open("input.txt");
    
    in >> t;
    while(t--){
        in >> n;
        int num[2][n];
        for (int i=0; i<n*2; i++){
            in >> num[i%2][i/2];
        }
        result = 0;
        sum = 0;
        for (int i=0; i<n; i++){
            result = ((num[0][i] + num[0][i+1]) * (num[1][i+1] - num[1][i]));
            if (i == n-1){
                result = ((num[0][i] + num[0][0]) * (num[1][0] - num[1][i]));
            }
            sum += result;
        }
        cout << abs(sum);
        if (sum > 0){
            cout << " 1" << endl;
        }
        else {
            cout << " -1" << endl;
        }
    }   
    return 0;
}
