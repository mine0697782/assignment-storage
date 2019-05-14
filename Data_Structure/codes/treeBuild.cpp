#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

char prec[4][2]={{'*',2},{'/',2},{'+',1},{'-',1}};

class Node{
  private:
    char data;
    int prio;
    Node *left;
    Node *right;
    Node(char value){
      data=value;
      left=0;
      right=0;
    }
    friend class Tree;
};

class Tree{
private:
  Node *root;
public:
  Tree(){root=0;};
  void buildTree(string);
  void inputoperand(Node*);
  void inputoperator(Node*);
  void inorder(Node*);
  Node* getroot();
  void postorder(Node*);
  void preorder(Node*);
  int evaltree(Node*);
};

void Tree::buildTree(string input){
  for(int i=0;input[i]!='\0';i++){
    cout << input[i] << endl;
    Node *temp = new Node(input[i]);

    temp->prio=4;
    for(int j=0;j<4;j++){
      if(temp->data==prec[j][0]){
        temp->prio=prec[j][1];
      }
    }

    if(temp->prio==4){
      inputoperand(temp);
    }else{
      inputoperator(temp);
    }

  }
}

void Tree::inputoperand(Node *input){
  cout << "ok1" << endl;
  if(root==0){
    root=input;
  }else{
    Node *p=root;
    while(p->right !=0){p=p->right;}
    p->right=input;
  }
}

void Tree::inputoperator(Node *input){
  cout << "ok2" << endl;
  if(root->prio >= input->prio){
    input->left=root;
    root=input;
  }else{
    input->left=root->right;
    root->right=input;
  }
}


void Tree::inorder(Node *ptr){
  if(ptr){
    inorder(ptr->left);
    cout << ptr->data;
    inorder(ptr->right);
  }
}

Node* Tree::getroot(){
  return root;
}

void Tree::postorder(Node *ptr){
  if(ptr){
    {
      postorder(ptr->left);
      postorder(ptr->right);
      cout << ptr->data;
    }
  }
}

void Tree::preorder(Node *ptr){
  if(ptr){
    cout << ptr->data;
    preorder(ptr->left);
    preorder(ptr->right);
  }
}

int Tree::evaltree(Node *p){
  int value;
  if(p!=0){
    if(p->data == '0' || p->data == '1' || p->data == '2' || p->data == '3' || p->data == '4' || p->data == '5' || p->data == '6' || p->data == '7' || p->data == '8' || p->data=='9'){
      value = p->data-'0';
    }else{
      int left = evaltree(p->left);
      int right = evaltree(p->right);
      switch(p->data){
        case '+':
          value=left+right;
          break;
        case '-':
          value=left-right;
          break;
        case '*':
          value=left*right;
          break;
        case '/':
          value=left/right;
          break;
      }

      cout << "left : " << left << " right : " << right << " return : " << value << endl;
    }
  }else{
    cout << "Empty tree" << endl;
  }
  cout << value << endl;

  return value;
}



int main(){


  string expression;
  cin >> expression;

  Tree tree1;
  cout << expression << endl;
  tree1.buildTree(expression);
  tree1.inorder(tree1.getroot());
  cout<< endl;
  tree1.postorder(tree1.getroot());
  cout << endl;
  tree1.preorder(tree1.getroot());
  cout << endl;
  tree1.evaltree(tree1.getroot());
  cout << endl;

  return 0;
}
