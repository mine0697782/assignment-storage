#include<iostream>
using namespace std;

main(){
    char a1[5][10] = {0};
    char a2[7] = {0};
    
    int i1[3][5] = {0};
    int i2[4] = {0};

    cout<<sizeof(a1)<<endl<<sizeof(a1[0])<<endl<<sizeof(a2)<<endl;
    cout << "========" << endl;
    cout<<sizeof(i1)<<endl;
    cout<<sizeof(i1[0])<<endl;
    cout<<sizeof(i2)<<endl;
    cout<<sizeof(i1)/sizeof(i1[0]) << endl;

    return 0;

}
