#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int n;
int** arr;
vector<int> nums;

void DFS(int x, int y, int num) {

    nums[num]++;
    arr[x][y] = -1;

    if (x > 0 && arr[x - 1][y] == 1) DFS(x - 1, y, num);
    if (x < n - 1 && arr[x + 1][y] == 1) DFS(x + 1, y, num);
    if (y > 0 && arr[x][y - 1] == 1) DFS(x, y - 1, num);
    if (y < n - 1 && arr[x][y + 1] == 1) DFS(x, y + 1, num);

}

int main(){
    cin >> n;
    arr = new int*[n];
    nums.assign(n*n, 0);
    
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) {
                DFS(i, j, cnt++);
            }      
        }
    }
    nums.resize(cnt);
    sort(nums.begin(), nums.end());

    cout << cnt << endl; 
    
    for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++){
        cout << *iter << endl;
    }

    return 0;
}
