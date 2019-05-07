#include<iostream>
using namespace std;

class Node {
    private:
        int data; 
        int prio;
        Node *left; 
        Node *right;
        Node(int data) {this.data = data; left = 0; right = 0; prio = 4;}
    friend class Tree;
};

class Tree {
    private:
        Node *root;
    public:
        Tree() {root = 0;}
        ~Tree();
        
        void buildTree(int input){
            int i;
            Node *new_node = new Node(input);
            
            if (root == 0) {root = new_node;}

            for (i = 0; i < 4; i++) {
                if (new_node->data == prec[i][0]) {
                    new_node->prio = prec[i][1];
                    break;
                }
            }
            if (i==4) { Operand(new_node); }
            else { Operator(new_node); }
        }

        void Operand(Node *new_node) {
            Node *p = new_node;
            if (root == 0) {
                root = new_node;
                return;
            }
            
        }
        
        void inorder(Node *ptr){
            if (ptr) {
                inorder(ptr->left);
                cout << ptr->data;
                inorder(ptr->right);
            }
        }

        void postorder(Node *ptr){
            if (ptr) {
                postorder(ptr->left);
                postorder(ptr->right);
                cout << ptr->data;
            }
        }

        void preorder(Node *ptr){
            if (ptr) {
                cout << ptr->data;
                preorder(ptr->left);
                preorder(ptr->right);
            }
        }
}































