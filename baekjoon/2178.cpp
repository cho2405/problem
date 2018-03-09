#include <iostream>
#include <vector>

using namespace std;

int** map;
int a, b;
int min_num = 10000;

void DFS(int x, int y, int num) {
    if (min_num < num + 2) return;
    if (x == a-2 && y == b-2) {
        min_num = num +2;
        return;
    }
    if (x == a-1 && y == b-2) {
        min_num = num +1;
        return;
    }
    if (x == a-2 && y == b-1) {
        min_num = num +1;
        return;
    }
    if (x == a-1 && y == b-1) {
        min_num = num;
        return;
    }   

    map[x][y] = -1;

    if (x < a - 1 && map[x + 1][y] == 1) DFS(x + 1, y, num+1);
    if (y < b - 1 && map[x][y + 1] == 1) DFS(x, y + 1, num+1);
    if (x > 0 && map[x - 1][y] == 1) DFS(x - 1, y, num+1);
    if (y > 0 && map[x][y - 1] == 1) DFS(x, y - 1, num+1);
   
    map[x][y] = 1;
}
int main() {

    cin >> a >> b;
    map = new int*[a];

    for(int i = 0; i < a; i++) {
        map[i] = new int[b];
        for(int j = 0; j < b; j++) 
            scanf("%1d", &map[i][j]);
    }
    DFS(0, 0, 1);
    cout << min_num << endl;
    return 0;
}
