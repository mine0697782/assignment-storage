#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ifstream in;
    in.open("ppt10_text.txt");
    if (!in) {
        cerr << "파일 오픈에 실패했습니다." << endl;
        exit(1);
    }
    char c;
    in.get(c);
    while(!in.eof()){
        cout << c;
        in.get(c);
    }
    in.close();
    return 0;
}
