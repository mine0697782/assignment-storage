#include<iostream>
using namespace std;

int iterative(int *list, int num){
    int length = sizeof(list);
    int start = 0, end = length;
    int i;

    while(1){
        i = (start + end)/2;
        if (end-start == 1)
            return -1;

        if (list[i] == num)
            return i;
        else if (list[i] > num)
            end = i;
        else if (list[i] < num)
            start = i;
    }

}

int recursive(int *list, int num, int start = -1, int end = -1){
    int length = sizeof(list);
    int i;

    if (start == -1) 
        start = 0;
    if (end == -1)
        end = length;

    while(1){
        i = (start + end)/2;
        if (end-start == 1)
            return -1;
        if (list[i] == num)
            return i;
        else if (list[i] > num)
            return recursive(list, num, start, i);
        else if (list[i] < num)
            return recursive(list, num, i, end);
    }
}

main(){
    int list[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int num, command, result;
    while(1){
        cout << "Enter an integer to search : ";
        cin >> num;
        cout << "Enter method of search(1.Binary Search / 2.Recursive Binary Search : ";
        cin >> command;
        
        if (command == 1)
            result = iterative(list, num);
        else if (command == 2)
            result = recursive(list, num);
        else {
            cout << "Bad command" << endl;
            continue;
        }

        if (result != -1)
            cout << num << " is at position " << result << endl;
        else
            cout << num << " is NOT FOUND" << endl;
    }
}
