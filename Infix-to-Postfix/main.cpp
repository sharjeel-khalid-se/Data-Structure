#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op){
    if(op == '^') return 3;
    if(op == '/' || op == '*') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
};

bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
};

// "Main tumhein infix naam ki ek string de raha hoon. Iski nayi copy mat banana taake memory aur time bache (via &), aur galti se bhi original string ko modify mat karna, sirf usko padhna (via const)."//
string infixToPostFix(const string& infix){
    stack<char> s;
    string postFix = "";

    for(char c : infix){
        if(c == ' ') continue;

        if(isalnum(c)){
            postFix += c;
            postFix += ' ';
        } else if(c == '('){
            s.push(c);
        } else if (c == ')'){
            while(!s.empty() && s.top() != '('){
                postFix += s.top();
                postFix += ' ';
                s.pop();
            }
            s.pop();
        } else if(isOperator(c)){
            while(!s.empty() && s.top() != '(' && precedence(s.top()) >= precedence(c)){
                postFix += s.top();
                postFix += ' ';
                s.pop();
            }

            s.push(c);
        }
    }

    while(!s.empty()){
        postFix += s.top();
        postFix += ' ';
        s.pop();
    }

    return postFix;
}


int main(){
     cout << infixToPostFix("A+B*C")     << "\n";
    // A B C * +

    cout << infixToPostFix("(A+B)*C")   << "\n";
    // A B + C *

    cout << infixToPostFix("A+B*C-D")   << "\n";
    // A B C * + D -

    cout << infixToPostFix("(A+B)*(C-D)") << "\n";
    // A B + C D - *
    return 0;
}