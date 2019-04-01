/*
 * Filename: /Users/cho/work/problem/LG/2018_1_newcity.cpp
 * Path: /Users/cho/work/problem/LG
 * Created Date: Thursday, March 15th 2018, 3:01:01 pm
 * Author: cho
 * 
 * Copyright (c) 2018 Your Company
 */

#include <iostream>
using namespace std;

int N;//정사각형 지도 크기
int X, Y;//수돗물 공급되는 시작 좌표, 가로, 세로
int map[20][20];//지도 정보

void Input_Data(void){
	char str[20];
	cin >> N;
	cin >> X >> Y;
	for (int i = 0; i < N; i++){
		cin >> str;
		for(int j = 0; j < N; j++){
			if(str[j] < 'A') map[i][j] = str[j] - '0';
			else map[i][j] = str[j] - 'A' + 10;
		}
	}
}

int main(){
	int ans = -1;
	Input_Data();		//	입력 함수

	//	코드를 작성하세요
	
	
	cout << ans << endl;	//	정답 출력
	return 0;
}
