#include <iostream>
using namespace std;

void outputPyramid(int n, int k);

main(){
    int t;
    int n, k;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> k;
        outputPyramid( n, k );
    }
    return 0;
}
void outputPyramid(int n, int k){
    int indent = 0;
    cout<<k;
    int output = k;
    for(int i=1; i<k; i++){
        output += (n-i);
        cout<<'*'<<output;
    }
    cout<<endl;
    return;
}
