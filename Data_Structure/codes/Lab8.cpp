#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>

using namespace std;

char prec[4][2] = {{'*', 2},{'/', 2},{'+', 1},{'-', 1}};


class Node {
    private:
        int data; 
        int prio;
        Node *left; 
        Node *right;
        Node(int data) {this->data = data; left = NULL; right = NULL;}
    friend class Tree;
};

class Tree {
    private:
        Node *root;
    public:
        Tree() {root = NULL;}
        //~Tree();
        Node *insert(Node *, int);
        Node *deleteBSTree(Node *, int);
        Node *search(Node *, int key);
        void drawTree();
        void drawBSTree(Node *, int);
        Node *find_min(Node *p);
        int tree_empty();
        void freeBSTree(Node *);
        Node *getroot();
        int leaf(Node *);

        void inorder(Node *p);
        void postorder(Node *p);
        void preorder(Node *p);
        //Node *getroot();
};

//Tree::~Tree() {/*freeBSTree(root);*/}

Node *Tree::search(Node *ptr, int key){
    if (ptr == NULL) return NULL;
    else {
        if (key == ptr->data) return ptr;
        else if (key < ptr->data) {
            ptr = search(ptr->left, key);
        }
        else if (key > ptr->data) {
            ptr = search(ptr->right, key);
        }
    }
    return ptr;
}

Node *Tree::insert(Node *ptr, int key){
    
    if (ptr == NULL) {
        //cout << "insert 1" << endl;
        //Node *new_node = new Node(key);
        //ptr = new_node;
        ptr =  new Node(key);
        if(root == 0){
            root = ptr;
        }
        cout << ptr->data << endl;
    }
    else if (key < ptr->data) {
        //cout << "insert 2" << endl;
        ptr->left = insert(ptr->left, key);
        //cout << "inserted data : " << ptr->left->data << endl;

    }
    else if (key > ptr->data) {
        //cout << "insert 3" << endl;
        ptr->right = insert(ptr->right, key);
        //cout << "inserted data : " << ptr->right->data << endl;
    }

    return ptr;
}

Node *Tree::deleteBSTree(Node *ptr, int key){
    if (ptr != NULL) {
        if (key < ptr->data) {
            ptr->left = deleteBSTree(ptr->left, key);
        }
        else if (key > ptr->data){
            ptr->right = deleteBSTree(ptr->right, key);
        }
        else if ((ptr->left == NULL) && (ptr->right == NULL)) {
            ptr = NULL; // leaf
        }
        else if (ptr->left == NULL) {
            Node *p = ptr; 
            ptr = ptr->right;
            delete(p); // rightchild only
        }
        else if (ptr->right == NULL) {
            Node *p = ptr;
            ptr = ptr->left;
            delete(p); // leftchild only
        }
        else {
            Node *temp = find_min(ptr->right); // both child exists
            ptr->data = temp->data;
            ptr->right = deleteBSTree(ptr->right, ptr->data);
        }
    }
    else {
        cout << "Not Found" << endl;
    }
    return ptr;
}

Node *Tree::find_min(Node *p){
    if (p->left == NULL){
        return p;
    }
    else {
        find_min(p->left);
    }
}

void Tree::drawTree() {
    cout << "drawtree" << endl;
    drawBSTree(getroot(), 1);
}

void Tree::drawBSTree(Node *p, int level) {
    //cout << "drawBST" << endl;
    if (p != 0 && level <= 7) {
        //cout << "111" << endl;
        drawBSTree(p->right, level+1);
        for (int i=1; i<=(level-1); i++){
            cout << "    ";
        }
        cout << p->data;
        if (p->left != 0 && p->right != 0) cout << "<" << endl;
        else if (p->right != 0) cout << "/" << endl;
        else if (p->left != 0) cout << "\\" << endl;
        else cout << endl;
        drawBSTree(p->left, level+1);
    }
    else{
        //cout << "222" << endl;
    }
}

Node * Tree::getroot(){
    return root;
}

int Tree::tree_empty() {
    if (root == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int Tree::leaf(Node *p){
    int count = 0;
    if(tree_empty()){
        return 0;
    }
    else if(p){
        if(p->left == NULL && p->right == NULL){
            count++;
        }
        else { 
            count = leaf(p->left) + leaf(p->right);
        }
    }
    return count;
}


////////////////////////////////////////////////////////////////

void Tree::inorder(Node *p){
    if (p) {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

void Tree::postorder(Node *p){
    if (p) {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }
}

void Tree::preorder(Node *p){
    if (p) {
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

int main() {
    int input;
    char command[20];
    Tree tree;

    while(1){
        cout << "\nMenu(insert, delete, search, print, traverse, leaf, quit)" << endl;
        cout << "Enter a command : ";
        cin >> command;

        if (strcmp(command, "insert") == 0) {
            //cout << "Enter number to insert : ";
            cin >> input;
            tree.insert(tree.getroot(), input);
        }
        else if (strcmp(command, "delete") == 0) {
            if (!tree.tree_empty()){
                //cout << "Enter number to delete : ";
                cin >> input;
                tree.deleteBSTree(tree.getroot(), input);
            }
            else {
                cout << "Tree is empty!" << endl;
            }
        }
        else if (strcmp(command, "search") == 0) {
            if (!tree.tree_empty()){
                //cout << "Emter number to search : ";
                cin >> input;
                Node * temp = tree.search(tree.getroot(), input);
                
                if (temp == NULL){
                    cout << "Not found" << endl;
                }
                else {
                    cout << "Number is found" << endl;
                }
            }
            else {
                cout << "Tree is empty!" << endl;
            }
        }
        else if (strcmp(command, "print") == 0) {
            tree.drawTree();
        }
        else if (strcmp(command, "traverse") == 0) {
            if (!tree.tree_empty()) {
                cout << "inorder : ";
                tree.inorder(tree.getroot());
                cout << "\npostorder : ";
                tree.preorder(tree.getroot());
                cout << "\npreorder : ";
                tree.postorder(tree.getroot());
            }
            else {
                cout << "Tree is empty!" << endl;
            }
        }
        else if (strcmp(command, "leaf") == 0) {
            cout << "leaf : " << tree.leaf(tree.getroot()) << endl;
        }
        else if (strcmp(command, "quit") == 0) {
            exit(0);        
        }
        else {
            cout << "Bad Command!" << endl;
        }
        //cout << "pre :";
        //tree.preorder(tree.getroot());
        //cout << endl;
        }
    tree.drawTree();


    /*
    cout << "Now Expression Get : " << expression << endl;
    tree.buildTree(expression);
    cout << endl;
    
    cout << "  InOrder exp \t: ";
    tree.inorder(tree.getroot());
    cout << endl << endl;

    cout << "  PostOrder exp\t: ";
    tree.postorder(tree.getroot());
    cout << endl << endl;

    cout << "  PreOrder exp \t: ";
    tree.preorder(tree.getroot());
    cout << endl << endl;

    cout << "  Evaluation : " << tree.evalTree(tree.getroot()) << endl << endl;
    
    cout << "  Parentheses \t: ";
    tree.parentheses(tree.getroot());
    cout << endl << endl;

    cout << "Tree Structure" << endl << endl;
    tree.DrawTree(tree.getroot(), 1);
    cout << endl;
    */

    return 0;
}



























