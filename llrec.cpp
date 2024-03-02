#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    // Base case: if head is null, both smaller and larger lists are empty
    if (head == nullptr) {
        smaller = nullptr;
        larger = nullptr;
        return;
    }
    
    // Recursively partition the rest of the list
    Node *next_node = head->next;
    // Recursive call to partition the rest of the list
    llpivot(next_node, smaller, larger, pivot);
    
    // Adjust the current node's next pointer based on the pivot
    if (head->val <= pivot) {
        // Append the current node to the smaller list
        head->next = smaller;
        smaller = head;
    } else {
        // Append the current node to the larger list
        head->next = larger;
        larger = head;
    }
    // Update head to the next node in the original list
    head = next_node;
}
