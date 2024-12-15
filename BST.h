#pragma once

#include <vector>
#include <stdexcept>

using namespace std;

// Templated TreeNode structure
template <typename T>
struct TreeNode {
    T value;
    TreeNode* LChild;
    TreeNode* RChild;

    TreeNode(T val) : value(val), LChild(nullptr), RChild(nullptr) {}
};

// Templated Binary Search Tree class
template <typename T>
class BST {
private:
    TreeNode<T>* root;

    TreeNode<T>* insertNode(TreeNode<T>* node, T value);
    TreeNode<T>* deleteNode(TreeNode<T>* node, T value);
    TreeNode<T>* findMin(TreeNode<T>* node);
    void inorderTraversal(TreeNode<T>* node, vector<T>& result);

public:
    BST();
    void insert(T value);
    void remove(T value);
    T findMax();
    vector<T> traverse();
};

// Explicit template instantiation (only declare, don't define the methods here)
extern template class BST<int>;








