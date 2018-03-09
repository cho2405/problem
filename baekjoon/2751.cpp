/*
 * Filename: /Users/cho/GoogleDrive/02_Develop/codepro/2751.cpp
 * Path: /Users/cho/GoogleDrive/02_Develop/codepro
 * Created Date: Thursday, March 8th 2018, 2:53:54 pm
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++){
        cout << *iter << endl;
    }    
    return 0;
}