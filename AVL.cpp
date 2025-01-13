#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    int height; // Height of the node (used for balancing the tree)
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        height = 1; // Initial height is set to 1, as it's a leaf node
        left = NULL;
        right = NULL;
    }
};

// Function to get the height of a node:
int getheight(Node *root)
{
    // If the node is NULL, its height is considered 0.
    if (root == NULL)
    {
        return 0;
    }
    // Otherwise, return the height of the node.
    return root->height;
}

// Function to calculate the balance factor of a node:
int getbalance(Node *root)
{
    // Balance factor is the difference in height between the left and right subtrees.
    // If it is >1 or <-1, the tree is unbalanced.
    return getheight(root->left) - getheight(root->right);
}

// Right Rotation function (used to balance Left-Left case or when the left subtree is too tall)
Node *rightRotate(Node *root)
{
    // The child node will be the left child of the root
    Node *child = root->left;

    // Temporary node to store the right child of the left child
    Node *temp = child->right;

    // Perform the rotation:
    // 1. The left child (child) becomes the new root.
    // 2. The old root (root) becomes the right child of the new root.
    // 3. The right child of the new root (child->right) is now the left child of the old root (root->left).
    child->right = root;
    root->left = temp;

    // After the rotation, update the height of the original root:
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // Update the height of the new root (child):
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    // Return the new root of the subtree (child)
    return child;
}

// Left Rotation function (used to balance Right-Right case or when the right subtree is too tall)
Node *leftRotate(Node *root)
{
    // The child node will be the right child of the root
    Node *child = root->right;

    // Temporary node to store the left child of the right child
    Node *temp = child->left;

    // Perform the rotation:
    // 1. The right child (child) becomes the new root.
    // 2. The old root (root) becomes the left child of the new root.
    // 3. The left child of the new root (child->left) is now the right child of the old root (root->right).
    child->left = root;
    root->right = temp;

    // After the rotation, update the height of the original root:
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // Update the height of the new root (child):
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    // Return the new root of the subtree (child)
    return child;
}

// Function to insert a key into the AVL tree and keep it balanced:
Node *insertAVL(Node *root, int key)
{
    // If the root is NULL, it means the tree (or subtree) is empty,
    // so we create a new node with the given key and return it.
    // This new node will become the root of this subtree.
    if (root == NULL)
    {
        return new Node(key);
    }

    // If the key is smaller than the current node's data,
    // we insert the key into the left subtree (root->left).
    if (key < root->data)
    {
        root->left = insertAVL(root->left, key);
    }
    // If the key is larger than the current node's data,
    // we insert the key into the right subtree (root->right).
    else if (key > root->data)
    {
        root->right = insertAVL(root->right, key);
    }
    // If the key is equal to the current node's data,
    // it means the key is already present, and we return the current node (i.e., no insertion).
    else
    {
        return root;
    }

    // After inserting the key, update the height of the current node:
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // FIND THE BALANCE OF THE TREE:
    // After updating the height, you would normally check the balance factor to see if the tree is unbalanced.
    // If the balance factor is greater than 1 or less than -1, rotations would be needed.

    int balance = getbalance(root); // Get the balance factor of the current node

    // 4 Rotation cases to balance the tree if necessary:

    // Case 1: Left-Left (LL) Rotation
    // If balance factor > 1 and the key is smaller than the left child’s data,
    // then it's a Left-Left (LL) case, and we need to perform a right rotation.
    if (balance > 1 && key < root->left->data)
    {
        return rightRotate(root);
    }

    // Case 2: Left-Right (LR) Rotation
    // If balance factor > 1 and the key is greater than the left child’s data,
    // then it's a Left-Right (LR) case, and we first perform a left rotation on the left subtree,
    // followed by a right rotation on the current node.
    if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left); // Left rotate on the left subtree
        return rightRotate(root);            // Right rotate on the current node
    }

    // Case 3: Right-Right (RR) Rotation
    // If balance factor < -1 and the key is greater than the right child’s data,
    // then it's a Right-Right (RR) case, and we need to perform a left rotation.
    if (balance < -1 && key > root->right->data)
    {
        return leftRotate(root);
    }

    // Case 4: Right-Left (RL) Rotation
    // If balance factor < -1 and the key is smaller than the right child’s data,
    // then it's a Right-Left (RL) case, and we first perform a right rotation on the right subtree,
    // followed by a left rotation on the current node.
    if (balance < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right); // Right rotate on the right subtree
        return leftRotate(root);                // Left rotate on the current node
    }

    return root;
}

Node *deleteNodeHelper(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    // Traverse to the node to be deleted
    if (key < root->data)
    {
        root->left = deleteNodeHelper(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNodeHelper(root->right, key);
    }
    else
    {
        // Node found, handle the cases
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        if (root->left != NULL && root->right == NULL)
        {
            return root->left;
        }
        if (root->right != NULL && root->left == NULL)
        {
            return root->right;
        }
        if (root->right != NULL && root->left != NULL)
        {
            Node *temp = findMinValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNodeHelper(root->right, temp->data);
        }
    }

    // Update height of the node
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // Balance the node
    int balance = getbalance(root);

    // Left-Left case
    if (balance > 1 && getbalance(root->left) >= 0)
    {
        return rightRotate(root);
    }

    // Left-Right case
    if (balance > 1 && getbalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right-Right case
    if (balance < -1 && getbalance(root->right) <= 0)
    {
        return leftRotate(root);
    }

    // Right-Left case
    if (balance < -1 && getbalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* findMinValueNode(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

// Traversing The AVL:
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << ' -> ';
        inorder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    root = insertAVL(root, 50);
    root = insertAVL(root, 60);
    root = insertAVL(root, 70);
    root = insertAVL(root, 80);
    cout << "Inorder Traversal" << endl;
    inorder(root);
}