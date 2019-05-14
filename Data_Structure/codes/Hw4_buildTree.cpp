#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

char prec[4][2] = {{'*', 2},{'/', 2},{'+', 1},{'-', 1}};


class Node {
    private:
        char data;          // 숫자나 연산자를 저장하는 변수
        int prio;           // 데이터의 연산 우선 순위
        Node *left;         // 왼쪽 자식 노드
        Node *right;        // 오른족 자식 노드
        Node(char data) {   // 입력받은 데이터로 새로운 노드 생성
            this->data = data; left = 0; right = 0;
        }
    friend class Tree; // Tree 클래스에서 접근 가능
};

class Tree {
    private:
        Node *root;        // 트리의 맨 위(첫번째) 노드를 가리키는 포인터
    public:
        Tree() {root = 0;} 
        void buildTree(char *input);            // input으로 받은 데이터를 판별하여 내부에서 operand와 operator 함수를 호출
        void input_operand(Node *new_node);     // operand(피연산자)를 트리에 연결하는 함수
        void input_operator(Node *new_node);    // operator(연산자)를 트리에 연결하는 함수
        void inorder(Node *p);                  // 트리를 중위 표기법으로 출력하는 함수
        void postorder(Node *p);                // 트리를 후위 표기법으로 출력하는 함수
        void preorder(Node *p);                 // 트리를 전위 표기법으로 출력하는 함수
        int evalTree(Node *p);                  // 입력받은 수식을 계산하여 결과를 출력하는 함수
        Node *getroot();                        // root의 주소를 반환하는 함수
        void DrawTree(Node *p, int level);      // Tree를 반시계 방향으로 90도 눕힌 모양으로 출력하는 함수
};

void Tree::buildTree(char *input){              // input을 받아서 트리를 생성하는 함수
    for (int i = 0; i < strlen(input); i++) {   // 공백 없이 입력받은 데이터에 한자리씩 접근
        cout << "Now " << i+1 << "th input(char) : " << input[i] << endl; // 올바른 데이터인지 체크하기 위한 출력문
        Node *new_node = new Node(input[i]);    // 함수 밖에서도 접근해야 하는 노드를 new_node로 동적할당함
        
        new_node->prio = 4;                     // 처음 우선순위를 기본적으로 4로 지정
        for (int i = 0; i < 4; i++) {           // 노드의 데이터를 미리 만들어진 prec 배열의 값과 비교
            if (new_node->data == prec[i][0]){  // 연산자일 경우 그 연산자에 맞게 연산 우선순위 설정
                new_node->prio = prec[i][1];    // +, - 일 경우 prio를 1로, * 이나 / 일 경우 prio를 2로 설정
            }
        }

        if (new_node->prio == 4){               // 데이터가 피연산자(숫자)인 경우 prec과 매치되지 않기 때문에 prio가 4로 남아있음
            input_operand(new_node);            // new_node를 숫자를 삽입하는 함수의 인자로 전달하여 호출
        }
        else {                                  // 데이터가 연산자일 경우
            input_operator(new_node);           // new_node를 연산자를 삽입하는 함수의 인자로 전달하여 호출
        }
    }
}

void Tree::input_operand(Node *new_node) {      // 피연산자(숫자)를 트리에 삽입하는 함수
    cout << "input Operand called" << endl;     // 알고리즘이 정상적으로 돌아가는지 확인하기 위한 출력문
    if (root == 0) {                            // 트리에 노드가 존재하지 않는 경우
        cout << "root initialized" << endl;     // 디버깅 트리가 초기화됨을 알리는 출력문
        root = new_node;                        // 새로 입력받은 노드를 root로 설정
    }
    else {                                      // 트리에 노드가 존재할 경우
        Node *p = root;                         // root를 가리키는 포인터 p를 선언
        while(p->right) {p = p->right;}         // p(현재 바라보는 노드)의 오른쪽 자식 노드가 없을때까지 오른쪽으로 이동
        p->right = new_node;                    // p의 오른쪽 노드가 없으면 새로운 노드를 right로 설정
    }
}

void Tree::input_operator(Node *new_node) {     // 연산자를 트리에 삽입하는 함수
    cout << "input Operator called" << endl;    // 알고리즘이 정상적으로 돌아가는지 확인하기 위한 출력문
    if (root->prio >= new_node->prio) {         // 새로운 노드(연산자)의 우선순위가 root와 같거나 작을 경우
        new_node->left = root;                  // 새로운 노드가 새로운 root로 갱신된다.
        root = new_node;
    }
    else {                                      // 새로운 노드의 우선순위가 root보다 높을 경우
        new_node->left = root->right;           // 새로운 노드의 left를 root->right 로 지정하고
        root->right = new_node;                 // root->right는 새로운 노드로 연결한다
    }
}

