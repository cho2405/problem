#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct hang{
    int a;
    char op;
};

hang arr[5000];

vector<hang> postfix;
stack<char> oprt;
stack<int> oprn;

int N;
void input_data(){
    int i;
    cin >> N;
    for(i=0 ; i<N ; i++){
        if( i % 2 == 0)
            cin >> arr[i].a;
        else
            cin >> arr[i].op;
    }           
}

int weight(char a) {
    switch(a) {
        case '+': case '-':
            return 2;
        case '*': case '/':
            return 3;
    }
    return -1;
}


void post() {

    for(int i = 0; i < N; i ++) {
        if (i % 2 == 0) {
            int cur = arr[i].a;

            postfix.push_back(hang({cur,'\0'}));
            continue;
        }
        char cur = arr[i].op;
        if (oprt.size() == 0 ) {
            oprt.push(cur);
            continue;
        }
        while (weight(oprt.top()) >= weight(cur)) {
            postfix.push_back(hang({-1, oprt.top()}));
            oprt.pop();

            if(oprt.size() == 0) break;
        }
        oprt.push(cur);
    }
    while (oprt.size() != 0){
        postfix.push_back(hang({-1, oprt.top()}));
        oprt.pop();
    }

}

void calculate() {
    for(unsigned int i =0; i < postfix.size(); i ++ ){
        int c = postfix[i].a;
        char ch = postfix[i].op;
        int tmp = 0;
        if (c != -1)
            oprn.push(c);

        else {
            int second = oprn.top(); 
            oprn.pop();
            int first = oprn.top();
            oprn.pop();

            if( ch == '+')
                tmp = first + second;
            else if ( ch == '-') 
                tmp = first - second;
            else if (ch == '*') 
                tmp = first * second;
            else if (ch == '/')
                tmp = first / second;

            oprn.push(tmp);
        }
    }
}
int main() {
    input_data();
    post();
    calculate();

    cout << oprn.top() << endl;


    return 0;
}

