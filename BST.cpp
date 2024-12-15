#include "BST.h"

// Constructor
template <typename T>
BST<T>::BST() : root(nullptr) {}

// Helper function to insert a node recursively
template <typename T>
TreeNode<T>* BST<T>::insertNode(TreeNode<T>* node, T value) {
    if (!node)
        return new TreeNode<T>(value);
    if (value < node->value)
        node->LChild = insertNode(node->LChild, value);
    else if (value > node->value)
        node->RChild = insertNode(node->RChild, value);
    else
        throw invalid_argument("Duplicate values are not allowed in the BST.");
    return node;
}

// Insert a value into the BST
template <typename T>
void BST<T>::insert(T value) {
    root = insertNode(root, value);
}

// Helper function to delete a node recursively
template <typename T>
TreeNode<T>* BST<T>::deleteNode(TreeNode<T>* node, T value) {
    if (!node)
        return nullptr;

    if (value < node->value) {
        node->LChild = deleteNode(node->LChild, value);
    }
    else if (value > node->value) {
        node->RChild = deleteNode(node->RChild, value);
    }
    else {
        if (!node->LChild) {
            TreeNode<T>* temp = node->RChild;
            delete node;
            return temp;
        }
        else if (!node->RChild) {
            TreeNode<T>* temp = node->LChild;
            delete node;
            return temp;
        }
        TreeNode<T>* temp = findMin(node->RChild);
        node->value = temp->value;
        node->RChild = deleteNode(node->RChild, temp->value);
    }
    return node;
}

// Remove a value from the BST
template <typename T>
void BST<T>::remove(T value) {
    root = deleteNode(root, value);
}

// Helper function to find the minimum node
template <typename T>
TreeNode<T>* BST<T>::findMin(TreeNode<T>* node) {
    while (node && node->LChild)
        node = node->LChild;
    return node;
}

// Find the maximum value in the BST
template <typename T>
T BST<T>::findMax() {
    if (!root)
        throw runtime_error("BST is empty.");

    TreeNode<T>* current = root;
    while (current->RChild)
        current = current->RChild;
    return current->value;
}

// Helper function to traverse the tree in-order
template <typename T>
void BST<T>::inorderTraversal(TreeNode<T>* node, vector<T>& result) {
    if (node) {
        inorderTraversal(node->LChild, result);
        result.push_back(node->value);
        inorderTraversal(node->RChild, result);
    }
}

// Traverse the tree and return values in in-order
template <typename T>
vector<T> BST<T>::traverse() {
    vector<T> result;
    inorderTraversal(root, result);
    return result;
}

// Explicit template instantiation for BST<int> (this is needed to avoid redefinition error)
template class BST<int>;





