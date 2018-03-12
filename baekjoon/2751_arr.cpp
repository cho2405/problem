/*
 * Filename: /Users/cho/work/problem/baekjoon/2751_arr.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Monday, March 12th 2018, 9:46:50 am
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <cstdio>
#include <vector>
using namespace std;
int *arr;
void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y= tmp;
}

void insert(int key, int last) {
    arr[last] = key;
    int cur = last;
    while (cur != 1) {
        int parent = cur/2;

        if (arr[parent] <= arr[cur])
            break;
        else {
            swap(&arr[parent], &arr[cur]);
            cur = parent;
        } 
    }   
}

int heapify(int last) {
    int i = 1;
    int ret = arr[i];
    arr[i] = arr[last];

    while (1) {
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left > last && right > last) {
            break;
        }   

        else if (right > last) {
            if (arr[i] < arr[left]) 
                break;
            swap(&arr[i], &arr[left]);
            i = left;
        }   

        else {
            if (arr[left] < arr[right]) {
                if (arr[i] < arr[left]) 
                    break;
                swap(&arr[i], &arr[left]);
                i = left;
            }   

            else {
                if (arr[i] < arr[right]) 
                    break;
                swap(&arr[i], &arr[right]);
                i = right;
            }   
        }   
    }   

    return ret;
}


int main() {
    int n;
    scanf("%d", &n);
    arr = new int[n+1];
    for (int i=1; i<=n; i++) {
        int x;
        scanf("%d", &x);
        insert(x, i); 
    }   

    for (int i=0; i<n; i++) {
        printf("%d\n", heapify(n-i));
    }   

    return 0;
}