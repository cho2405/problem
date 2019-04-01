#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>

using namespace std;
#define MAX 501
int N, M;
int S, D;
vector<int> adj[MAX];
vector<int> result;

bool state[MAX];
int dist[MAX];
//int path[MAX][MAX];

vector<int> path[MAX];
void dfs(int v) {
    for (unsigned int i = 0; i < path[v].size(); i++){
            if (adj[path[v][i]][v]) {
                adj[path[v][i]][v] = 0;
                dfs(path[v][i]);
            }
    }   
}

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int shortestDist;
void dij() {

    dist[S] = 0;
    pq.push(pair<int, int>(0, S));
    while (!pq.empty()) {
        pair<int, int> cur = pq.top(); pq.pop();
        int curIdx = cur.second;
        int flag = false;
           
        for (unsigned int i = 0; i < N; i++) {
            int nextIdx = i;
            int weight = adj[curIdx][i];

            if (weight == 0 || curIdx == nextIdx || state[nextIdx]) {
                continue;
            }
            flag = true;
            if (dist[nextIdx] > dist[curIdx] + weight) {
                dist[nextIdx] = dist[curIdx] + weight;
                pq.push(pair<int, int>(dist[nextIdx], nextIdx));
                path[nextIdx].clear();
                path[nextIdx].push_back(curIdx);

            } else if (dist[nextIdx] == dist[curIdx] + weight) {
                path[nextIdx].push_back(curIdx);
            }
        }
        if(!flag) {
            break;
        }
        state[curIdx] = true;
    }
}

int main() {
    while (1) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) {
            for(unsigned int j = 0; j < result.size(); j++) {
                printf("%d\n", result[j]);
            }
            exit(0);
        }
        scanf("%d %d", &S, &D);
        pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
        shortestDist = -1;
        for (int i = 0; i < N; i++) {
            dist[i] = INT_MAX;
            state[i] = false;
            adj[i].clear();
            adj[i].resize(N);
        }   
        for (int i = 0; i < M; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            adj[a][b] = c;
        }   
        dij();
        shortestDist = dist[D];
        dfs(D);
        for (int i = 0; i < N; i++) {
            dist[i] = INT_MAX;
            state[i] = false;
        }
        dij();
        if (dist[D] == INT_MAX) 
            result.push_back(-1);
        else 
            result.push_back(dist[D]);
    }   

    return 0;
}
