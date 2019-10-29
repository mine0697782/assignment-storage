// 이진 트리
// 수식 계산, 연산자

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

char prec[4][2] = {'*', 2, '/', 2, '+', 1, '-', 1};

class Node{
    //private:
    public:
        char data;
        int prio;
        Node *left;
        Node *right;
        Node(int value){data = value; prio = 0; left = 0; right = 0;}

    friend class Tree;
};

class Tree{
    private:
        Node *root;
    public:
        Tree(){root = 0;}
        void buildTree(char*);
        void input_operand(Node *);
        void input_operator(Node *);
        int evalTree(Node *);        
        void drawTree(Node *, int);        
        Node *getroot(){return root;}
        void inorder(Node *);
        void postorder(Node *);
        void preorder(Node *);

};

void Tree::buildTree(char *input){
    //cout << strlen(input) << endl;;
    //cout << sizeof(input) << " " << sizeof(input[0]) << endl;
    for (int i = 0; i < strlen(input); i++){
        Node *new_node = new Node(input[i]);
        new_node->prio = 4;
        for (int i = 0; i < 3; i++){
            if (new_node->data == prec[i][0]){
                new_node->prio = prec[i][1];
            }
        }
        if (new_node->prio == 4){ // warning, i == 4
            input_operand(new_node);
        }
        else {
            input_operator(new_node);
        }
    }
}

void Tree::input_operand(Node *new_node){
    if (root == 0){
        root = new_node;
        return;
    }
    Node *p = root;
    while(p->right != 0) {
        p = p->right;
    }
    p->right = new_node;
}

void Tree::input_operator(Node *new_node){
    if (root->prio >= new_node->prio){
        new_node->left = root;
        root = new_node;
    }
    else {
        new_node->left = root->right;
        root->right = new_node;
    }
}

int Tree::evalTree(Node *p){
    int left, right, value;
    if (p) {
        if (p->data >= '0' && p->data <= '9'){
            value = p->data - '0';
        }
        else {
            left = evalTree(p->left);
            right = evalTree(p->right);
            switch (p->data) {
                case '+':
                    value = left + right;
                    break;
                case '-':
                    value = left - right;
                    break;
                case '*':
                    value = left * right;
                    break;
                case '/':
                    value = left / right;
                    break;
            }
        }
    }
    else {
        cout << "Empty Tree" << endl;
    }
    return value;
}

void Tree::drawTree(Node *p, int level){
    if (p != 0 && level <= 7) {
        drawTree(p->right, level+1);
        for (int i = 0; i < (level-1); i++){
            cout << "    ";
        }
        cout << p->data;
        if (p->left != 0 && p->right != 0)  cout << " <" << endl;
        else if (p->right != 0)             cout << " /" << endl;
        else if (p->left != 0)              cout << " \\"<< endl;
        else                                cout << endl;
        drawTree(p->left, level+1);
    }
}

void Tree::inorder(Node *p){
    if (p){
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

void Tree::postorder(Node *p){
    if (p){
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }
}

void Tree::preorder(Node *p){
    if (p){
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

main(){
    ifstream in;
    char input[100];
    Tree tree;

    in.open("Binary_Tree_Operator_input.txt");
    while(in.getline(input,100)){
        //input = "3+2"; //
        cout << "input : " << input << endl;
        tree.buildTree(input);
        cout << "root : " << tree.getroot()->data << endl;
        tree.drawTree(tree.getroot(), 1);
        cout << "inorder   : ";
        tree.inorder(tree.getroot());
        cout << "\npostorder : ";
        tree.postorder(tree.getroot());
        cout << "\npreorder  : ";
        tree.preorder(tree.getroot());
        cout << "\nResult    : " << tree.evalTree(tree.getroot()) << endl;
    }
    return 0;
}
