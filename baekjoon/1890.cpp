/*
 * Filename: /Users/cho/work/problem/baekjoon/1890.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Tuesday, April 10th 2018, 8:34:28 am
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>

using namespace std;

#define MAX 100
int N;
int arr[MAX][MAX];
long long cache[MAX][MAX];
                                                                                    
long long hana(int x, int y) {
    long long ret = 0;
    if (x == 0 && y == 0) return cache[0][0] = 1;
    if (cache[x][y] > -1) return cache[x][y];

    for (int i = 1; i <= x; i++) {
        if (arr[x-i][y] == i) {
            ret += hana(x-i, y); 
        } 
    }
    for (int i = 1; i <= y; i++) {
        if (arr[x][y-i] == i) {
            ret += hana(x, y-i); 
        } 
    }

    return cache[x][y] = ret;
}
int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            cache[i][j] = -1;
        }
    }
    cout << hana(N-1, N-1) << endl;
    return 0;
}
