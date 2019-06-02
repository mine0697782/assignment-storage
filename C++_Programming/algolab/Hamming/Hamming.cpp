#include <iostream>
#include <fstream>
#include <algorithm>
//#include <time.h>
using namespace std;

int main(){
    //time_t start, end;

    ifstream in;
    int t, data;
    in.open("Hamming_text.txt");
    //in.open("input.txt");

    //start = time(NULL);
    in >> t;

    while (t--){
        int index = 0;
        const signed int max = 1000000000;
        unsigned int arr[7410];
        
        in >> data;
        for (unsigned int i = 1;; i *= 2) {
            for (unsigned int j = i;; j *= 3) {
                for (unsigned int k = j;; k *= 5) {
                    arr[index++] = k;
                    if (k>max/5) break;
                }
                if (j>max/3) break;
            }
            if (i>max/2) break;
        }
        //cout << "index : " << index << endl;
        sort(arr, arr+index);
        cout << arr[data-1] << endl;

    }
    
    //end = time(NULL);
    //double result = end - start;
    //cout << "time : " << result << endl;
    return 0;
}
