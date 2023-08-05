#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

struct BinarySearchTree {
    TreeNode* root;

    TreeNode* insertHelper(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertHelper(node->left, value);
            //recursive function
        } else if (value > node->data) {
            node->right = insertHelper(node->right, value);
        }

        return node;
    }

    void preOrderTraversalHelper(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        std::cout << node->data << " ";//print -> parent
        preOrderTraversalHelper(node->left);
        preOrderTraversalHelper(node->right);
    }

    void postOrderTraversalHelper(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        postOrderTraversalHelper(node->left);
        postOrderTraversalHelper(node->right);
        std::cout << node->data << " ";
    }

    void inOrderTraversalHelper(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        inOrderTraversalHelper(node->left);
        std::cout << node->data << " ";
        inOrderTraversalHelper(node->right);
    }

    TreeNode* searchHelper(TreeNode* node, int value) {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return searchHelper(node->left, value);
        } else {
            return searchHelper(node->right, value);
        }
    }

    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertHelper(root, value); // == node
    }

    void preOrderTraversal() {
        std::cout << "Preorder Traversal: ";
        preOrderTraversalHelper(root);
        std::cout << std::endl;
    }

    void postOrderTraversal() {
        std::cout << "Postorder Traversal: ";
        postOrderTraversalHelper(root);
        std::cout << std::endl;
    }

    void inOrderTraversal() {
        std::cout << "Inorder Traversal: ";
        inOrderTraversalHelper(root);
        std::cout << std::endl;
    }

    TreeNode* search(int value) {
        return searchHelper(root, value);
    }
};

int main() {
    BinarySearchTree bst;

    // Insert elements into the binary search tree
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Perform different traversals
    bst.preOrderTraversal();
    bst.postOrderTraversal();
    bst.inOrderTraversal();

    // Search for an element in the binary search tree
    int valueToSearch = 60;
    TreeNode* searchResult = bst.search(valueToSearch);
    if (searchResult != nullptr) {
        std::cout << valueToSearch << " found in the binary search tree." << std::endl;
    } else {
        std::cout << valueToSearch << " not found in the binary search tree." << std::endl;
    }

    return 0;
}