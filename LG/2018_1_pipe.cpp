#include <iostream>

using namespace std;
int N;
int a, b;

int map[10][10];
int w[][4] = {
    {0,0,0,0},
    {0,0,1,1},
    {1,1,0,0},
    {0,1,0,1},
    {0,1,1,0},
    {1,0,1,0},
    {1,0,0,1},
    {1,1,0,1},
    {0,1,1,1},
    {1,1,1,0},
    {1,0,1,1},
    {1,1,1,1}
};
int cnt = 0;

void pipe(int x, int y) {

    if( x < 0 || y < 0 || x >= N || y >= N) 
        return;    
    int c = map[x][y];
    map[x][y] = 0;
    cnt++;
    for (int i = 0; i < 4; i ++) {
        if(!w[c][i])
            continue;
        if (i == 0 && /*x >= 0 && y-1 >= 0 && x < N && y-1 < N &&*/ map[x][y-1] != 0) 
            pipe(x, y-1);
        if (i == 1 && /*x >= 0 && y+1 >= 0 && x < N && y+1 < N && */map[x][y+1] != 0) 
            pipe(x, y+1); 
        if (i == 2 && /*x-1 >= 0 && y >= 0 && x-1 < N && y < N &&*/ map[x-1][y] != 0) 
            pipe(x-1, y); 
        if (i == 3 && /*x+1 >= 0 && y >= 0 && x+1 < N && y < N &&*/ map[x+1][y] != 0) 
            pipe(x+1, y); 
    }
}

void input_data() {
    int i,j;
    cin >> N;
    cin >> a >> b;
    for(i=0 ; i<N ; i++){
        for(j=0; j<N; j++){
            scanf("%1d", &map[i][j]);
        }
    }
}

int main() { 
    //int ans = 0;
    input_data();

    pipe(a, b);
    cout << N*N - cnt -1 << endl;
    return 0;
}

