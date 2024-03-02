#include <iostream>
#include <fstream>
#include <functional>
#include "stack.h"

using namespace std;

int main() {
    // Create a Stack object with a custom container type (deque)
    Stack<int, deque<int>> myStack;

    // Push elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // Print the size and top item of the stack
    cout << "Stack size: " << myStack.size() << endl;
    cout << "Top item: " << myStack.top() << endl;

    // Pop two elements from the stack
    myStack.pop();
    myStack.pop();

    // Print the size and top item of the stack again
    cout << "Stack size: " << myStack.size() << endl;
    cout << "Top item: " << myStack.top() << endl;

    return 0;
}
