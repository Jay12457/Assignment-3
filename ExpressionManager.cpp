#include "ExpressionManager.h"

// Implementation for checking balanced parentheses
bool ExpressionManager::isBalanced(const std::string& expression) {
    std::stack<char> stack;
    for (char ch : expression) {
        if (ch == '{' || ch == '(' || ch == '[') {
            stack.push(ch);
        } else if (ch == '}' || ch == ')' || ch == ']') {
            if (stack.empty()) {
                return false;
            }
            char top = stack.top();
            stack.pop();
            if ((ch == '}' && top != '{') ||
                (ch == ')' && top != '(') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return stack.empty();
}

// Implementation for infix to postfix conversion
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/' || op == '%') {
        return 2;
    }
    return 0; // Default precedence for non-operators
}

std::string ExpressionManager::infixToPostfix(const std::string& infix) {
    std::string postfix;
    std::stack<char> operators;

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Remove the '('
        } else {
            while (!operators.empty() && precedence(ch) <= precedence(operators.top())) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}
