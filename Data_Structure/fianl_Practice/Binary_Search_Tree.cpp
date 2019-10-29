#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(){left = 0; right = 0;}
        Node(int input){data = input; left = 0; right = 0;}
};

class Tree{
    private:
        Node *root;
    public:
        Tree() {root = 0;}
        
        Node *searchTree(Node *p, int key);
        Node *insertTree(Node *p, int key);
        Node *deleteTree(Node *p, int key);
        void drawTree(Node *p, int level);
        int empty();
        Node *find_min(Node *p);
        Node *getroot(){return root;}
};

Node *Tree::searchTree(Node *p, int key){
    if (p == NULL){
        return NULL;
    }
    else {
        if (key == p->data) return p;
        else if (key < p->data) p = searchTree(p->left, key);
        else if (key > p->data) p = searchTree(p->right, key);
    }
    return p;
}

Node *Tree::insertTree(Node *p, int key){
    if (p == NULL){
        p = new Node(key);
    }
    else if (key < p->data) p->left = insertTree(p->left, key);
    else if (key > p->data) p->right = insertTree(p->right, key);

    return p;
}

Node *Tree::deleteTree(Node *p, int key){
    if (p != NULL) {
        if (key < p->data)      p->left = deleteTree(p->left, key);
        else if (key > p->data) p->right = deleteTree(p->right, key);
        
        else if ((p->left == NULL) && (p->right == NULL))   p = NULL;
        else if (p->left == NULL){
            Node *temp = p;
            p = p->right;
            delete(temp);
        }
        else if (p->right == NULL){
            Node *temp = p;
            p = p->left;
            delete(temp);
        }
        else {
            Node *temp = find_min(p->right);
            p->data = temp->data;
            p->right = deleteTree(p->right, p->data);
        }
    }
    else cout << "Not found" << endl;
}

void Tree::drawTree(Node *p, int level) {
    cout << "1" << endl;
    if (p != 0 && level <= 7){
        drawTree(p->right, level+1);
        for (int i=1; i<=(level-1); i++){
            cout << "   ";
        }
        cout << p->data;
        if (p->left != 0 && p->right != 0)  cout << " <" << endl;
        else if (p->right != 0)             cout << " /" << endl;
        else if (p->left != 0)              cout << " \\"<< endl;
        else                                cout << endl;
        drawTree(p->left, level+1);
    }
    cout << "2" << endl;
}

Node *Tree::find_min(Node *p){
    if (p->left == NULL){
        return p;
    }
    else find_min(p->left);
}

main(){
    char input[20];
    int key;
    Tree tree;

    cout << "Enter (insert, search, delete, print)" << endl;
    while(1){
        cin >> input;
        if (strcmp(input,"insert") == 0){
            cin >> key;
            tree.insertTree(tree.getroot(), key);
        }
        else if (strcmp(input,"search") == 0){
            cin >> key;
            tree.searchTree(tree.getroot(), key);
        }
        else if (strcmp(input,"delete") == 0){
            cin >> key;
            tree.deleteTree(tree.getroot(), key);
        }
        else if (strcmp(input,"print") == 0){
            tree.drawTree(tree.getroot(), 1);
        }
    }
    
}
