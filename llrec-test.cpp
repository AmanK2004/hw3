#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------
struct isEven {
	bool operator()(int x) const {
		return (x & 1) == 0; // Check if the least significant bit is 0
	} 
};

int main(int argc, char* argv[])
{
    // Check if an input file is provided as a command-line argument
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------

    // Read the linked list from the input file
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);
    cout << endl;

    // Test out your linked list code

    // Test 1: llpivot function
    cout << "Test 1" << endl;
    cout << "Original List Before: ";
    print(head);
    Node* smallerList;
    Node* largerList;
    // Partition the list around a pivot value of 10
    llpivot(head, smallerList, largerList, 10);
    cout << "Smaller List: ";
    print(smallerList);
    cout << "Larger List: ";
    print(largerList);
    cout << "Original List After: ";
    if (head == NULL) {
        cout << "empty" << endl;
    }
    cout << endl;

    // Test 2: llfilter function
    cout << "Test 2" << endl;
    // Reset the original list
    head = readList(argv[1]);
    cout << "Original List Before: ";
    print(head);
    // Define a predicate functor to filter even numbers
    isEven c1;
    // Filter the list using the llfilter function
    Node* filteredList = llfilter(head, c1);
    cout << "Filtered List: ";
    print(filteredList);

    return 0;
}
