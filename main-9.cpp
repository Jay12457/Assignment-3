#include <iostream>
#include "ExpressionManager.h"
#include "Queue.h"

int main() {
    // Example usage of ExpressionManager for infix to postfix conversion and balanced parentheses check
    ExpressionManager expressionManager;
    std::string infixExpression;

    std::cout << "Enter an infix expression: ";
    std::cin >> infixExpression;

    if (expressionManager.isBalanced(infixExpression)) {
        std::string postfixExpression = expressionManager.infixToPostfix(infixExpression);
        std::cout << "Postfix Expression: " << postfixExpression << std::endl;
    } else {
        std::cout << "The expression is not balanced." << std::endl;
    }

    // Example usage of Queue
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Front element: " << myQueue.front() << std::endl;

    myQueue.dequeue();
    std::cout << "Front element after dequeue: " << myQueue.front() << std::endl;
    std::cout << "Queue size: " << myQueue.size() << std::endl;

    return 0;
}
