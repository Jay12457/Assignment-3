#ifndef QUEUE_H
#define QUEUE_H

class Queue {
public:
    Queue();
    ~Queue();

    void enqueue(int value);
    int dequeue();
    int front() const;
    bool isEmpty() const;
    int size() const;

private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* frontPtr;
    Node* rearPtr;
    int count;
};

#endif // QUEUE_H
