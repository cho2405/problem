#include <iostream>
#include <vector>

using namespace std;

int* map;
int a, b;
int max_num = -1;

void DFS(int x, int num) {
    if (max_num < num) return;
    if (x == a-1) {
        max_num = num;
        return;
    }   

    map[x] = -1;
   
}

int main() {

    cin >> a;
    map = new int[a];

    for(int i = 0; i < a; i++) {
        scanf("%d", &map[i]);
    }
    DFS(0, 1);
    DFS(0, 2);
    cout << max_num << endl;
    return 0;
}
