/*
 * Filename: /Users/cho/work/problem/baekjoon/2504_re.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Friday, March 16th 2018, 8:52:43 am
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>
#include <stack>


using namespace std;

char arr[30];
stack<char> stack1;
int so(int, int);

int jung(int f, int l) {
    int first = f +1;
    int ncnt = f +1;
    int nl; 
    char nc; 
    stack<char> tmp;

    if( f == l -1)
        return 3;

    while (ncnt < l) {
      tmp.push(arr[ncnt]);

      while (tmp.size() != 0) {
        nc = arr[ncnt++];
        
        if (nc == ')' && tmp.top() == '(') {
            tmp.pop();
            nl = ncnt -1;
            int tempfirst =first;
            first = nl+1;
            return so(tempfirst, nl) * 3;
        } 
        else if (nc == ']' && tmp.top() == '[') {
            tmp.pop();
            nl = ncnt -1;
            int tempfirst =first;
            first = nl+1;
            return jung(first, nl) * 3;
        } else {
            tmp.push(nc);
        }
      }
    }

    return -1; 
}
int so(int f, int l) {
    int first = f +1;
    int ncnt = f +1;
    int nl; 
    char nc; 
    stack<char> tmp;

    if( f == l -1)
        return 2;

    while (ncnt < l) {
      tmp.push(arr[ncnt]);

      while (tmp.size() != 0) {
        nc = arr[ncnt++];
        
        if (nc == ')' && tmp.top() == '(') {
            tmp.pop();
            nl = ncnt -1;
            int tempfirst =first;
            first = nl+1;
            return so(tempfirst, nl) * 2;
        } 
        else if (nc == ']' && tmp.top() == '[') {
            tmp.pop();
            nl = ncnt -1;
            int tempfirst =first;
            first = nl+1;
            return jung(first, nl) * 2;
        } else {
            tmp.push(nc);
        }

    }
}
    return -1;
}
int main() {
    scanf("%s", arr);

    int cnt = 0;
    int first = 0, last = 0;
    int ret = 0;
    while (arr[cnt] != '\0') {
        char c = arr[cnt++];

        stack1.push(c);

        while (stack1.size() != 0) {
            c = arr[cnt];
            char top = stack1.top();

            if (c == ')' && top == '(') {
                stack1.pop();
                last = cnt++;
                int tempfirst = first;
                first = last + 1;
                so(first, last);
            } else if (c == ']' && top == '[') {
                stack1.pop();
                last = cnt++;
                int tempfirst = first;
                first = last + 1;
                jung(first, last);
            } else {
                stack1.push(c);

            }

        }

    }
    cout << ret << endl;
    return 0;
}
