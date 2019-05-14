#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

char prec[4][2] = {{'*', 2},{'/', 2},{'+', 1},{'-', 1}};


class Node {
    private:
        char data; 
        //int prio;
        Node *left; 
        Node *right;
        int left_thread;
        int right_thread;
        Node(char data) {this->data = data; left = 0; right = 0;}
    friend class Tree;
};

class Tree {
    private:
        Node *root;
    public:
        Tree() {root = 0;}
        //~Tree();
        void buildTree(char *input);
        void input_operand(Node *new_node);
        void input_operator(Node *new_node);
        void inorder(Node *p);
        void postorder(Node *p);
        void preorder(Node *p);
        int evalTree(Node *p);
        Node *getroot();
        void DrawTree(Node *p, int level);
};

void Tree::buildTree(char *input){
    for (int i = 0; i < strlen(input); i++) {
        cout << "Now " << i+1 << "th input(char) : " << input[i] << endl;
        Node *new_node = new Node(input[i]);
        
        new_node->prio = 4;
        for (int i = 0; i < 4; i++) {
            if (new_node->data == prec[i][0]){
                new_node->prio = prec[i][1];
            }
        }

        if (new_node->prio == 4){
            input_operand(new_node);
        }
        else {
            input_operator(new_node);
        }
    }
}

void Tree::input_operand(Node *new_node) {
    cout << "input Operand called" << endl;
    if (root == 0) {
        cout << "root initialized" << endl;
        root = new_node;
    }
    else {
        Node *p = root;
        while(p->right) {p = p->right;}
        p->right = new_node;
    }
}

void Tree::input_operator(Node *new_node) {
    cout << "input Operator called" << endl;
    if (root->prio >= new_node->prio) {
        new_node->left = root;
        root = new_node;
    }
    else {
        new_node->left = root->right;
        root->right = new_node;
    }
}

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

int Tree::evalTree(Node *p){
    int value;
    if (p) {
        if (0 <= p->data - '0' && p->data - '0' < 10) { // Operand //
            value = p->data - '0';
        }
        else { // Operator //
            int left = evalTree(p->left);
            int right = evalTree(p->right);
            switch(p->data) {
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
            //cout << "left : " << left << " right : " << right << " return : " << value << endl;
        }
    }
    else {
        cout << "Empty tree" << endl;
    }
    //cout << value << endl;

    return value;
}

Node * Tree::getroot() {
    return root;
}

void Tree::DrawTree(Node *p, int level) {
    if (p != 0) {
        DrawTree (p->right, level + 1);
        for (int i = 1; i <= level-1; i++) {
            cout << "    ";
        }

        cout << p->data;

        if (p->left != 0 && p->right != 0) {
            cout << "  <  ";
        }
        else if (p->right != 0) {
            cout << "/";
        }
        else if (p->left != 0) {
            cout << "\\";
        }
        
        cout << endl;
        DrawTree(p->left, level + 1);
        //cout << endl;
        
    }
}

int main() {
    char expression[50];
    cout << "Enter Expression : ";
    cin >> expression;

    Tree tree;
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
    
    cout << "Tree Structure" << endl << endl;
    tree.DrawTree(tree.getroot(), 1);
    cout << endl;

    return 0;
}



























