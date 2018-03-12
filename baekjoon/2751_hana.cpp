#include <iostream>

int a=0;
int *arr;

void swap(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void heapify(int last) {
    int left; 
    int right; 
    int min;
    int cur = 1;
    while(1) {
        left = (cur * 2);
        right = (cur * 2) + 1; 
        min = cur; 
        if (left > last && right >last)
            return;
        if (arr[left] < arr[min]) { 
            min = left; 
        } 
        if (right <= last && arr[right] < arr[min]) { 
            min = right; 
        } 
        if (min != cur) { 
            swap(&arr[cur], &arr[min]); 
            cur = min; 
        } 
        else { 
            return; 
        } 
    }
}

void push(int input, int last) {
    arr[last] = input;
    int cur = last;
    while (cur != 1) {
        int parent = (cur)/2;

        if (arr[parent] <= arr[cur])
            break;
        else {
            swap(&arr[parent], &arr[cur]);
            cur = parent;
        } 
    }
}

int pop(int last) {
    int root = arr[1];

    arr[1] = arr[last];
    heapify(last-1);    

    return root;
}

int main() {
    int a;
    scanf("%d", &a);
    arr = new int[a+1];
    for (int i=1; i<=a; i++) {
        int x;
        scanf("%d", &x);
        push(x, i); 
    }   

    for (int i=0; i<a; i++) {
        printf("%d\n", pop(a-i));
    }   
    return 0;
}
