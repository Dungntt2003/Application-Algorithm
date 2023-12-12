#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isCorrectExpression(const string& expr) {
    stack<char> stk;
    unordered_map<char, char> closingMap = {{')', '('}, {']', '['}, {'}', '{'}};

    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stk.empty() || stk.top() != closingMap[c]) {
                return false;
            }
            stk.pop();
        }
    }

    return stk.empty();
}

int main() {
    string expr;
    getline(cin, expr);

    if (isCorrectExpression(expr)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}