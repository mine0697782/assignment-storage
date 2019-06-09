#include <iostream>
using namespace std;

struct Node
{
    int key;
    int data;
    Node* link;
    public:
        Node();
        Node(int data) {
            this -> key = 0;
            this -> data = data;
            this -> link = 0;
        }
        Node(int key, int data)
        {
            this -> data = data;
            this -> key = key;
            this -> link = 0;
        }
};

class SLL
{
    private:
        Node *head;
    public:
        SLL() { head = 0; }
        ~SLL()
        {
            Node *p;
            while(head != 0)
            {
                p = head;
                head = head -> link;
                delete p;
            }
        }
        void insert_node(int data, int key)
        {
            Node *temp = new Node(key, data);

            if (head == 0) head = temp;
            else
            {
                Node *p = head;
                while(p -> link != 0) p = p -> link;
                p -> link = temp;
            }    
        }
        void delete_node(int data)
        {
            Node *p, *q;

            if (head -> data == data)
            {
                p = head;
                head = head -> link;
                delete p;
            }
            if(true)
            {
                p = head;
                while(p != 0 && p -> data != data)
                {
                    q = p;
                    p = p -> link;
                }
                if (p != 0)
                {
                    q -> link = p -> link;
                    delete p;
                }
                else cout << data << " is not in Hash.\n";
            }
        }
        bool isEmpty() {return head == 0; }
        void traverse()
        {
            Node *p;
            if (!isEmpty())
            {
                p = head;
                while(p -> link != 0)
                {
                    cout << p -> data << " -> ";
                    p = p -> link;
                }
                cout << p -> data;
            }
        }
        bool search(int data)
        {
            Node *p;
            if (head != 0)
            {
                p = head;
                while(p != 0 && p -> data != data) p = p -> link;
                if (p) return true;
                else return false;
            }
        }
        friend class Hash;
};

const int HASH_SIZE = 7;
class Hash
{
    SLL* Htable;
    int key_num;
    public:
        Hash() {
            Htable = new SLL[HASH_SIZE];
            key_num = 0;
        }
        int hash_function(int data){
            return data % 7;
        }
        bool isEmpty(){
            return key_num == 0;
        }
        void insert(int data){
            int key = hash_function(data);
            (Htable + key) -> insert_node(data, key);
            key_num++;
        }
        void Delete(int data){
            if (find(data) == true){
                int key = hash_function(data);
                (Htable + key) -> delete_node(data);
                key_num--;
            }
            else cout << data << " is not found\n";
        }
        bool find(int data){
            int key = hash_function(data);
            if ((Htable + key) -> isEmpty()) return false;
            else {
                if ((Htable + key) -> search(data)) return true;
                else return false;
            }
        }
        void print() {
            cout << "-------------------------" << endl;
            for (int i = 0 ; i < HASH_SIZE ; i++){
                cout << "Htable[" << i << "] : ";
                (Htable + i) -> traverse();
                cout << endl;
            }
            cout << "-------------------------" << endl;
        }
};

int main()
{
    char c;
    int n;
    Hash hash;
    
    while(true){
        cout << "입력하세요. (i, d, f, q)" << endl;
        cin >> c;
        if(c == 'i'){
            cin >> n;
            hash.insert(n);
        }
        else if(c == 'f'){
            cin >> n;
            if(hash.find(n) == true) cout << "key found" << endl;
            else cout << "key not found" << endl;
        }
        else if(c == 'd'){
            cin >> n;
            hash.Delete(n);
        }
        else if(c == 'q') break;
        else cout << "잘못된 명령어 입니다. 다시 입력하세요." << endl;
        hash.print();
    }
    return 0;
}
