/*
 * Filename: /Users/cho/work/problem/baekjoon/11053
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Monday, April 2nd 2018, 6:22:13 pm
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
int cache[MAX] = {0, };
//가장긴 감소 수열도 fn은 n번째 숫자를 포함한 가장 긴 길이 라고 가정
int a;
void hana() {
    cache[0] = 0;
    for (int i = 1; i <= a; i++ ) {
        int maxValue = 1;
        for (int j = i-1; j > 0; j++ ) {
            if (arr[j] < arr[i]) {
                maxValue = max(maxValue,  cache[j] + 1);
            }
        }
        cache[i] = maxValue;
    }
}
int main() {
    cin >> a;
    int ele;

    arr.push_back(0);
    for (int i = 0; i < a; i++ ) {
        cin >> ele;
        arr.push_back(ele);
    }
    hana();

    for (int i = 1; i <= a; i++ ) {
        cout << cache[i]  << " " ;
    }
    cout << endl;
    return 0;
}