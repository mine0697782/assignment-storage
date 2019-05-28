#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

class Node{
public:
    int data;
    Node *link;
    Node(int value){
      data=value;
      link=0;
    }
    friend class Tree;
};

class Tree{
private:

public:
  Node* root;
  Tree();
  Node* graph[6];
  bool visited[6];
  void dfs(int);
  void insert(int,int);
  void printTree();
};

Tree::Tree(){
  root=0;
  for(int i=0;i<6;i++){
    visited[i]=false;
    Node* p=new Node(i);
    graph[i]=p;
  }
};



void Tree::dfs(int v){
  visited[v]=true;
  cout << "v" << v << " ";

  Node *w;
  for(w=graph[v];w!=0;w=w->link){
    if(!visited[w->data]){
      dfs(w->data);
    }
  }

}

void Tree::insert(int to,int input){
    Node *p=graph[to];
    while(p->link!=0){
      p=p->link;
    }
    Node* ptr = new Node(input);
    p->link=ptr;
    Node *q=graph[input];
    while(q->link!=0){
    q=q->link;
    }
    Node* ptr2 = new Node(to);
    q->link = ptr2;

}

void Tree::printTree(){
    for(int i=0;i<6;i++){
        Node* p=graph[i];

        cout << i << " : ";

        while(p->link!=0){
        cout << p->link->data << "->";
        p=p->link;
        }
        cout << endl;
    }
}


int main(){

    Tree tree;

    ifstream in;
    in.open("Lab9_text.txt");

    int n1, n2;
    for (int i=0; i<8; i++){
        in >> n1 >> n2;
        tree.insert(n1, n2);
    }
    
    cout << "input start number" << endl;
    int startnum;
    cin >> startnum;
    tree.dfs(startnum);
    cout << endl;

    return 0;
}
