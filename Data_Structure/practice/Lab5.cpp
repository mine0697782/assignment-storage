#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Node{
    private:
        int data;
        Node *next;
    public:
        Node(int data){this->data = data; next = 0;}
    friend class List;
};

class List{
    private:
        Node *head;
    public:
        List(){head = 0;}
        int isEmpty(){return head == 0;}
        void insertNode(int data){
            Node *temp = new Node(data);
            Node *p, *q;

            if (isEmpty()) {head = temp;}
            else if (temp->data < head->data) {
                temp->next = head;
                head = temp;
            }
            else {
                p = head;
                while(p != 0 && temp->data > p->data){
                    q = p;
                    p = p->next;
                }
                if (p != 0){
                    q->next = temp; 
                    temp->next = p;
                }
                else {
                    q->next = temp;
                }
            }
        }
        void deleteNode(int data){
            Node *p, *q;

            if (!isEmpty()) {
                if (head->data == data) {
                    p = head;
                    head = head->next;
                    delete p;
                }
                else {
                    p = head;
                
                    while (p != 0 && p->data != data) {
                        q = p;
                        p = p->next;
                    }
                    if (p != 0){
                        q->next = p->next;
                        delete p;
                    }
                    else {
                        cout << data << " is not found" << endl;
                    }
                }
            }
            else {
                cout << "List is Empty!" << endl;
            }
        }
        void search(int data){
            Node *p;

            if (!isEmpty()){
                p = head;
                while(p != 0 && p->data != data) {
                    p = p->next;
                }
                if (p != 0){
                    cout << data << " is in the List" << endl;
                }
                else{
                    cout << data << " is not in the List" << endl;
                }
            }
            else 
                cout << "List is empty!" << endl;
        }
        void printList(){
            Node *p;

            if(!isEmpty()){
                p = head;
                cout << "List : ";
                while(p) {
                    cout << p->data << " ";
                    p = p->next;
                }
                cout << endl;
            }
            else
                cout << "List is empty!" << endl;
        }
        void printLast(){
            Node *p;

            if (!isEmpty()){
                p = head;
                while(p->next){
                    p = p->next;
                }
                cout << "Last : " << p->data << endl;
            }
            else 
                cout << "List is empty!" << endl;
        }
        void printNth(int Nth){
            Node *p;

            if (!isEmpty()) {
                p = head;
                for (int i = 0; i < Nth-1; i++) {
                    if (p->next) {
                        p = p->next;
                    }
                    else {
                        cout << "List is shorter than N" << endl;
                    }
                }
                cout << Nth << "th : " << p->data << endl;
            }
            else 
                cout << "List is empty!" << endl;
        }
        void invertList(){
            Node *p;
            int len, i;
            int *num;

            if (!isEmpty()){
                p = head;
                len = 1;
                while(p->next){
                    p = p->next;
                    len++;
                }
                num = new int[len];

                p = head;
                for (i=0; p; i++){
                    num[i] = p->data;
                    p = p->next;
                }
                cout << "Invert : ";
                while(i){
                    cout << num[i-1] << " ";
                    i--;
                }
                cout << endl;
            }
            else {
                cout << "List is empty!" << endl;
            }
        }

};


main(){
    char input[20];
    int num;
    List list = List();
    
    cout << "Menu(insert, delete, list, search, printLast, printNth, invert, quit)" << endl;

    while(1){
        //cout << "Menu(insert, delete, list, search, printLast, printNth, invert, quit)" << endl;
        cin >> input;

        if (strcmp(input,"insert") == 0){
            cin >> num;
            list.insertNode(num);
        }
        else if (strcmp(input,"delete") == 0){
            cin >> num;
            list.deleteNode(num);
        }
        else if (strcmp(input,"list") == 0){
            list.printList();
        }
        else if (strcmp(input,"search") == 0){
            cin >> num;
            list.search(num);
        }
        else if (strcmp(input,"printLast") == 0){
            list.printLast();
        }
        else if (strcmp(input,"printNth") == 0){
            cin >> num;
            list.printNth(num);
        } 
        else if (strcmp(input,"invert") == 0){
            list.invertList();
        } 
        else if (strcmp(input,"quit") == 0){
            exit(0);
        }
        else
            cout << "Bad Command" << endl;
    }
}
