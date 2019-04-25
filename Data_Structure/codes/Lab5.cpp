#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

class Node {
    private:
        int data;
        Node *next;
    public:
        Node(int dat) {data = dat;}
        int getData() {return data;}
    friend class List;
};

class List {
    private:
        Node *head;
    public:
        List() {head = 0;}

        void insertNode(int data){
            Node *temp = new Node(data);
            Node *p, *q;

            if (head == 0) head = temp;
            else if (temp->data < head->data) {
                temp->next = head;
                head = temp;
            }
            else {
                p = head;
                while ((p != 0) && (p->data < temp->data)) {
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
            
        void deleteNode(int num) {
            Node *p, *q;

            if (head->data == num) {
                p = head;
                head = head->next;
                delete p;
            }
            else {
                p = head;
                while (p != 0 && p->data != num) {
                    q = p;
                    p = p->next;
                }
                if (p != 0) {
                    q->next = p->next;
                    delete p;
                }
                else
                    cout << num << " is not found (delete)" << endl;
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
                cout << "list : ";
                while (p) {
                    cout << p->data << " ";
                    p = p->next;
                }
                cout << endl;
            }
            else
                cout << "List is empty!" << endl;
        }

        void searchList(int num) {
            Node *p;

            if (head != 0) {
                p = head;
                while (p != 0 && p->data != num)
                    p = p->next;

                if (p) cout << p->data << " is in the list (search)" << endl;
                else cout << num << " is not in the list (search)" << endl;
            }
            else cout << "List is empty!" << endl;
        }
        void printLast() {
            Node *p;
            
            if (!isEmpty()) {
                p = head;
                while(p->next){
                    p = p->next;
                }
                cout << p->data << endl;
            }
            else cout << "List is empty!" << endl;
        }
        void printNth(int n) {
            Node *p;
            if (!isEmpty()){
                p = head;
                for(int i = 0; i<n-1; i++){
                    if (p->next){
                        p = p->next;
                    }
                    else cout << "List is shorter than N (printNth)" << endl;
                }
                cout << p->data << endl;
            }
            else cout << "List is empty!" << endl;
        }

        void invertList(){
            //cout << "Enter invert" << endl; //
            Node *p;
            int index;
            int num[100];
            int count = 0;
            int three = 3;
            if (!isEmpty()) {
                //cout << "start if" << endl;//
                p = head;
                index = 0;
                while (three--){
                    //cout << "start while" << endl;//
                    num[index++] = int(p->data);
                    //cout << "p->data : " << p->data << endl;//
                    p = p->next;
                    //cout << count << " ";//
                    count++;
                }
            }
            else cout << "List is empty!" << endl;

            //cout << "end while" << endl; //
            cout << "Invert : ";
            for(index = 1; index <= count; index++) {
                cout << num[count - index] << " ";
            }
            cout << endl;
        }
    };



    main(){
        int num; char input[20];
        
        List l = List();

        ifstream in;
        in.open("Lab5_example.txt");
        while(1){
            //cout << "\nMenu (1.insert, 2.delete, 3.list, 4.search, 5.PrintLast, 6.PrintNth, 7.InvertList, 8.exit) : ";
            in >> input;

            if (strcmp(input, "insert") == 0) {
            //cout << "Enter a number to insert : ";
            in >> num;
            l.insertNode(num);
        }

        else if (strcmp(input, "delete") == 0) {
            if (l.isEmpty()) {cout << "List is Empty!\n"; continue;}
            //cout << "Enter a number to delete : ";
            in >> num;
            l.deleteNode(num);
        }
        
        else if (strcmp(input, "list") == 0) {
            l.displayList();
        }
        
        else if (strcmp(input, "search") == 0) {
            //cout << "Enter a number to search : ";
            in >> num;
            l.searchList(num);
        }
        
        else if (strcmp(input, "PrintLast") == 0) {
            l.printLast();
        }
        
        else if (strcmp(input, "PrintNth") == 0) {
            //cout << "Enter a number to print : ";
            in >> num;
            l.printNth(num);
            // add search
        }
        
        else if (strcmp(input, "InvertList") == 0) {
            l.invertList();
            // add invert
        }
        
        else if (strcmp(input, "exit") == 0) {
            exit(0);
        } 
        
        else cout << "Bad Command!" << endl;
    }






}


















































