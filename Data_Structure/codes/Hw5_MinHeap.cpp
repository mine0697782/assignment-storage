#include<iostream>
#include<stdlib.h>
#include<string.h>

#define MAX_ELEMENTS 7+1                            // Heap의 원소의 최대 갯수 지정
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)          // Heap이 가득 찼으면 True 반환
#define HEAP_EMPTY(n) (!n)                          // Heap의 원소가 없으면 True 반환

using namespace std;

typedef struct {    // Heap의 원소로 사용될 구조체 선언
    int key;        // 데이터를 저장하는 변수
} element;      

element heap[MAX_ELEMENTS]; // 전역변수로 element형 배열 heap선언
int n = 0;                  // 현재 heap의 크기(마지막 원소의 위치)를 저장하는 전역변수

void insert_minheap(element item, int *n){  // element형 item을 heap에 삽입하는 함수
    int i;                                  // 크기순으로 삽입하므로 비교대상을 가리킬 인덱스변수
    if (HEAP_FULL(*n)) {                    
        cout << "Heap is full..." << endl;  // heap이 가득 찼으면 에러 출력
        return;
    }
    i = ++(*n);                                     // 현재 마지막 노드의 위치를 저장
    while ((i!=1) && (item.key < heap[i/2].key)) {  // 원소의 갯수가 0이 아닐 경우
        heap[i] = heap[i/2];                        // && 부모 노드보다 값이 작을 경우
        i = i/2;                                    // 부모 노드와 현재(마지막) 값을 서로 변환
    }
    heap[i] = item;                                 // 최종적으로 자리잡은 위치에 값 삽입
}

element delete_minheap(int *n){ // heap의 맨 위 데이터를 꺼내는(pop) 함수
    int parent, child;          // 각각 부모와 자식 노드를 가리키는 인덱스 변수
    element item, temp;         // item : 최상위 노드를 반환하기 위한 변수
                                // temp : 마지막 노드를 임시로 저장하는 변수
    item = heap[1];              
    temp = heap[(*n)--];        
    parent = 1;                 // 최상위 노드는 1번부터 시작한다
    child = 2;                  // parent 바로 다음 노드부터 시작한다

    while (child <= *n){        // 맨 마지막 노드에 다다를 때까지 비교하며 swap해주는 반복문
        if ((child < *n) && (heap[child].key > heap[child+1].key)) { 
            child++;            // 현재 가리키는 노드가 다음 노드보다 값이 크면 다음으로 이동
        }
        if (temp.key <= heap[child].key) {
            break;              // 현재 가리키는 값이 마지막 값보다 크면 중지
        }
        heap[parent] = heap[child]; //
        parent = child;             // 부모 노드에 자식 노드를 넣고 
        child = child*2;            // 자식 노드는 다시 한 번  자식 노드로 이동한다
    }
    heap[parent] = temp;            // 마지막 노드와 그 상위 노드가 swap된다.
    return item;                    // 가장 위에 있는 min값이 반환
}

void display() {        // heap이 배치된 순서대로 나열해서 보여주는 함수
    if (HEAP_EMPTY(n)){ // heap에 원소가 없는 경우 에러문 출력
        cout << "Heap is Empty" << endl;
    }
    else {              // 원소가 있는 경우
        for (int i=1; i<=n; i++){       // heap의 인덱스는 1부터 시작
            cout << heap[i].key << " "; // heap의 각 값들을 한 칸 공백을 두고 출력
        }
        cout << endl;
    }
}

int level(){            // 현재 heap의 레벨(깊이)가 몇인지 출력하는 함수
    int count = 0;      // 한 층씩 깊이를 측정할 때마다 횟수를 저장하는 변수
    int i = 1;          // 각 층마다 원소가 몇 개 이상이여야 하는지를 담는 변수

    while(1){   
        if (n >= i){    // 그 층의 최소갯수를 만족하면
            count++;    // 갯수 변수를 증가시킨다
        }
        else break;     

        i = i * 2;      // 한 층의 갯수를 만족하면 비교대상을 다음 층의 최소갯수로 증가시킨다.
    }
    cout << "level : " << count << endl;    // 출력문
    return count;       // 다른 이용 가능성을 위해 반환
}

main(){
    char input[20];     // command를 입력받는 변수
    element e;          // 유저의 입력을 heap의 원소로 전달하기 위한 구조체 변수
    
    cout << "Menu (insert, delete, print, empty, full, level)" << endl;
    while(1){
        cin >> input;

        if (strcmp(input,"insert") == 0) {
            cin >> e.key;
            insert_minheap(e, &n);
        }
        else if (strcmp(input,"delete") == 0) {
            delete_minheap(&n);
        }
        else if (strcmp(input,"print") == 0) {
            display();
            cout << endl;
        }
        else if (strcmp(input,"empty") == 0) {
            if (HEAP_EMPTY(n)){
                cout << "Heap is Empty" << endl;
            }
            else {
                cout << "Heap is Not Empty" << endl;
            }
        }
        else if (strcmp(input,"full") == 0) {
            if (HEAP_FULL(n)){
                cout << "Heap is Full" << endl;
            }
            else {
                cout << "Heap is Not Full" << endl;
            }
        }
        else if (strcmp(input,"level") == 0) {
            level();
        }
        else {
            cout << "Bad command" << endl;
        }
    }
}

