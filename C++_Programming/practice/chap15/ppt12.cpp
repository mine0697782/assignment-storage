#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream os;
    char c;
    os.open("ppt12_text.txt");
    while(cin.get(c)){
        os.put(c);
    }
    os.close();
    return 0;
}
