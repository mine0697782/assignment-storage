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

void insert_maxheap(element item, int *n){  // 
    int i;
    if (HEAP_FULL(*n)) {
        cout << "Heap is full..." << endl;
        return;
    }
    i = ++(*n);
    while((i!=1) && (item.key > heap[i/2].key)) {
        heap[i] = heap[i/2];
        i = i/2;
    }
    heap[i] = item;
}

element delete_maxheap(int *n){
    int parent, child;
    element item, temp;

    item = heap[1];
    temp = heap[(*n)--];
    parent = 1;
    child = 2;

    while (child <= *n){
        if ((child < *n) && (heap[child].key < heap[child+1].key)) {
            child++;
        }
        if (temp.key >= heap[child].key) {
            break;
        }
        heap[parent] = heap[child];
        parent = child;
        child = child*2;
    }
    heap[parent] = temp;
    return item;
}

void display(){
    if (HEAP_EMPTY(n)){
        cout << "Heap is Empty" << endl;
    }
    else {
        for (int i=1; i<=n; i++){
            cout << heap[i].key << " ";
        }
        cout << endl;
    }
}

int level(){
    int num = 0;
    int count = 0;
    int i = 1;

    while(1){
        if (n >= i){
            count++;
        }
        else break;

        i = i * 2;
    }
    cout << "level : " << count << endl;
    return count;
}

main(){
    char input[20];
    element e;
    
    cout << "Menu (insert, delete, print, empty, full, level)" << endl;
    while(1){
        cin >> input;

        if (strcmp(input,"insert") == 0) {
            cin >> e.key;
            insert_maxheap(e, &n);
        }
        else if (strcmp(input,"delete") == 0) {
            delete_maxheap(&n);
        }
        else if (strcmp(input,"print") == 0) {
            
            for (int i=1; i<=n; i++){
                cout << heap[i].key << " ";
            }
            
            //display();
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


















































