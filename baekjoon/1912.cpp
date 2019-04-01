/*
 * Filename: /Users/cho/work/problem/baekjoon/1912.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Friday, March 30th 2018, 2:23:41 pm
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>
#include <vector>
#include <queue>

#define MAX 100001

using namespace std;

vector<int> arr;
int cache[MAX];

int a;
void hana() {
    cache[0] = 0;
    for (int i = 1; i <= a; i++) {
        cout << "Arr i : " << arr[i] << endl;
        if(arr[i] < cache[i-1] + arr[i]) {
            cache[i] = cache[i-1] + arr[i];
        } else { 
            cache[i] = arr[i];
        }
    }
}
int main() {
    cin >> a;
    int ele;

    arr.push_back(0); 
    for (int i = 0; i < a; i++) {
        cin >> ele;
        arr.push_back(ele);
    } 
    hana();
    int maxValue = -1001;
    for (int i = 1; i <=a; i++ ) {
        cout << cache[i] << endl;
        if(cache[i] > maxValue)
            maxValue = cache[i];
    } 
    cout << maxValue << endl;
}