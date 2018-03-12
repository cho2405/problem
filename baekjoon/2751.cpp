#include <cstdio>
#include <vector>
using namespace std;

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y= tmp;
}

void heapify(vector<int>& v, int key, int length) {
    v[length] = key;
    int i = length; 
    while (i != 1) {
        int j = i/2;

        if (v[j] > v[i]) {
            swap(&v[i], &v[j]);
            i = j;
        } else {
            break;
        }   
    }   
}

int root(vector<int>& v, int length) {
    int i = 1;
    int ret = v[i];
    v[i] = v.back();
    v.pop_back();

    while (1) {
        int left = 2*i;
        int right = 2*i+1;


        if (right > length && left > length) {
            break;
        }   

        else if (right > length) {
            if (v[i] < v[left]) break;
            swap(&v[i], &v[left]);
            i = left;
        }   

        else {

            if (v[left] < v[right]) {
                if (v[i] < v[left]) break;
                swap(&v[i], &v[left]);
                i = left;
            }   

            else {
                if (v[i] < v[right]) break;
                swap(&v[i], &v[right]);
                i = right;
            }   
        }   
    }   

    return ret;
}


int main() {
    int n;
    scanf("%d", &n);

    vector<int> v;
    v.resize(n+1); 

    for (int i=1; i<=n; i++) {
        int x;
        scanf("%d", &x);
        heapify(v, x, i); 
    }   

    for (int i=0; i<n; i++) {
        printf("%d\n", root(v, n-i));
    }   

    return 0;
}