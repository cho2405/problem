/*
 * Filename: /Users/cho/work/problem/baekjoon/1152.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Tuesday, March 20th 2018, 9:49:53 am
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    int cnt = 0;

    string str;

    getline(cin, str);
    if((int)str.length() == 1) {
        cout << "0" << endl;
        exit(0);
    }

    for (int i = 0; i < (int)str.length(); i++){
        if (str.at(i) == ' ' && i != 0 && i != (int)str.length()-1)
                cnt++;
             
    }   
        
    cout << cnt+1 << endl;
    return 0;
}