#include <iostream>

using namespace std;

int main() {
    int a;
    int b = 0;
    cin >> a;
    
    while(1) {
        if( a == 1 || a == 2) {
            cout << -1 << endl;
            break;
        }   
    
        if( a % 5 == 0) {
            b += a/5;
            cout << b << endl;
            break;
        }   

        a -= 3;
        ++b;
    }   
    return 0;
}
