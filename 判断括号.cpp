#include <iostream>
#include <stack>
using namespace std;
int main() {
	string check_string;
	cout << "请输入你要检查的括号字符串" << endl;
	stack<char> check_stack;
	cin >> check_string;
	if(check_string[0]){
        check_stack.push(check_string[0]);
	}
	for(int i = 1 ; i < check_string.length() ; i++){
		//cout << check_string[i];
		if(((check_string[i] == ')') && (check_stack.top() == '(' ) )||((check_string[i] == ']') && (check_stack.top() == '[')) || ((check_string[i] == '}') && (check_stack.top() == '{' ) )){
			check_stack.pop();
		}else{
			check_stack.push(check_string[i]);
		}
	}
    if(check_stack.empty()){
        cout << "这是一个合法的串" << endl;
    }else{
        cout << "这不是一个合法的串" << endl;
    }
	return 0;
}
