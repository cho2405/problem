#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int** map;
int* order;

void DFS(int x, int y, int num) {
    
    order[num]++;
    map[x][y] = -1;

    if (x > 0 && map[x - 1][y] == 1) DFS(x - 1, y, num);
    if (x < n - 1 && map[x + 1][y] == 1) DFS(x + 1, y, num);
    if (y > 0 && map[x][y - 1] == 1) DFS(x, y - 1, num);
    if (y < n - 1 && map[x][y + 1] == 1) DFS(x, y + 1, num);

}

int main(){
    cin >> n;
    map = new int*[n];
    order = new int[n*n];

    for (int i = 0; i < n*n; i++) 
        order[i] = 0;

    for (int i = 0; i < n; i++) {
        map[i] = new int[n];
        for (int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1) {
                DFS(i, j, cnt++);
            }      
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] != 0)
                order[map[i][j] - 2]++;
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << cnt << endl; 
    sort(order, order + cnt);
    for (int i = 0; i < cnt; i++) 
        cout << order[i] << endl;;
    return 0;
}
