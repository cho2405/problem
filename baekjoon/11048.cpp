/*
 * Filename: /Users/cho/work/problem/baekjoon/11048.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Thursday, April 5th 2018, 9:58:49 am
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 1001
int map[MAX][MAX];
int cache[MAX][MAX];
int visit[MAX][MAX];

struct Node {
    int x;
    int y;
};
queue<Node> q;
Node go[3] = {{1, 0}, {0, 1}, {1, 1}};
int N, M;

int bfs(int x, int y) {
    q.push(Node({x, y}));
    cache[x][y] = map[x][y];
    visit[x][y] = 1;
    while(!q.empty()) {
        Node n1 = q.front(); q.pop();
        visit[n1.x][n1.y] = 1;
        
        for (int i = 0; i < 3; i++ ) {
            int nextX = n1.x + go[i].x;
            int nextY = n1.y + go[i].y;

            if ( (i == 0 && nextX <= N) || (i == 1 && nextY <= M) || (i == 2 && nextX <= N && nextY <= M) ) {
                if (!visit[nextX][nextY]) {
                  cache[nextX][nextY] =
                      max(cache[nextX][nextY],
                          cache[n1.x][n1.y] + map[nextX][nextY]);
                  q.push(Node({nextX, nextY}));
                }
            }
        }
    }
    return cache[N][M];
}

int main() {
    scanf("%d %d", &N, &M);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &map[i][j]);
            cache[i][j] = 0;
            visit[i][j] = 0;
        }
    }

    cout  << bfs(1, 1) << endl;
    
    return 0;
}  