#include <iostream>
#include <chrono>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    // To insert data into the stack
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    //To remove/delete data from the stack
    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        } else {
            std::cerr << "Stack underflow\n";
        }
    }
    
    //To check whethet the stack is empty or not
    bool isEmpty() {
        return top == nullptr;
    }
    
    // To find what is at the top of the stack
    int stackTop() {
        if (!isEmpty()) {
            return top->data;
        } else {
            std::cerr << "Stack is empty\n";
            return -1; 
        }
    }
    //Print the elements from the top of the stack to the bottom, separated by spaces
    void display() {
        Node* current = top;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    // Function to measure time and execute the given function
    template<typename Func>
    long long measureTime(Func func) {
        auto start = std::chrono::high_resolution_clock::now();
        func();
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }
};

int main() {
    Stack myStack;

    // Push operations
    long long pushTime = myStack.measureTime([&]() {
        myStack.push(8);
        myStack.push(10);
        myStack.push(5);
        myStack.push(11);
        myStack.push(15);
        myStack.push(23);
        myStack.push(6);
        myStack.push(18);
        myStack.push(20);
        myStack.push(17);
    });
    std::cout << "Time taken for push operations: " << pushTime << " nanoseconds\n";

    // Display operation
    long long displayTime = myStack.measureTime([&]() {
        myStack.display();
    });
    std::cout << "Time taken for display operation: " << displayTime << " nanoseconds\n";

    // Pop operations
    long long popTime = myStack.measureTime([&]() {
        for (int i = 0; i < 5; ++i) {
            myStack.pop();
        }
    });
    std::cout << "Time taken for pop operations: " << popTime << " nanoseconds\n";

    // Display operation after pops
    long long displayAfterPopTime = myStack.measureTime([&]() {
        myStack.display();
    });
    std::cout << "Time taken for display operation after pops: " << displayAfterPopTime << " nanoseconds\n";

    // Push operations
    long long pushTime2 = myStack.measureTime([&]() {
        myStack.push(4);
        myStack.push(30);
        myStack.push(3);
        myStack.push(1);
    });
    std::cout << "Time taken for second set of push operations: " << pushTime2 << " nanoseconds\n";

    // Display operation
    long long displayTime2 = myStack.measureTime([&]() {
        myStack.display();
    });
    std::cout << "Time taken for display operation after second set of pushes: " << displayTime2 << " nanoseconds\n";

    return 0;
}
