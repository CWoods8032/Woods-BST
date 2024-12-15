#include <iostream>
#include "BST.h"

int main() {
    BST<int> bst;

    // Test 1: Insertion and traversal
    vector<int> data = { 50, 30, 70, 20, 40, 60, 80 };
    for (int val : data) {
        bst.insert(val);
    }

    cout << "In-order traversal after insertion: ";
    for (int val : bst.traverse()) {
        cout << val << " ";
    }
    cout << "\n";

    // Test 2: Attempt to insert a duplicate value
    try {
        bst.insert(30);  // Duplicate value
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Test 3: Maximum value in BST
    cout << "Maximum value in BST: " << bst.findMax() << "\n";

    // Test 4: Attempt to remove a node from an empty BST
    BST<int> empty_bst;
    try {
        empty_bst.remove(10);  // Should handle the case
        cout << "Error: Cannot remove from an empty BST.\n";
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Test 5: Remove node with no children (leaf node)
    bst.remove(20);  // Node with no children (leaf node)
    cout << "In-order traversal after removing leaf node (20): ";
    for (int val : bst.traverse()) {
        cout << val << " ";
    }
    cout << "\n";

    // Test 6: Remove node with one child
    bst.remove(30);  // Node with one child (40)
    cout << "In-order traversal after removing node with one child (30): ";
    for (int val : bst.traverse()) {
        cout << val << " ";
    }
    cout << "\n";

    // Test 7: Remove node with two children
    bst.remove(50);  // Node with two children (30, 70)
    cout << "In-order traversal after removing node with two children (50): ";
    for (int val : bst.traverse()) {
        cout << val << " ";
    }
    cout << "\n";

    // Test 8: Verify BST structure after all removals (In-order should be sorted)
    cout << "Final In-order traversal (should be sorted): ";
    for (int val : bst.traverse()) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}





