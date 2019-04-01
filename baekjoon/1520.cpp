/*
 * Filename: /Users/cho/work/problem/baekjoon/1520.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Tuesday, April 10th 2018, 8:33:25 am
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>
using namespace std;

#define MAX 500
int N, M;

int arr[MAX][MAX];
int cache[MAX][MAX];
//down, up, right,left
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int hana(int x, int y){
    if (x == 0 && y == 0) return cache[0][0] = 1;
    if (cache[x][y] > -1) return cache[x][y];
    int ret = 0;
    for (int i = 0; i < 4; i++){
        int nextX = x + dir[i][0];
        int nextY = y + dir[i][1];
        if (nextX < 0 || nextY < 0 || nextX > N -1 || nextY > M-1) continue;

        if (arr[x][y] < arr[nextX][nextY]) {
            ret += hana(nextX, nextY);
        }
    }
    return cache[x][y] = ret;
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
            cache[i][j] = -1;
        }
    }
    printf("%d\n", hana(N-1, M-1));                                                             

    return 0;
}