#include <iostream>

using namespace std;

int isHansu(int n) {
    int *c = new int[4];
    int i = 0;  

    for (i = 0; n > 0; i++) {
        c[i] = n % 10; 
        n /= 10; 
    }   

    int j = 1;  
    while (j + 1 < i) {
        if ((c[j] - c[j-1]) != (c[j+1] - c[j])) {
            return 0;
        }   
        j++;
    }   
    return 1;
}

int main() {
    int a = 0, cnt = 0;
    cin >> a;
    if (a <= 99) {
        cnt = a;    
    }   
    else {
        cnt += 99; 
        while (a > 99) {
            if (isHansu(a--))
                cnt++;
        }   
    }   
    cout << cnt << endl;
    return 0;
}

