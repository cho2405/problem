#include <iostream>
#include <stack>
#include <vector>

using namespace std;

char arr[100];

vector<char> postfix;
stack<char> oprt;

int weight(char a) {
    switch(a) {
        case '+': case '-':
            return 2;
        case '*': case '/':
            return 3;
    }
    return -1;
}


int main() {
    scanf("%s", arr);
    int cnt = 0;
    while (1) {
        char cur = arr[cnt++];
        if (cur == '\0')
            break;

        if (cur >= 'A' && cur <= 'Z') {
            postfix.push_back(cur);
            continue;
        }
        
        if (oprt.size() == 0 || cur == '(') {
            oprt.push(cur);
            continue;
        }

        if (cur == ')') {
            while (oprt.size() != 0) {
                char top = oprt.top();
                oprt.pop();
                if (top  == '(') {
                    break;
                }
                postfix.push_back(top);
            }
            continue;
        }
        if (oprt.top() == '(') {
            oprt.push(cur);
            continue;
        }

        while (weight(oprt.top()) >= weight(cur)) {
            postfix.push_back(oprt.top());
            oprt.pop();

            if(oprt.size() == 0)
                break;
        }
        oprt.push(cur);

    }
    while (oprt.size() != 0){
        if (oprt.top() != '(')
            postfix.push_back(oprt.top());
        oprt.pop();
    }

    for (unsigned int i = 0; i < postfix.size(); i++) {
        printf("%c", postfix[i]);
    }
    printf("\n");
    return 0;
}
