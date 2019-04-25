#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

struct Person {
    char name[20];
    int weight;
    int height;
};

typedef Person Type;

class Node{
    private:
        Person data;
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

        void insertFirst(Person data) {
            Node *temp = new Node(data);

            if (head == 0) head = temp;
            else {
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
        }

        void insertLast(Person data) {
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

        void insertList(Person data) {
            Node *temp = new Node(data/*, name*/); // what's the name?
            Node *p, *q;
            
            //cout << "1" << endl;//

            if (head == 0) { //if it is First node
                //cout << "1-1" << endl;//
                head = temp;
            } 
            else if (strcmp(temp->data.name,head->data.name) < 0) { // put in front of head node
                //cout << "2" << endl; //
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
            else { // put in the middle
                //cout << "3" << endl; //
                p = head;
                q = head;
                while ((p != 0) && (strcmp(p->data.name, temp->data.name)) < 0) { // move
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

        void deleteList(char *key){
            Node *p, *q;

            if (head == 0) {cout << "List is empty!" << endl;}
            else {
                if (strcmp(head->data.name, key) == 0) { // if head will be deleted
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
                    while(p != 0 && strcmp(p->data.name, key) != 0){ //move
                        q = p;
                        p = p->next;
                    }
                    if (p->next != 0 && strcmp(p->data.name, key) == 0) {
                        q->next = p->next;
                        p->next->prev = q;
                        delete p;
                    }
                    else if (p->next == 0 && strcmp(p->data.name, key) == 0) {
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
                    cout << p->data.name << " " << p->data.weight << " " << p->data.height << endl;
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
                    cout << p->data.name << " " << p->data.weight << " " << p->data.height << endl;
                    p = p->prev;
                }
                cout << endl;
            }
            else cout << "List is empty!" << endl;
        }

        void searchList(char *key){
            if (!isEmpty()) {
                Node *p = head;
                while (p != 0 && strcmp(p->data.name, key) != 0) p = p->next;

                if (p != 0)
                    cout << p->data.name << " is in the list" << endl;
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
            cout << p->data.name << " " << p->data.weight << " " << p->data.height << endl;
            }
        }

        void insertAfterNth(int Nth, Person data) {
            Node *temp = new Node(data);
            Node *p;
            p = head;

            if (!isEmpty()) {
                for (int i = 0; i < Nth-1; i++) {
                    if (p->next){
                        p = p->next;
                    }
                    else cout << "List is less then N" << endl;
                }
                temp->next = p->next;
                temp->prev = p;

                p->next->prev = temp;
                p->next = temp;
            }
            else cout << "List is empty!" << endl;
        }
};

main() {
    char input[20];
    int num;
    List list = List();
    Person data;
   
    ifstream in;
    in.open("Lab6_example.txt");
    for (int i = 0; i < 4; i++){
        in >> data.name >> data.weight >> data.height;
        list.insertList(data);
    }
    
    while(1){
        cout << "\nMenu (insertList, insertAfterNth, delete, forward, backward, search, find, exit)" << endl;
        cout << "Command : ";
        cin >> input;

        
        if (strcmp(input,"insertList") == 0){
            cin >> data.name >> data.weight >> data.height;
            list.insertList(data);
        }
        
        else if (strcmp(input,"insertAfterNth") == 0){
            cout << "enter N : ";
            cin >> num;
            cout << "enter data : ";
            cin >> data.name >> data.weight >> data.height;
            list.insertAfterNth(num, data);
        }


        else if (strcmp(input,"delete") == 0){
            cin >> input;
            list.deleteList(input);
        }
        
        else if (strcmp(input,"forward") == 0){
            list.forwardList();
        }
        
        else if (strcmp(input,"backward") == 0){
            list.backwardList();
        }
        
        else if (strcmp(input,"search") == 0){
            cin >> input;
            list.searchList(input);
        }
        
        else if (strcmp(input,"find") == 0){
            cin >> num;
            list.locateCurrent(num);
        }
        
        else if (strcmp(input,"exit") == 0){
            exit(0);
        }
        
        else cout << "Bad Command!" << endl;
        
    }
}




































