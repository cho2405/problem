#include <iostream>
#include <queue>
#include <string.h>
#include <limits.h>
using namespace std;
#define MAX 20001
int N, M;
int S, D;
vector<pair<int, int> > adj[MAX];

bool state[MAX];
int dist[MAX];
priority_queue<pair<int, int >, vector<pair<int, int> >, greater<pair<int, int > > > pq;
void dij() {

    dist[S] = 0;
    pq.push(pair<int, int>(0, S));
    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        int curIdx = cur.second;
       
        pq.pop();
        for (unsigned int i = 0; i < adj[curIdx].size(); i++) {
            int nextIdx = adj[curIdx][i].first;
            int weight = adj[curIdx][i].second;
            if (curIdx != nextIdx && !state[nextIdx] && dist[nextIdx] > dist[curIdx] + weight) {
                dist[nextIdx] = dist[curIdx] + weight;
                pq.push(pair<int, int>(dist[nextIdx], nextIdx));
            }
        }      
        state[curIdx] = true;
    }
}


int main() {
    cin >> N;
    cin >> M;

    cin >> S;
    for (int i= 1; i <= N; i++){
        dist[i] = INT_MAX;
        state[i] = false;
    }
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        pair<int, int> e = make_pair(b, c);
        adj[a].push_back(e);
    }
    dij();
    for ( int i = 1; i <= N; i++){
        if (dist[i] == INT_MAX) 
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }   
    return 0;
}
