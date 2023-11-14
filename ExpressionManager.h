#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H

#include <string>
#include <stack>

class ExpressionManager {
public:
    bool isBalanced(const std::string& expression);
    std::string infixToPostfix(const std::string& infix);
};

#endif // EXPRESSION_MANAGER_H
