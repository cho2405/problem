/*
 * Filename: /Users/cho/work/problem/baekjoon/2178_bfs.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Friday, March 9th 2018, 11:24:44 am
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define SIZE 100

int** map;
int a, b;
int rear = -1, front = -1;
struct node {
    int x;
    int y;
};
queue<node> q;

int visit[SIZE][SIZE];
node togo[4] = {{-1, 0},{1, 0},{0, -1},{0, 1}};
void BFS(node n) {
    q.push(n);
    visit[n.x][n.y] = 1;

    while (!q.empty()) {
        node f = q.front();
        q.pop();

        if (f.x == a-1 && f.y == b-1) 
            break; 
        for (int i = 0; i < 4; i++) {
            int next_x = f.x + togo[i].x;
            int next_y = f.y + togo[i].y;

            if (next_x < 0 || next_y < 0 || next_x > a-1 || next_y > b-1)
                continue;
            if (map[next_x][next_y] == 1 && !visit[next_x][next_y]) {
                visit[next_x][next_y] = visit[f.x][f.y] + 1;
                q.push({next_x, next_y});
            }
        }
    }
}
int main() {
    cin >> a;
    cin >> b;
    map = new int*[a];

    for(int i = 0; i < a; i++) {
        map[i] = new int[b];
        for(int j = 0; j < b; j++) 
            scanf("%1d", &map[i][j]);
    }

    BFS({0, 0});
    cout << visit[a-1][b-1] << endl;
    return 0;
}
