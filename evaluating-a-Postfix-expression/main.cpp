#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

int evaluatePostfix(const string& expression){
    stack<int> s;
    stringstream ss(expression);
    string token;

    while(ss >> token){
        if(token != "+" && token != "-" && token != "*" && token != "/"){
            s.push(stoi(token));
        } else {
            int op2  = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
             int result = 0;
            if      (token == "+") result = op1 + op2;
            else if (token == "-") result = op1 - op2;
            else if (token == "*") result = op1 * op2;
            else if (token == "/") result = op1 / op2;

            s.push(result);
        }

    }
     return s.top();
};

int main(){
// 4 + 3*2 = 10
    cout << evaluatePostfix("4 3 2 * +") << "\n";  // 10

    // (4+3) * 2 = 14
    cout << evaluatePostfix("4 3 + 2 *") << "\n";  // 14

    // 6-2+3 = 7
    cout << evaluatePostfix("6 2 - 3 +") << "\n";  // 7

    return 0;
}