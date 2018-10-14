#include <iostream>
#include <stack>
#include <map>
using namespace std;
map<char , int> inline_stack;
map<char , int> out_stack;
void initMap(){
    inline_stack['#'] = 0;
    inline_stack['('] = 1;
    inline_stack['^'] = 7;
    inline_stack['*'] = 5;
    inline_stack['/'] = 5;
    inline_stack['%'] = 5;
    inline_stack['+'] = 3;
    inline_stack['-'] = 3;
    inline_stack[')'] = 8;

    out_stack['#'] = 0;
    out_stack['('] = 8;
    out_stack['^'] = 6;
    out_stack['*'] = 4;
    out_stack['/'] = 4;
    out_stack['%'] = 4;
    out_stack['+'] = 2;
    out_stack['-'] = 2;
    out_stack[')'] = 1;

}


int optertor(string math_string){
    math_string += '#';
    stack<char> optr;
    stack<int> optd;
    optr.push('#');
    for(int i = 0 ; i < math_string.length() ; i++){
        if('0' <= math_string[i] && math_string[i] <= '9'){
            optd.push(math_string[i] - '0');
        }else if(math_string[i] == '(' || math_string[i] == '^' || math_string[i] == '*' || math_string[i] == '/' || math_string[i] == '%' || math_string[i] == '+' || math_string[i] == '-' || math_string[i] == ')' || math_string[i] == '#'){
            if(out_stack[math_string[i]] > inline_stack[optr.top()]){
                optd.push(math_string[i]);
            }else if(out_stack[math_string[i]] == inline_stack[optr.top()]) {
                optd.pop();
            }else{
                int temp = optd.top();
                optd.pop();
                switch (optr.top()){
                    case '+':
                        optd.top() += temp;
                        break;
                    case '-':
                        optd.top() -= temp;
                        break;
                    case '*':
                        optd.top() *= temp;
                        break;
                    case '/':
                        optd.top() /= temp;
                        break;
                    case '%':
                        optd.top() %= temp;
                        break;
                    case '^':
                        for(int i = 0 ; i < temp ; i++){
                            optd.top() *= optd.top();
                        }
                        break;
                    default:
                        break;
                }
            }
        }
    }
    return optd.top();
};


int main(){
    cout << optertor("1+2");

    return 0;
}