void Tree::inorder(Node *p){                    // 트리를 중위 표현식으로 출력하는 함수
    if (p) {                                    // p가 Null이 아닐 때까지
        inorder(p->left);                       // 왼쪽 노드를 먼저 재귀호출한다
        cout << p->data << " ";                 // 왼쪽 노드의 inorder 호출이 끝나면 현재 노드의 데이터를 출력한다.
        inorder(p->right);                      // 이후 오른쪽 노드 재귀호출
    }
}

void Tree::postorder(Node *p){                  // 후위 표현식으로 출력하는 함수
    if (p) {                                    // p가 Null이 아닐 때까지
        postorder(p->left);                     // 왼쪽 노드 먼저 재귀호출
        postorder(p->right);                    // 오른쪽 노드 재귀호출
        cout << p->data << " ";                 // 마지막으로 현재 노드의 데이터 출력
    }
}

void Tree::preorder(Node *p){                   // 전위 표현식으로 출력하는 함수
    if (p) {                                    // p가 Null이 아닐 때까지
        cout << p->data << " ";                 // 현재 노드 먼저 출력
        preorder(p->left);                      // 왼쪽 노드 재귀호출
        preorder(p->right);                     // 오른쪽 노드 재귀호출
    }
}

int Tree::evalTree(Node *p){                    // 입력받은 식을 계산하여 결과값을 출력하는 함수
    int value;                                  // 계산하는 값을 담을 변수
    if (p) {                                    // p가 Null이 아닐 때까지
        if (0 <= p->data - '0' && p->data - '0' < 10) { // 데이터가 피연산자 (0~9인 숫자)임을 검증하는 조건문
            value = p->data - '0';              // 아스키 코드로 저장된 값을 숫자로 바꿔서 value에 저장
        }
        else { // Operator //                   // 데이터가 연산자인 경우
            int left = evalTree(p->left);       // 왼쪽과 오른쪽 자식 노드의 계산 결과를 재귀호출의 받아서 저장
            int right = evalTree(p->right);
            switch(p->data) {                   // 현재 노드에 담긴 연산자를 구분하여 알맞는 연산을 진행
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
        cout << "Empty tree" << endl;           // 트리가 존재하지 않는 경우 에러 출력
    }

    return value;                               // 계산 결과 반환
}

Node * Tree::getroot() {                        // root의 주소값을 반환하는 함수
    return root;
}

void Tree::DrawTree(Node *p, int level) {       // 트리의 구조를 반시계방향으로 90도 눕힌 모양으로 출력하는 함수
    if (p != 0) {                               // p(현재 바라보는 노드)가 Null이 아닐 때까지
        DrawTree (p->right, level + 1);         // level을 높이며 오른쪽 노드를 호출하여 가장 오른쪽 노드부터 윗줄에 출력
        for (int i = 1; i <= level-1; i++) {    // 입력받은 level(depth)만큼 공백을 띄워서 트리의 깊이를 표현
            cout << "    "; 
        }

        cout << p->data;                        // 공백 출력 이후 데이터 출력

        if (p->left != 0 && p->right != 0) {    // 자식 노드의 유무 여부에 따라 가지 출력
            cout << "  <  ";
        }
        else if (p->right != 0) {
            cout << "/";
        }
        else if (p->left != 0) {
            cout << "\\";
        }
        
        cout << endl; 
        DrawTree(p->left, level + 1);           // 왼쪽 자식 노드 출력
    }
}

int main() {
    char expression[50];                        // 사용자의 입력을 저장하는 변수
    cout << "Enter Expression : ";
    cin >> expression;

    Tree tree;
    cout << "Now Expression Get : " << expression << endl; // 입력받은 데이터를 확인하는 출력문
    tree.buildTree(expression);                 // 입력받은 데이터로 트리 생성
    cout << endl;
    
    cout << "  InOrder exp \t: ";               // 중위 표기법으로 수식 출력
    tree.inorder(tree.getroot());
    cout << endl << endl;

    cout << "  PostOrder exp\t: ";              // 후위 표기법으로 수식 출력
    tree.postorder(tree.getroot());         
    cout << endl << endl;

    cout << "  PreOrder exp \t: ";              // 전위 표기법으로 수식 출력
    tree.preorder(tree.getroot());
    cout << endl << endl;

    cout << "  Evaluation : " << tree.evalTree(tree.getroot()) << endl << endl; // 계산한 결과 출력
    
    cout << "  Tree Structure" << endl << endl; // 트리의 구조를 반시계방향으로 90도 눕혀서 출력
    tree.DrawTree(tree.getroot(), 1);
    cout << endl;

    return 0;
}
