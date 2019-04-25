#include<iostream>
using namespace std;

struct Data {
    int num;
    char alpha;
};


class Tester {
    private:
        Data data;
    public:
        Tester(Data data) {
            this->data = data;
        }

        void print() {
            cout << "num : " << this->data.num << endl;
            cout << "alpha : " << this->data.alpha << endl;
        }

};


main(){
    int num;
    char alpha;

    cout << "input num : ";
    cin >> num;
    cout << "input alpha : ";
    cin >> alpha;

    Data data;
    data.num = num;
    data.alpha = alpha;

    Tester t = Tester(data);
    t.print();

    return 0;
}
