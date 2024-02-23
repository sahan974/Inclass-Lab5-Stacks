#include <iostream>
#include <chrono>

class Stack {
private:
    int* array;
    int top;
    int size;

public:
    Stack(int maxSize) {
        size = maxSize;
        array = new int[size];
        top = -1;
    }

    //To check whethet the stack is empty or not
    bool isEmpty() {
        return top == -1;
    }
   
    //To check whether the stack is full or not
    bool isFull() {
        return top == size - 1;
    }

    // To insert data into the stack
    void push(int x) {
        if (isFull()) {
            std::cerr << "Error: Stack overflow\n";
        } else {
            top++;
            array[top] = x;
        }
    }
    
    //To remove/delete data from the stack
    void pop() {
        if (isEmpty()) {
            std::cerr << "Error: Stack underflow\n";
        } else {
            top--;
        }
    }

    // To find what is at the top of the stack
    int stackTop() {
        if (isEmpty()) {
            std::cerr << "Error: Stack is empty\n";
            return -1; 
        } else {
            return array[top];
        }
    }

    //Print the elements from the top of the stack to the bottom, separated by spaces
    void display() {
        for (int i = top; i >= 0; i--) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
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
    Stack myStack(10);

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
