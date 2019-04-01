#include <iostream>
#include <stack>
#include <vector>

using namespace std;

char arr[30];
stack<char> stk;
int cnt1 = 0, cnt2 = 0;

int main () {
    scanf("%s" ,arr);
    int cnt = 0;
    char c = arr[cnt];

    stk.push(c);
    int sum = 0;

    int mul = 1;
    while (c != '\0') {
      c = arr[cnt];

      if (c == '(') {
          if( arr[cnt+1] == '(')
        cout << "PUSH: 2" << endl;
      }
      if (c == '[') {
        cout << "PUSH: 3" << endl;
      }
      if (c == ')') {
        mul *= 2;
        sum += mul;
        cout << "POPP: 2, ret: " << sum << endl;
      }
      if (c == ']') {
        mul *= 3;
        sum += mul;
        cout << "POPP: 3, ret: " << sum << endl;
      }
        cnt++;
    }
    cout << sum << endl;
    return 0;
}
      