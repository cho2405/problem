#include <iostream>
#include <queue>
#include <string>
 
using namespace std;
 
int H;                  // 세로 크기
int W;                  // 가로 크기
string map[502];        // 지도
unsigned int visit[502][502];
unsigned int ans;
 
typedef struct point_ {
    int x, y;
} point;
 
queue<point> searchQ;
 
void inputData(){
    cin >> H >> W;
 
    // cleanup visit map
    for (int i = 0; i < H+2; i++)
        for (int j = 0; j < W+2; j++)
            visit[i][j] = 0xFFFFFFFF;
 
    // Guard
    map[0] = string(W+2, 'X');
    map[H+1] = string(W+2, 'X');
 
    for (int i = 0; i < H; i++) {
        cin >> map[i+1];
        // Guard
        map[i+1] = string("X") + map[i+1] + string("X");
    }
}
 
void BFS() {
    while(searchQ.size()) {
        point p = searchQ.front();
        searchQ.pop();
 
        int move = visit[p.y][p.x] + 1;
        bool chk = false;
 
        if ( map[p.y][p.x-1] == '.' && move < visit[p.y][p.x-1] ) {
            visit[p.y][p.x-1] = move;
            if ( p.x-1 == W && p.y == H ) chk = true;
 
            point newP = {p.x-1, p.y};
            searchQ.push(newP);
        }
 
        if ( map[p.y-1][p.x] == '.' && move < visit[p.y-1][p.x] ) {
            visit[p.y-1][p.x] = move;
            if ( p.x == W && p.y-1 == H ) chk = true;
 
            point newP = {p.x, p.y-1};
            searchQ.push(newP);
        }
 
        if ( map[p.y][p.x+1] == '.' && move < visit[p.y][p.x+1] ) {
            visit[p.y][p.x+1] = move;
            if ( p.x+1 == W && p.y == H ) chk = true;
 
            point newP = {p.x+1, p.y};
            searchQ.push(newP);
        }
 
        if ( map[p.y+1][p.x] == '.' && move < visit[p.y+1][p.x] ) {
            visit[p.y+1][p.x] = move;
            if ( p.x == W && p.y+1 == H ) chk = true;
 
            point newP = {p.x, p.y+1};
            searchQ.push(newP);
        }
 
        if (chk) break;
    }
}
 
int main(){
    inputData();
 
    if (map[1][1] == '.') {
        point p = {1, 1}; // start point
        visit[1][1] = 0;
 
        searchQ.push(p);
        BFS();
    }
 
    int ans = (visit[H][W] == 0xFFFFFFFF) ? -1 : visit[H][W];
    cout << ans << endl;
 
    return 0;
}