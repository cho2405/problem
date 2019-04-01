#include <iostream>

using namespace std;

int N;//정사각형 지도 크기
int X, Y;//수돗물 공급되는 시작 좌표, 가로, 세로
int map[20][20] = {-1,};//지도 정보
int w[12][4] = {
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
int total = 0;
void pipe(int x, int y) {
    if( x < 0 || y < 0 || x >= N || y >= N) 
      return;    
    int c = map[x][y];
	if( c == 0)
		return;
	
	map[x][y] = 0;
	cnt++;
    
    for (int i = 0; i < 4; i++) {
        if(!w[c][i])
            continue;
				
        if (i == 0 && x -1 >= 0 && w[map[x-1][y]][1] && map[x-1][y] != 0)
			pipe(x-1, y);
        if (i == 1 && w[map[x+1][y]][0] && map[x+1][y] != 0) 
			pipe(x+1, y); 
        if (i == 2 && y-1 >= 0 && w[map[x][y-1]][3] && map[x][y-1] != 0) 
            pipe(x, y-1); 
        if (i == 3 && w[map[x][y+1]][2] && map[x][y+1] != 0) 
			pipe(x, y+1); 
    }
}
void Input_Data(void){
	char str[20];
	cin >> N;
	cin >> X >> Y;
	for (int i = 0; i < N; i++){
		cin >> str;
		for(int j = 0; j < N; j++){
			if(str[j] !='0')
				total++;
			if(str[j] < 'A') map[i][j] = str[j] - '0';
			else map[i][j] = str[j] - 'A' + 10;
		}
	}
}

int main(){
	int ans = -1;
	Input_Data();		//	입력 함수

	pipe(X, Y);
	ans = total- cnt;
	cout << ans << endl;
	return 0;
}