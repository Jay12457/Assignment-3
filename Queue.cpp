#include "Queue.h"
#include <stdexcept>

Queue::Queue() : frontPtr(nullptr), rearPtr(nullptr), count(0) {}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        frontPtr = newNode;
        rearPtr = newNode;
    } else {
        rearPtr->next = newNode;
        rearPtr = newNode;
    }
    count++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    Node* temp = frontPtr;
    int value = temp->data;
    frontPtr = frontPtr->next;
    delete temp;
    count--;
    return value;
}

int Queue::front() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return frontPtr->data;
}

bool Queue::isEmpty() const {
    return count == 0;
}

int Queue::size() const {
    return count;
}
