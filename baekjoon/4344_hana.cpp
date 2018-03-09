#include <iostream>
#include <stdio.h>
#include <cmath>

#define ROUNDING(x, dig)    ( floor((x) * pow(float(10), dig) + 0.5f) / pow(float(10), dig) )

using namespace std;

int main() {
    auto a = 0, b = 0;
    cin >> a;

    while(a > 0) {
        cin >> b; 
        int sum = 0;
        double avg = 0;
        int *c = new int[b];
        for(int i = 0; i < b; i++) {
            cin >> c[i];
            sum += c[i];
        }       

        avg = sum/b;
        int cnt = 0;

        for(int i = 0; i < b; i++) {
            if(avg < c[i]) 
                cnt++; 
        }           
        double result = (double)cnt/b * 100;
        printf("%.3f%%\n", result);
        a--;
    }       
    return 0;
}

