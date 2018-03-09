#include <iostream>

using namespace std;

int main() {
    auto a=0;
    char b[100] ={0,};
    cin >> a >> b;

    int sum = 0;  
    for(int i = 0; i < a; i++) {
        sum += (b[i] - 48);
    }   
    cout << sum << endl;
    return 0;
}
