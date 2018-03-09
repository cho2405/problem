/*
 * Filename: /Users/cho/GoogleDrive/02_Develop/codepro/1667.cpp
 * Path: /Users/cho/GoogleDrive/02_Develop/codepro
 * Created Date: Wednesday, March 7th 2018, 1:14:14 pm
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */
#include <iostream>

using namespace std;
int** map;
int** visit;
int* check;
void DFS(int x, int y, int c) {
    visit[x][y] = -1;

    if (visit[x + 1][y] != -1 && map[x + 1][y] == 1) {
      check[c]++;
      DFS(x + 2, y, c);
    } else if (visit[x][y + 1] != -1 && map[x][y + 1] == 1) {
      check[c]++;
      DFS(x, y + 1, c);
    }
}

int main() {
    int n; 
    cin >> n;

    map = new int *[n];
    check = new int[n];
    for (int i = 0; i < n; i++){ 
        map[i] = new int[n];
        check[i] = 0;
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    /*
    for (int i = 0; i < n; i++){ 
        for (int j = 0; j < n; j++) {
            cout << i << " " << j << "    ";
        }
        cout << endl;

    }
    */

    DFS(0, 0, 0);
    return 0;
}
