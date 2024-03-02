#include <iostream>
#include <fstream>
#include "heap.h"

using namespace std;

int main() {
    // Create a Heap object with a custom comparator
    Heap<int, greater<int>> myHeap; // Use greater<int> to create a min heap

    // Push elements onto the heap
    myHeap.push(3);
    myHeap.push(2);
    myHeap.push(1);

    // Print the size and top item of the heap
    cout << "Heap size: " << myHeap.size() << endl;
    cout << "Top item: " << myHeap.top() << endl;

    // Pop two elements from the heap
    myHeap.pop();
    myHeap.pop();

    // Print the size and top item of the heap again
    cout << "Heap size: " << myHeap.size() << endl;
    cout << "Top item: " << myHeap.top() << endl;

    return 0;
}