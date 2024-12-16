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
    void insert(int val) {
        root = insertRecursive(root, val);
    }

    // Recursive function to insert a value into the BST
    Node *insertRecursive(Node *node, int val) {
        // If the tree is empty, create a new node and return it
        if (node == NULL) {
            return new Node(val);
        }

        // Otherwise, recur down the tree
        if (val < node->data) {
            node->left = insertRecursive(node->left, val);
        } else if (val > node->data) {
            node->right = insertRecursive(node->right, val);
        }

        // Return the (unchanged) node pointer
        return node;
    }

    // Function to search for a value in the BST
    bool search(int val) {
        return searchRecursive(root, val);
    }

    // Recursive function to search for a value in the BST
    bool searchRecursive(Node *node, int val) {
        // Base case: root is null
        if (node == NULL) {
            return false;
        }

        // Key is greater than root's key
        if (val < node->data) {
            return searchRecursive(node->left, val);
        } else if (val > node->data) {
            // Key is smaller than root's key
            return searchRecursive(node->right, val);
        } else {
            // Key is found
            return true;
        }
    }

    // Function for inorder traversal of the BST
    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    // Recursive function for inorder traversal of the BST
    void inorderRec(Node *node) {
        if (node != NULL) {
            inorderRec(node->left);
            cout << node->data << " -> ";
            inorderRec(node->right);
        }
    }

    // Function for preorder traversal of the BST
    void preorder() {
        preorderRec(root);
        cout << endl;
    }

    // Recursive function for preorder traversal of the BST
    void preorderRec(Node *node) {
        if (node != NULL) {
            cout << node->data << " -> ";
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }

    // Function for postorder traversal of the BST
    void postorder() {
        postorderRec(root);
        cout << endl;
    }

    // Recursive function for postorder traversal of the BST
    void postorderRec(Node *node) {
        if (node != NULL) {
            postorderRec(node->left);
            postorderRec(node->right);
            cout << node->data << " -> ";
        }
    }

    // Function to delete a node from the BST
    void deleteNode(int key) {
        root = deleteRec(root, key);
    }

    // Recursive function to delete a node from the BST
    Node *deleteRec(Node *node, int key) {
        // Base case: If the tree is empty
        if (node == NULL) {
            return node;
        }

        // Otherwise, recur down the tree
        if (key < node->data) {
            node->left = deleteRec(node->left, key);
        } else if (key > node->data) {
            node->right = deleteRec(node->right, key);
        } else {
            // Node with only one child or no child
            if (node->left == NULL) {
                Node *temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node *temp = minValueNode(node->right);

            // Copy the inorder successor's content to this node
            node->data = temp->data;

            // Delete the inorder successor
            node->right = deleteRec(node->right, temp->data);
        }
        return node;
    }

    // Function to find the node with the minimum value starting from a specific node(used in delete)
    Node *minValueNode(Node *node) {
        Node *current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    // Function to find the minimum node in the tree
    Node* minValue(){
        Node* current = root;
        while(current->left != NULL){
            current = current->left;
        }
        return current;
    }
};

int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal of the BST:" << endl;
    bst.inorder();

    cout << "Preorder traversal of the BST:" << endl;
    bst.preorder();

    cout << "Postorder traversal of the BST:" << endl;
    bst.postorder();

    int key = 40;
    if (bst.search(key)) {
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