#include<iostream>
#include<stdlib.h>

using namespace std;

main(){
    int freq[6] = {0};
    int i;

    srand((unsigned int) time(NULL));
    for (i = 0; i < 10000; i++){
        freq[(rand()%6)]++;
    }

    for (i = 0; i < 6; i++){
        cout << i+1 << "th frequency : " << freq[i] << endl;
    }
    return 0;
}
