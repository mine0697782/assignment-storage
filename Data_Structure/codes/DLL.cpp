#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

typedef int Type;

class Node{
    private:
        Type data;
        Node *next;
        Node *prev;
        Node(Type data) {this->data = data; next = 0; prev = 0;}
    friend class List;
};

class List {
    private:
        Node *head;
    public:
        List() {head = 0; /*current = 0;*/}
        
        ~List() {
            Node *p;
            
            while(head != 0) {
                p = head;
                head = head->next;
                delete p;
            }
        }
    
        int isEmpty() {return (head == 0);}

        int listLength() {
            Node *p = head;
            int count = 0;
            
            while(p){
                count++;
                if (p->next != 0)
                    p = p->next;
                else break;
            }
            return count;
        }

        void insertFirst(Type data) {
            Node *temp = new Node(data);

            if (head == 0) head = temp;
            else {
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
        }

        void insertLast(Type data) {
            Node *temp = new Node(data);
            Node *p;

            if (head == 0) head = temp;
            else {
                p = head;
                while (p->next != 0) p = p->next;
                p->next = temp;
                temp->prev = p;
            }
        }

        void insertList(Type data) {
            Node *temp = new Node(data/*, name*/); // what's the name?
            Node *p, *q;
            
            //cout << "1" << endl;//

            if (head == 0) { //if it is First node
                //cout << "1-1" << endl;//
                head = temp;
            } 
            else if (temp->data < head->data) { // put in front of head node
                //cout << "2" << endl; //
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
            else { // put in the middle
                //cout << "3" << endl; //
                p = head;
                q = head;
                while ((p != 0) && (p->data < temp->data)) { // move
                    //cout << "4" << endl;//
                    q = p;
                    p = p->next;
                }
            

            if (p != 0) { // put on array (middle?)
                //cout << "5" << endl; //
                temp->next = p;
                //cout << "5-1" << endl; //
                temp->prev = q;
                //cout << "5-2" << endl; //
                //cout << q->next << endl; // 1
                //cout << temp << endl; // 2
                q->next = temp;
                //cout << "5-3" << endl; //
                p->prev = temp;
                //cout << "5-4" << endl; // 
            }
            else { // if temp is bigger
                //cout << "6" << endl;//
                q->next = temp;
                temp->prev = q;
            }
            //cout << "7" << endl;//
            }
        }

        void deleteList(int key){
            Node *p, *q;

            if (head == 0) {cout << "List is empty!" << endl;}
            else {
                if (head->data == key) { // if head will be deleted
                    if (head->next != 0) { // if head won't be deleted
                        p = head;
                        head = head->next;
                        head->prev = 0;
                    }
                    else head = 0;
                }
                else { // if the middle node will be deleted
                    q = head;
                    p = head;
                    while(p != 0 && p->data != key){ //move
                        q = p;
                        p = p->next;
                    }
                    if (p->next != 0 && p->data == key) {
                        q->next = p->next;
                        p->next->prev = q;
                        delete p;
                    }
                    else if (p->next == 0 && p->data == key) {
                        q->next = 0;
                        delete p;
                    }
                    else cout << key << " is not in the list" << endl;
                }
            }

        }

        void forwardList(){
            if(!isEmpty()) {
                Node *p = head;
                cout << "---- Forward List ----" << endl;
                while(p != 0){
                    cout << p->data << " "/* << p->name << endl*/;
                    p = p->next;
                }
                cout << endl;
            }
            else cout << "List is empty!" << endl;
        }

        void backwardList() {
            if (!isEmpty()) {
                Node *p = head;
                while (p->next != 0)
                    p = p->next;
                cout << "---- Backward List ----" << endl;
                while (p != 0) {
                    cout << p->data << " "/* << p->name << endl*/;
                    p = p->prev;
                }
                cout << endl;
            }
            else cout << "List is empty!" << endl;
        }

        void searchList(int key){
            if (!isEmpty()) {
                Node *p = head;
                while (p != 0 && p->data != key) p = p->next;

                if (p != 0)
                    cout << p->data << " is in the list" << endl;
                else cout << key << " is not in the list" << endl;
            }
            else cout << "List is empty!" << endl;
        }

        void locateCurrent(int Nth) {
            Node *p;
            int pos = 1;

            if (head == 0) cout << "List is empty!" << endl;
            else if (listLength() >= Nth) { // add listLength func $$$$$$$$$$$$$$$$$$$$$
                p = head;
                while (pos != Nth) {p = p->next; pos++;}
            cout << pos << "*";
            cout << p->data << endl;
            }
        }
};

main() {
    char input[20];
    List list = List();
    int data;
    
    while(1){
        cout << "\nMenu (insertFirst, insertLast, insertList, delete, forward, backward, search, locationNth, exit)" << endl;
        cout << "Command : ";
        cin >> input;


        if (strcmp(input,"insertFirst") == 0){
            cin >> data;
            list.insertFirst(data);
        }
        
        else if (strcmp(input,"insertLast") == 0){
            cin >> data;
            list.insertLast(data);
        }
        
        else if (strcmp(input,"insertList") == 0){
            cin >> data;
            list.insertList(data);
        }
        
        else if (strcmp(input,"delete") == 0){
            cin >> data;
            list.deleteList(data);
        }
        
        else if (strcmp(input,"forward") == 0){
            list.forwardList();
        }
        
        else if (strcmp(input,"backward") == 0){
            list.backwardList();
        }
        
        else if (strcmp(input,"search") == 0){
            cin >> data;
            list.searchList(data);
        }
        
        else if (strcmp(input,"locationNth") == 0){
            cin >> data;
            list.locateCurrent(data);
        }
        
        else if (strcmp(input,"exit") == 0){
            exit(0);
        }
        
        else cout << "Bad Command!" << endl;
    }
}




































