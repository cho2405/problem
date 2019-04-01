#include <iostream>

using namespace std;
#define MAX 10

int sumOfRow[MAX];
char chairs[MAX][MAX];

void init(int b) {
	for (int j = 0; j < b; j++) {
		sumOfRow[j] = 0; 
	}
}


int cache[MAX];
int calculate(int b) {
	cache[0] = sumOfRow[0];
	cache[1] = sumOfRow[1];
	int maxValue = -1;
	for (int j = 2; j < b; j++) {	
		maxValue = cache[j-1];
		for (int k = j - 2; k >= 0; k--) {
			maxValue = max(maxValue, cache[k] + sumOfRow[j]);
		}
	}	

	return maxValue;
	
}
void summate(int a, int b) {
	for (int j = 0; j < b; j++) {
		for (int i = 0; i < a; i++) {
			if (chairs[i][j] == '.')
				sumOfRow[j] += 1;
		}	
	}
}

int main() {
    int T;

    cin >> T;

    while ( T-- > 0) {
        int a, b;
        cin >> a >> b;
        for (int i = 0; i < a; i++) {
            scanf("%s", chairs[i]);
        }

		init(b);	
		summate(a, b);

		cout << calculate(b) << endl;
	}
    return 0;
}
