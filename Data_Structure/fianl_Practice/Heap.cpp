#include<iostream>
#include<fstream>
#include<string.h>

#define MAX_ELEMENTS 8 // 최대크기 + 1
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)

using namespace std;

typedef struct {
    int key;
} element;

//element heap[MAX_ELEMENTS];
int heap[MAX_ELEMENTS];
int n = 0;

void insert_heap(int item, int *n, int mode){
    int i;
    if (HEAP_FULL(*n)) {
        cout << "Heap is full..." << endl;
        exit(1);
    }
    i = ++(*n);
    if (mode == 1){ // MaxHeap
        while((i!=1) && (item > heap[i/2])){
            heap[i] = heap[i/2];
            i = i/2;
        }
        heap[i] = item;
    }
    else {          // MinHeap
        while((i!=1) && (item < heap[i/2])){
            heap[i] = heap[i/2];
            i = i/2;
        }
        heap[i] = item;
    }
}

int /*element*/ delete_heap(int *n, int mode){
    int parent, child;
    //element item, temp;
    int item, temp;

    item = heap[1];
    temp = heap[(*n)--];
    parent = 1;
    child = 2;
    if (mode == 1){ // MaxHeap
        while(child <= *n) {
            if ((child < *n) && (heap[child] < heap[child+1])){
                child++;
            }
            if (temp >= heap[child]) break;
            heap[parent] = heap[child];
            parent = child;
            child = child*2;
        }
    }
    else {          // MinHeap
        while(child <= *n) {
            if ((child < *n) && (heap[child] > heap[child+1])){
                child++;
            }
            if (temp <= heap[child]) break;
            heap[parent] = heap[child];
            parent = child;
            child = child*2;
        }
    }
    heap[parent] = temp;
    return item;
}

void print_heap(int *n){
    cout << "Heap : ";
    for (int i = 1; i <= *n; i++){
        cout << heap[i]/*.key*/ << " ";
    }
    cout << endl << endl;
}

int print_level(int *n){
    int i, num, level;
    i = 1;
    level = 0;
    num = 0;
    while(1){
        if (*n > num){
            level++;
        }
        else {
            cout << level << endl;
            return level;
        }
        num += i;
        i *= 2;
    }
}

main(){
    //ifstream in;
    //in.open("Heap_input.txt");
    //element item;
    int item, mode;
    char input[20];
    
    cout << "Emter mode(1.MaxHeap, 2.MinHeap) : ";
    cin >> mode;

    insert_heap(9, &n, mode);
    insert_heap(2, &n, mode);
    insert_heap(5, &n, mode);
    insert_heap(3, &n, mode);
    insert_heap(8, &n, mode);
    insert_heap(1, &n, mode);
    insert_heap(7, &n, mode);

    cout << "Enter (insert, delete, print, full, empty, level)" << endl;
    while(1){
        cin >> input;
        if (strcmp(input, "insert") == 0){
            cin >> item;//.key;
            insert_heap(item, &n, mode);
        }
        else if (strcmp(input, "delete") == 0){
            delete_heap(&n, mode);
        }
        else if (strcmp(input, "print") == 0){
            print_heap(&n);
        }
        else if (strcmp(input, "full") == 0){
            if (HEAP_FULL(n)) cout << "Heap is Full" << endl;
            else cout << "Heap is NOT Full" << endl;
        }
        else if (strcmp(input, "empty") == 0){
            if (HEAP_EMPTY(n)) cout << "Heap is Empty" << endl;
            else cout << "Heap is NOT Empty" << endl;
        }
        else if (strcmp(input, "level") == 0){
            print_level(&n);
        }
        else {
            cout << "Bad command" << endl;
        }
    }
    return 0;
}
