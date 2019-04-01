/*
 * Filename: /Users/cho/work/problem/baekjoon/11726.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Thursday, March 29th 2018, 8:05:02 pm
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 1001
int cache[MAX];
int foo(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (cache[n]>0) return cache[n];

    return cache[n] = (foo(n-1) + foo(n-2))%10007;
}

int main() {
    int a;
    cin >> a;
    memset(&cache, 0, sizeof(int));
    cout << foo(a)%10007 << endl;

}