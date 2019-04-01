/*
 * Filename: /Users/cho/work/problem/baekjoon/6591.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Tuesday, March 20th 2018, 11:06:01 am
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>


using namespace std;

int func(int n, int r) {
   if( n == r || r == 0)
       return 1;

    return func(n-1, r) + func(n-1, r-1);

}

int main() {
    int a = -1, b = -1; 


    while(a != 0 || b != 0) {
        cin >> a;
        cin >> b;

        cout << func(a, b) << endl;
    }   
    return 0;
}