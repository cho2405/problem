/*
 * Filename: /Users/cho/work/problem/baekjoon/9095.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Friday, March 30th 2018, 10:44:09 am
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>

using namespace std;
#define MAX 11

int cache[MAX];
int hana(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;
    if (cache[n]) return cache[n];
    return cache[n] = hana(n-1) + hana(n-2) + hana(n-3);
}

int main() {
    int a; 
    cin >> a;
    fill_n(cache, MAX, 0);
    int b;
    for(int i = 0; i < a; i ++) {
        cin >> b;
        cout << hana(b) << endl;
    }
    return 0;
}