#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack 
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary

private:
    std::vector<T> stack_;
    int topIndex;
};

template <typename T>
Stack<T>::Stack() : topIndex(-1) {
    // Constructor: Initialize the top index to -1
}

template <typename T>
Stack<T>::~Stack() {
    // Destructor: Nothing to do here since stack_ is a std::vector and will be automatically cleaned up
}

template <typename T>
bool Stack<T>::empty() const {
    // Check if the stack is empty
    return (topIndex == -1);
}

template <typename T>
size_t Stack<T>::size() const {
    // Return the size of the stack
    return static_cast<size_t>(topIndex + 1);
}

template <typename T>
void Stack<T>::push(const T& item) {
    // Push the item onto the stack
    stack_.push_back(item);
    topIndex++; // Increment the top index
}

template <typename T>
void Stack<T>::pop() {
    // Check if the stack is empty
    if (empty()) {
        throw std::underflow_error("Stack is empty");
    } else {
        // Pop the item from the stack
        stack_.pop_back();
        topIndex--; // Decrement the top index
    }
}

template <typename T>
const T& Stack<T>::top() const {
    // Check if the stack is empty
    if (empty()) {
        throw std::underflow_error("Stack is empty");
    } else {
        // Return the top item of the stack
        return stack_[topIndex];
    }
}
