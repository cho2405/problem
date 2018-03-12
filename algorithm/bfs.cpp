/*
 * Filename: /Users/cho/work/problem/algorithm/bfs.cpp
 * Path: /Users/cho/work/problem/algorithm
 * Created Date: Friday, March 9th 2018, 11:03:46 am
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>

using namespace std;

int n;

int rear, front;

int map[30][30];
int queue[30], visit[30];

void BFS (int v) {
    int i;

    visit[v] = 1;
    queue[rear++] = v;

    while (front < rear) {
        v = queue[front++];
        for (int i = 0; i <n; i++) {
            if (map[v][i] == 1 && !visit[i]) {
                visit[i] = 1;
                queue[rear++] = i;
            }
        }
    }

}
int main () {
    int start;
    int v1, v2;

    cin >> n >> start;
    BFS(start);
    return 0;
}