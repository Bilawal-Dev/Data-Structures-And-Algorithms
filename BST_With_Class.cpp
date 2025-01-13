#include <iostream>
using namespace std;

// Definition of a Node in the BST
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Class representing the Binary Search Tree
class BST {
public:
    Node *root;

    BST() {
        root = NULL;
    }

    void insertIterative(int val) {
        Node *newNode = new Node(val);

        if (root == NULL) {
            root = newNode;
            return;
        }

        Node *current = root;
        Node *parent = current;

        while (current != NULL) {
            parent = current;

            if (val > current->data) {
                current = current->right;
            } else if (val < current->data) {
                current = current->left;
            } else {
                // Value already exists, no need to insert
                return;
            }
        }

        if (val > parent->data) {
            parent->right = newNode;
        } else {
            parent->left = newNode;
        }
    }

    // Function to insert a value into the BST
    void insertRecursive(int val) {
        root = insertRecursiveHelper(root, val);
    }

    // Recursive function to insert a value into the BST
    Node *insertRecursiveHelper(Node *node, int val) {
        // If the tree is empty, create a new node and return it
        if (node == NULL) {
            return new Node(val);
        }

        // Otherwise, recur down the tree
        if (val < node->data) {
            node->left = insertRecursiveHelper(node->left, val);
        } else if (val > node->data) {
            node->right = insertRecursiveHelper(node->right, val);
        }

        // Return the (unchanged) node pointer
        return node;
    }

    // Iterative function to search for a value in the BST
    bool searchIterative(int val){
        Node* temp = root;

        while(temp != NULL){
            if(temp->data == val){
                return true;
            }
            else if(temp->data > val){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }

        return false;
    }

    // Function to search for a value in the BST
    bool searchRecursive(int val) {
        return searchRecursiveHelper(root, val);
    }

    // Recursive function to search for a value in the BST
    bool searchRecursiveHelper(Node *node, int val) {
        // Base case: root is null
        if (node == NULL) {
            return false;
        }

        if(node->data == val){
            return true;
        }
        // Key is greater than root's key
        else if (val < node->data) {
            return searchRecursiveHelper(node->left, val);
        } 
        else {
            // Key is smaller than root's key
            return searchRecursiveHelper(node->right, val);
        }
    }

    // Function for inorder traversal of the BST
    void inorder() {
        inorderHelper(root);
        cout << endl;
    }

    // Recursive function for inorder traversal of the BST
    void inorderHelper(Node *node) {
        if(node == NULL){
            return;
        }

        inorderHelper(node->left);
        cout << node->data << " -> ";
        inorderHelper(node->right);
    }

    // Function for preorder traversal of the BST
    void preorder() {
        preorderHelper(root);
        cout << endl;
    }

    // Recursive function for preorder traversal of the BST
    void preorderHelper(Node *node) {
        if (node != NULL) {
            cout << node->data << " -> ";
            preorderHelper(node->left);
            preorderHelper(node->right);
        }
    }

    // Function for postorder traversal of the BST
    void postorder() {
        postorderHelper(root);
        cout << endl;
    }

    // Recursive function for postorder traversal of the BST
    void postorderHelper(Node *node) {
        if (node != NULL) {
            postorderHelper(node->left);
            postorderHelper(node->right);
            cout << node->data << " -> ";
        }
    }

    // Function to delete a node from the BST
    void deleteNode(int key){
        root = deleteNodeHelper(root, key);
    }

    // Recursive Helper function to delete a node from the BST
    Node* deleteNodeHelper(Node* node, int key){
        if(node == NULL){
            return NULL;
        }

        if(node->data > key){
            node->left = deleteNodeHelper(node->left, key);
        }
        else if(node->data < key){
            node->right = deleteNodeHelper(node->right, key);
        }
        else{
            if(node->left == NULL && node->right == NULL){
                return NULL;
            }
            else if(node->left != NULL && node->right == NULL){
                return node->left;
            }
            else if(node->right != NULL && node->left == NULL){
                return node->right;
            }
            else{
                Node* temp = findMinValueNode(node->right);
                node->data = temp->data;
                node->right = deleteNodeHelper(node->right, temp->data);
            }
        }

        return node;
    }

    // Function to find the node with the minimum value starting from a specific node(used in delete)
    Node *findMinValueNode(Node *node) {
        Node *current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    // Function to find the minimum node in the tree
    Node* findMinValue(){
        return findMinValueNode(root);
    }
};

int main() {
    BST bst;
    bst.insertIterative(50);
    bst.insertIterative(30);
    bst.insertIterative(20);
    bst.insertIterative(40);
    bst.insertIterative(70);
    bst.insertIterative(60);
    bst.insertIterative(80);

    cout << "Inorder traversal of the BST:" << endl;
    bst.inorder();

    cout << "Preorder traversal of the BST:" << endl;
    bst.preorder();

    cout << "Postorder traversal of the BST:" << endl;
    bst.postorder();

    int key = 40;
    if (bst.searchIterative(key)) {
        cout << "Node with value " << key << " found in the BST." << endl;
    } else {
        cout << "Node with value " << key << " not found in the BST." << endl;
    }

    bst.deleteNode(20);
    cout << "Inorder traversal after deleting 20:" << endl;
    bst.inorder();

    bst.deleteNode(30);
    cout << "Inorder traversal after deleting 30:" << endl;
    bst.inorder();

    bst.deleteNode(50);
    cout << "Inorder traversal after deleting 50:" << endl;
    bst.inorder();

    return 0;
}