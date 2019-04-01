/*
 * Filename: /Users/cho/work/problem/baekjoon/10844.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Monday, April 16th 2018, 9:12:45 pm
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 101

int N;
int cache[MAX][10];
int hana(int n, int num) {
    if (num == -1 || num == 10) return 0;
    if (n == 1) {
        if (num == 0) return 0;
        return 1;
    }
    if (n == 2) {
        if (num == 0 || num == 9 || num == 1) {
            return 1;
        }
        return 2;
    }
    if (cache[n][num] != -1) return cache[n][num];
    
    return cache[n][num] = (hana(n-1, num-1) + hana(n-1, num+1)) % 1000000000;
}


int main() {
    cin >> N;
    for (int i = 0; i <= N; i++) {
        memset(cache[i], -1, sizeof(int) * (10));
    }
    int sum = 0;
    for (int i = 0; i <= 9; i++) {
        sum = (sum + hana(N, i)) % 1000000000;
    }
    cout << sum % 1000000000 << endl;
    return 0;
}
