/*
 * Filename: /Users/cho/work/problem/baekjoon/1935.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Monday, March 26th 2018, 10:19:51 am
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>
#include <stack>

using namespace std;

char arr[100];

stack<double> cal;
double nums[26];
bool checked[26] = {false, };

int N;

int main() {
    cin >> N;
    scanf("%s", arr);
       
    int cnt = 0, idx = 0, chIdx;
    char ch; 
    while ((ch = arr[idx++]) != '\0') {
        chIdx = ch - 'A';
        if (cnt < N && ch >= 'A' && ch <= 'Z' && !checked[chIdx]) {
            cin >> nums[chIdx];
            checked[chIdx] = true;
            cnt++;
        }   
    }   

    for (int i = 0; i < idx-1; i++) {
        char cur = arr[i];
        if (cur >= 'A' && cur <= 'Z') {
            cal.push(nums[cur - 'A']);
            continue;
        }

        double b = cal.top(); cal.pop();
        double a = cal.top(); cal.pop();

        if ( cur == '+' ) cal.push((double)a + b);
        else if (cur == '-') cal.push((double)a - b);
        else if (cur == '*') cal.push((double)a * b);
        else if (cur == '/') cal.push((double)a / b);
    }  
    printf("%.2f\n", cal.top());

    return 0;
}
