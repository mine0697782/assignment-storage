#include <iostream>

#define SIZE 7

using namespace std;

//const int Size = 7;

class Node
{
public:
    int data;
    Node *link;
    Node()
    {
        link = 0;
        data = 0;
    }
    Node(int input)
    {
        data = input;
    }
};

class Hashing
{
public:
    Node **Htable;

/*
    Hashing();
    int HASH(int);
    bool findKey(int);
    void insertKey(int);
    void deleteKey(int);
    void print();
*/

    Hashing()
    {
        Htable = new Node *[SIZE];
    }

    int HASH(int input)
    {
        return input % SIZE;
    }

    void insertKey(int input)
    {
        int key = HASH(input);

        Node *temp = new Node(input);

        if (Htable[key]->data == 0)
        {
            Htable[key] = temp;
        }
        else if (Htable[key]->data != 0)
        {
            Node *p = Htable[key];
            while (p->link)
            {
                p = p->link;
            }
            p->link = temp;
        }
    }

    void deleteKey(int input)
    {
        int key = HASH(input);

        if (Htable[key]->data != 0)
        {
            Node *p, *q;

            if (Htable[key]->data == input)
            {
                p = Htable[key];
                Htable[key] = Htable[key]->link;
                delete p;
            }

            p = Htable[key];

            while (p != 0 && p->data != input)
            {
                q = p;
                p = p->link;
            }
            if (p != 0)
            {
                q->link = p->link;
                delete p;
            }
            else
            {
                cout << "Data " << input << " is not found" << endl;
            }
        }
        else
        {
            cout << "Data " << input << " is not found" << endl;
        }
    }

    bool findKey(int input)
    {
        int key = HASH(input);

        if (Htable[key])
        {
            Node *p = Htable[key];

            while (p)
            {
                if (p->data == input)
                {
                    return true;
                }
                p = p->link;
            }
            return false;
        }
        else
        {
            return false;
        }
    }

    void print()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << "HTable[" << i << "] : ";
            Node *p = Htable[i];
            while (p->link)
            {
                cout << p->data << "  ->  ";
            }
            if (p)
                cout << p->data;
            cout << endl;
        }
    }
};

int main()
{
    char ch;
    int input;
    bool check;

    Hashing h;

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
            case 'i':
                h.insertKey(input);
                break;
            case 'f':
                check = h.findKey(input);
                if (check == false)
                    cout << "key not found" << endl;
                break;
            case 'd':
                h.deleteKey(input);
                break;
            default:
                cout << "Bad Command" << endl;
            }
        }
        h.print();
    } while (ch != 'q');

    return 0;
}