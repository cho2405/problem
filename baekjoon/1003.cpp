/*
 * Filename: /Users/cho/work/problem/baekjoon/1003.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Friday, March 30th 2018, 10:55:45 am
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>

#define MAX 41
struct Pair {
    int c0 = 0;
    int c1 = 0;
};

Pair cache[MAX];
Pair fibonacci(int n) {
    if (n == 0) {
        return Pair({1, 0});
    } 
    if (n == 1) {
        return Pair({0, 1});
    } 
    if (cache[n].c0) return cache[n];
    Pair n1 = fibonacci(n-1);
    Pair n2 = fibonacci(n-2);
    return cache[n] = Pair({n1.c0 + n2.c0, n1.c1 + n2.c1});
    
}
int main() {
    int a;
    scanf("%d", &a);
    int b;
    for(int i = 0; i < a; i ++){
        scanf("%d", &b);
        Pair c = fibonacci(b);
        printf("%d %d\n", c.c0, c.c1);
    }
    return 0;
}