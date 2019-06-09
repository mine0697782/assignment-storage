#include <iostream>
using namespace std;

struct Node
{
    int key = -1;
    char data;
    Node* link = 0;
    public:
        Node();
        Node(char data) { this->data = data; }
        Node(int key, char data)
        {
            this->data = data;
            this->key = key;
        }
};

class SingleLinkedList
{
    private:
        Node *head;
    public:
        SingleLinkedList() { head = 0; }
        ~SingleLinkedList()
        {
            Node *p;
            while(head != 0)
            {
                p = head;
                head = head->link;
                delete p;
            }
        }
        void insertNode(char data, int key)
        {
            Node *temp = new Node(key, data);

            if (head == 0) head = temp;
            else
            {
                Node *p = head;
                while(p->link != 0) p = p->link;
                p->link = temp;
            }    
        }
        void deleteNode(char data)
        {
            Node *p, *q;

            if (head->data == data)
            {
                p = head;
                head = head->link;
                delete p;
            }
            else
            {
                p = head;
                while(p != 0 && p->data != data)
                {
                    q = p;
                    p = p->link;
                }
                if (p != 0)
                {
                    q->link = p->link;
                    delete p;
                }
                else cout << data << " is not in Hash.\n";
            }
        }
        bool isEmpty() {return (head == 0); }
        void traverse()
        {
            Node *p;
            if (!isEmpty())
            {
                p = head;
                while(p->link != 0)
                {
                    cout << p->data << "->";
                    p = p->link;
                }
                cout << p->data << endl;
            }
        }
        bool search(char data)
        {
            Node *p;
            if (head != 0)
            {
                p = head;
                while(p != 0 && p->data != data) p = p->link;
                if (p) return true;
                else return false;
            }
        }
};

const int HASH_SIZE = 26;
class Hash
{
    SingleLinkedList* hash_table;
    int hashFunction(char) const;
    int item_num = 0;
    public:
        Hash() { hash_table = new SingleLinkedList[HASH_SIZE]; }
        bool isEmpty();
        bool findData(char) const;
        bool insertData(char);
        bool deleteData(char);
        void printHash() const;
        friend class SingleLinkedList;
};
int Hash::hashFunction(char data) const
{
    int key = (int)data;
    if (key >= 65 && key <= 90) key += 32;
    return (key - 97);
}
bool Hash::isEmpty() { return (item_num == 0); }
bool Hash::insertData(char data)
{
    int key = hashFunction(data);
    (hash_table + key)->insertNode(data, key);
    item_num++;
}
bool Hash::deleteData(char data)
{
    if (findData(data))
    {
        int key = hashFunction(data);
        (hash_table + key)->deleteNode(data);
        item_num--;
    }
    else cout << data << " is not here!\n";
}
bool Hash::findData(char data) const
{
    int key = hashFunction(data);
    if ((hash_table + key)->isEmpty()) return false;
    else
    {
        if ((hash_table + key)->search(data)) return true;
        else return false;
    }
}
void Hash::printHash() const
{
    cout << "-----Current Hash--------" << endl;
    for (int i=0; i<HASH_SIZE; i++) (hash_table + i)->traverse();
    cout << "-------------------------" << endl;
}

int main()
{
    Hash hash;
    
    char ch;
    int input;
    bool check;

    do
    {
      cout << "Enter Command(i, f, d, q) : ";
      cin >> ch;

      if (ch != 'q')
      {
        cout << "Enter key : ";
        cin >> input;

        switch (ch)
        {
        case 'i' :
          check = hash.insertData(input);
          if (check == false) cout << "Cannot insert key" << endl;
          break;
        case 'f' :
          check = hash.findData(input);
          if (check == false) cout << "key not found" << endl;
          break;
        case 'd' :
          check = hash.deleteData(input);
          if (check == false) cout << "Cannot insert key" << endl;
          break;
        default:
          cout << "Bad Command" << endl;
      }
    }
    hash.printHash();
  } while(ch != 'q');

  return 0;
}