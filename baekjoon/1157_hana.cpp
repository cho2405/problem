#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    string a = "";
    int max = -1;
    int idx = -1;
    cin >> str;
    
    int *cnt = new int[26];

    for (int i = 0; i< 26; i++)
        cnt[i] = 0;

    int size = str.length();
    for (int i = 0; i < size; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            idx = str[i]-65;
        }   
        else if(str[i] >= 97 && str[i] <= 122) {
            idx = str[i]-97;
        }   
        cnt[idx]++;

        if(max == cnt[idx]) {
            a = "?";
        } else if (max < cnt[idx]) {
            a = toupper(str[i]);
            max = cnt[idx];
        }   
    }   
    cout << a << endl;

    return 0;
}

