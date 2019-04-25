#include<iostream>
using namespace std;

int get_sum2(int a[], int n)
{
    int i;
    int *p;
    int sum = 0;

    p = a;
    for(i = 0; i < n; i++)
        sum += *p++;
    return sum;
}

main(){
    int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    result = get_sum2(list, 10);
    cout<<result<<endl;
}
