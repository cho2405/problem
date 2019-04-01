/*
 * Filename: /Users/cho/work/problem/baekjoon/1727.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Thursday, April 26th 2018, 1:20:23 pm
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>                                                                 
#include <vector>
#include <climits>
#include <stdlib.h>
#include <algorithm>

using namespace std;
int N, M;
vector<int> boys;
vector<int> girls;


int main() {
    cin >> N >> M;
    int n, m;
    for (int i = 0; i < N; i++){
        cin >> n;
        boys.push_back(n);
    }   
    for (int i = 0; i < M; i++) {
        cin >> m;
        girls.push_back(m);
    }   

    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    vector<int> bigVector;
    vector<int> smallVector;
        
    if (N <= M) {
        bigVector = girls;
        smallVector = boys;
    } else {
        smallVector = girls;
        bigVector = boys;
    }   
    unsigned int sSize = smallVector.size();
    unsigned int bSize = bigVector.size();
    int minIdx = 0;
    int ret = 0;
    for (unsigned int i = 0; i < sSize; i++) {
        int tmp = smallVector[i];
        int minValue = INT_MAX;

        for (unsigned int j = minIdx; j <= bSize - (sSize- i); j++) {
            if (minValue > abs(bigVector[j]-tmp)) {
                minValue = abs(bigVector[j] - tmp);
                minIdx = j;
            }   
        }   
        ret += minValue;
    }   
    cout << ret << endl;
    return 0;
}          