/*
 * Filename: /Users/cho/work/problem/baekjoon/1916.cpp
 * Path: /Users/cho/work/problem/baekjoon
 * Created Date: Wednesday, March 21st 2018, 9:45:00 am
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>
#include <queue>
#include <string.h>
#include <utility>
#include <limits.h>

using namespace std;
#define MIN_VAL(x, y) (((x) < (y)) ? (x) : (y))
#define MAX 1001
int N, M;
int S, D;
int path[MAX][MAX] = {};

enum {WHITE, GRAY, BLACK};
int state[MAX];

int dist[MAX];

priority_queue<pair<int, int >, vector<pair<int, int> >, greater<pair<int, int > > > pq;

void dij() {

    dist[S] = 0;
    pq.push(pair<int, int>(0, S));

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        int curIdx = cur.second;
        if (curIdx == D)
            break;
        pq.pop();
        for (int i = 1; i <= N; i++) {
            if (path[curIdx][i] != -1 && curIdx != i && dist[i] > dist[curIdx] + path[curIdx][i] ) {
                dist[i] = dist[curIdx] + path[curIdx][i];
                pq.push(pair<int, int>(dist[i], i));
            }
        }
    }
}

int main() {
    cin >> N;
    cin >> M;

    for (int i= 1; i <= N; i++){
        dist[i] = INT_MAX;
        state[i] = 0;
    }
    for (int i = 1; i <= N; i++) {
        memset(path[i], -1, sizeof(int) * (N+1));
    }
    
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(path[a][b] == -1 || path[a][b] > c) {
            path[a][b] = c;
        }
    }
    cin >> S;
    cin >> D;

    dij();
    cout << dist[D] << endl;
    return 0;
}
