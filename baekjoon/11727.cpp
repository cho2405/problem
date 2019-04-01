/*
 * Filename: /Users/cho/work/problem/baekjoon/11727.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Friday, March 30th 2018, 10:38:00 am
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>

using namespace std;
#define MAX 1001

int cache[MAX];

int hana(int n) {
    if (n == 1) return 1;
    if (n == 2) return 3;
    if (cache[n]) return cache[n];
    
    return cache[n] = (hana(n-1) + 2* hana(n-2)) % 10007;
}

int main() {
    int a;
    fill_n(cache, MAX, 0); 
    cin >> a;
    cout << hana(a) % 10007 << endl;
    return 0;    
}