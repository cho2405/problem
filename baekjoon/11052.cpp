#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 1000
int N;
int arr[MAX];
int cache[MAX];

int hana(int n) {
    if (n == 0) return cache[0] = arr[0];
    if (cache[n] > -1) return cache[n];
    
    int ret = -1;
    for (int i = 0; i < (n+1)/2; i++) {
        ret = max(hana(i) + hana(n-i-1), ret);
    }
    return cache[n] = max(ret, arr[n]);
}

int main() {
    cin >> N; 
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        cache[i] = -1;
    }
    cout << hana(N-1) << endl;
    
    return 0;
}