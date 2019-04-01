/*
 * Filename: /Users/cho/work/problem/baekjoon/11055.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Wednesday, April 4th 2018, 4:43:00 pm
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 1001
int N;
vector<int> arr;
int cache[MAX] = {0, };

void hana() {
    cache[1] = arr[1];

    for (int i = 1; i <= N; i++) {
        int value = 0;
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) {
                value = max(value, cache[j] + arr[i]);
            }    
        }
        cache[i] = value ? value : arr[i]; 
    }
}
int main() {
    cin >> N;
    int input;    
    arr.push_back(0);
    for (int i = 0; i < N; i++) {
        cin >> input;
        arr.push_back(input);
    }
    hana();
    int maxValue = -1;
    for (int i = 1; i <= N; i++) {
        maxValue = max(maxValue, cache[i]);
    }
    cout << maxValue << endl;
    return 0;
}