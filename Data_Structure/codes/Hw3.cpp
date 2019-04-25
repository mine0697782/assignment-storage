/******************************************************************************************
*
* Name : 정민재
* Student ID : 20181688
* Program ID : Hw3
* Description : 프로그램 목적
* Algorithm : Singly Linked Lisk - 데이터 처리를 위한 자료 구조
*             Ascending Sort - 정렬 알고리즘
*             Comparison - 비교 알고리즘
*
* Functions : 
*       compare() - 직접 선언한 student형 데이터의 특정 값을 비교하는 함수
*       input() - "data1.txt"와 "data2.txt" 파일을 읽어서 구조체에 저장하는 함수
*       print() - 처리가 끝난 데이터들을 적절한 포맷으로 출력해주는 함수
*       ascending_order() - 구조체 배열의 특정 변수를 기준으로 오름차순 정렬하는 함수
*       grade_A() - 성적이 A인 학생들만 골라 출력하는 함수
*       major_CS() - 전공이 CS인 학생들만 골라 출력하는 함수
*
******************************************************************************************/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct Data {
    char name;
    int id;
    char major[10];
    char grade;
};

class Node {
    private:
        Data data;
        Node *next;
    public:
        Node(Data data){
            this->data = data;
        }

        Data getData() {
            return data;
        }

        Node *getNext() {
            return next;
        }

    friend class List;
};

class List {
    private:
        Node *head;
    public:
        List() {head = 0;}

        void insertNode(Data data){
            Node *temp = new Node(data);
            Node *p, *q;

            if (head == 0) head = temp;
            else if (temp->data.name < head->data.name) {
                temp->next = head;
                head = temp;
            }
            else {
                p = head;
                while ((p != 0) && (p->data.name < temp->data.name)) {
                    q = p;
                    p = p->next;
                }
                if (p != 0) {
                    temp->next = p;
                    q->next = temp;
                }
                else q->next = temp;
            }
        }

        bool isEmpty() {
            if (head == 0) return true;
            else return false;
        }

        void displayList() {
            Node *p;

            if (!isEmpty()) {
                p = head;
                while (p) {
                    cout << p->data.name << "  " << p->data.id << "  ";
                    cout << p->data.major << "  " << p->data.grade << endl;
                    p = p->next;
                }
                cout << endl;
            }
            else cout << "List is empty!" << endl;
        }

        void print_A() {
            Node *p;
            p = head;
            
            while(p) {
                if (p->data.grade == 'A'){
                    cout << p->data.name << "  " << p->data.id << "  ";
                    cout << p->data.major << "  " << p->data.grade << endl;
                }
                p = p->next;
            }
            cout << endl;
        }

        void print_CS() {
            Node *p;
            p = head;

            while(p) {
                if (strcmp(p->data.major, "CS") == 0) {
                    cout << p->data.name << "  " << p->data.id << "  ";
                    cout << p->data.major << "  " << p->data.grade << endl;
                }
                p = p->next;
            }
            cout << endl;
        }

        Node *getHead() {return head;}
};

/******************************************************************************************
* function : fileInput
* description : 두 개의 파일을 각각 읽고 구조체 변수의 각 요소에 저장해주는 함수
* variables : 
*       n - 파일에서 입력받을 데이터의 줄의 수를 받는 매개변수
*       in - 현재 읽으려는 파일이 무엇인지 구분하기 위한 매개변수
*       i - 반복문의 인덱스
*       fin - ifstream으로 파일을 받기 위해 선언한 변수
******************************************************************************************/
List fileInput(int fileNum) {
    int i;
    int n;
    List list = List();
    Data data;
    ifstream in;
    
    switch(fileNum) {
        case 3:
        case 1:
            in.open("data1.txt");
            for (i = 0; i < 7; i++) {
                in >> data.name >> data.id >> data.major >> data.grade;
                list.insertNode(data);
            }
            in.close();
            if (fileNum == 1) break;
        case 2:
            in.open("data2.txt");
            for (i = 0; i < 3; i++) {
                in >> data.name >> data.id >> data.major >> data.grade;
                list.insertNode(data);
            }
    }

    return list;
}

int main()
{
    cout << "Program Start" << endl;

    List list1, list2, list3;
    
    cout << "Variables created" << endl;

    list1 = fileInput(1);
    cout << "First initialized" << endl;
    cout << "==== First debug ====" << endl;
    list1.displayList();
    
    /*
    list2 = fileInput(2);
    cout << "Second initialized" << endl;
    cout << "==== Second debug ====" << endl;
    list2.displayList();
    */

    list3 = fileInput(3);
    /*
    cout << "Thrid initialized" << endl;
    cout << "==== Third debug ====" << endl;
    list3.displayList();
    */
    cout << "==== print A ====" << endl;
    list1.print_A();
    
    cout << "==== print CS ====" << endl;
    list3.print_CS();
    
    cout << "Program End" << endl;
    return 0;
}
