/*
 * Filename: /Users/cho/work/problem/baekjoon/2133.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Monday, April 9th 2018, 1:01:02 pm
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>

using namespace std;
#define MAX 31
int N;
int cache[MAX] = {0,};

int hana(int n) {
    if (n % 2 == 1) return 0;
        
    if (n == 0) return 1; 
    if (n == 2) return 3;

    if (cache[n] > 0) return cache[n];
    int sum = hana(n-2) * 3;
    
    for (int i = 2; i <= n/2; i++) {
        int idx = n - (2*i);
        int temp = hana(idx);
        sum += temp *2;
    }
    return cache[n] = sum;
}
int main() {
    cin >> N;
    cout << hana(N) << endl;
    return 0;
}