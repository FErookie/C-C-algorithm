#include <iostream>
#include <stack>
#include <map>
#include <string>
using namespace std;

class Calculator{
public:
    string change(string s_mid);
    int compute(string s_beh);
    int cal(char a , char b , char opt);
};

int Calculator::cal(char a, char b, char opt) {
    int number1 = int(a - '0');
    int number2 = int(b - '0');
    switch(opt){
        case '+':
            return number1 + number2;

        case '-':
            return number1 - number2;

        case '*':
            return number1 * number2;

        case '/':
            return number1 / number2;

    }
};

string Calculator::change(string s_mid) {
    string s_beh="";
    stack<char> stk;
    map<char,int> op;
    op['(']=0;
    op[')']=0;
    op['+']=1;
    op['-']=1;
    op['*']=2;
    op['/']=2;
    string::iterator it=s_mid.begin();;
    while(it!=s_mid.end())
    {
        if(op.count(*it))
        {
            if(*it==')')
            {
                while(stk.top()!='(')
                {
                    s_beh+=stk.top();
                    stk.pop();
                }
                stk.pop();
            }
            else if(stk.empty()||*it=='('||op[*it]>op[stk.top()])
            {
                stk.push(*it);
            }
            else if(op[*it]<=op[stk.top()])
            {
                while(op[*it]<=op[stk.top()]&&(!stk.empty()))
                {
                    s_beh+=stk.top();
                    stk.pop();
                    if(stk.empty()) break;
                }
                stk.push(*it);
            }
        }
        else
        {
            s_beh+=*it;
        }
        it++;


        if(it==s_mid.end())//当中缀表达式输出完成，所有元素出栈
        {
            while(!stk.empty())
            {
                s_beh+=stk.top();
                stk.pop();
            }
            break;
        }
    }
    return s_beh;
};

int Calculator::compute(string s_beh) {
  int i = 0;
  stack <int> result;

  while(s_beh[i] != '\0'){
      if(s_beh[i] <= '9' && '0' <= s_beh[i]){
        result.push(s_beh[i]);
      }else{
        int temp = result.top();
        result.pop();
        int result_number = cal(temp , result.top() , s_beh[i]);
        cout << "这是第"  << i << "次运算" << result_number << endl;
        result.pop();
        result.push(result_number);
      }
      i++;
  }
  return result.top();
};

int main(){
    Calculator test1;
    cout << test1.change("1+2*(7+1)") << endl;
    cout << test1.compute(test1.change("1+2*(7+1)"));
    return 0;
}
