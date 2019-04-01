/*
 * Filename: /Users/cho/work/problem/baekjoon/11722.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Wednesday, April 4th 2018, 1:59:32 pm
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 1001

vector<int> arr;
int N;
int cache[MAX] = {0, };

int hana(int n) {
    if (n == 1) return cache[1] = 1;

    int value = 1;
    for (int i = 1; i < n; i++) {
        if (arr[n-i] > arr[n]) {
            int h1 = cache[n-i] ? cache[n-i] : hana(n-i);
            value = max(h1 + 1, value);
        }
    }
    return cache[n] = value;
}
int main() {
    cin >> N;    
    
    int input;
    arr.push_back(0);
    for (int i = 0; i < N; i ++){
       cin >> input;
       arr.push_back(input); 
    }
    hana(N);
    int maxValue = -1;
    for (int i = 1; i <= N; i++){
        maxValue = max(maxValue, cache[i]);
    }
    cout << maxValue << endl;
    
    return 0;
}