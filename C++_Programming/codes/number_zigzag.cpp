#include <iostream>
using namespace std;

void outputZigZag(int n, int k);

main(){
    int t;
    int n, k;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> k;
        outputZigZag( n, k );
    }
    return 0;
}

void outputZigZag(int n, int k){
    int start = 1;
    int line = 1;
    for(; line<k; line++) start += line;
    if(k%2==1){
        cout<<start++;
        for(int i=0; i<k-1; i++) cout<<'*'<<start++;
        cout<<endl;
    }
    else {
        start += (k - 1);
        cout<<start--;
        for(int i=0; i<k-1; i++) cout<<'*'<<start--;
        cout<<endl;
    }

    return;
}
