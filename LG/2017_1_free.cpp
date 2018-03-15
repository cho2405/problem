#include <iostream>
#include <queue>

using namespace std;
int H;//세로크기
int W;//가로크기
char map[500][510];//지도
bool visit[500][510] = {false,};//지도
int result[500][510];//지도

struct Node {
	int x, y;
};

queue<Node> q;

Node w[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int BFS() {
	int x = 0, y = 0;
	if (map[x][y] == 'X') 
		return -1;

	q.push(Node({x, y}));
	result[0][0] = 1;
	visit[0][0] = true;

	while (!q.empty()) {
		Node f = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nxi = f.x + w[i].x;
			int nyi = f.y + w[i].y;

			if (nxi > H -1 || nyi > W -1 || nxi < 0 || nyi < 0)
				continue;	
			if (map[nxi][nyi] == '.' && !visit[nxi][nyi]) {
				visit[nxi][nyi] = true;
				q.push(Node({nxi, nyi}));
				result[nxi][nyi] = result[f.x][f.y] + 1;
			}
		}
	}
	return result[H-1][W-1] -1;
}
void input_data(){
	int i;
	cin >> H >> W;
	for(i=0 ; i<H ; i++){
		cin >> map[i];
	}
}

int main(){
	int ans = 0;
	input_data();

	ans = BFS();
	cout << ans << endl;
	return 0;
}


