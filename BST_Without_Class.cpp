#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* lchild;
        Node* rchild;

        Node(int val){
            data = val;
            lchild = NULL;
            rchild = NULL;
        }
};

Node* insertIterative(Node* root, int val){
    Node* newNode = new Node(val);

    if(root == NULL){
        return newNode;
    }

    Node* temp = root;
    Node* parent = temp; //Parent Is One Node Above Temp, So When Temp Reaches Null It Points To The Up Node

    while(temp != NULL){
        parent = temp;

        if(val < temp->data){
            temp = temp->lchild;
        }   
        else if(val > temp->data){
            temp = temp->rchild;
        }
        else{
            return root; //Value Already Exists In The Tree
        }
    }

    if(val < parent->data){
        parent->lchild = newNode;
    }
    else{
        parent->rchild = newNode;
    }

    return root;
}

Node* insertRecursive(Node* root, int val){
    //Recursive Case
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->lchild = insertRecursive(root->lchild, val);
    }
    else if(val > root->data){
        root->rchild = insertRecursive(root->rchild, val);
    }

    return root;
}

Node* seachIterative(Node* root, int val){
    if(root == NULL){
        return NULL;
    }

    Node* temp = root;

    while(temp != NULL){
        if(val == temp->data){
            return temp;
        }
        else if(val < temp->data){
            temp = temp->lchild;
        }
        else{
            temp = temp->rchild;
        }
    }

    return NULL;
}

Node* searchRecursive(Node* root, int val){
    //Recursive Case
    if(root == NULL){
        return NULL;
    }

    if(val == root->data){
        return root;
    }
    else if(val < root->data){
        return searchRecursive(root->lchild, val);
    }
    else{
        return searchRecursive(root->rchild, val);
    }
}

Node* findMin(Node* root){
    Node* temp = root;
    while(temp->lchild != NULL){
        temp = temp->lchild;
    }
    return temp;
}

Node* deleteNode(Node* root, int val){
    //Reaching To Node To Be Deleted
    if(val < root->data){
        root->lchild = deleteNode(root->lchild, val);
    }
    else if(val > root->data){
        root->rchild = deleteNode(root->rchild, val);
    }
    else{
        //Deletion Logic Goes Here

        //Case 1 - No Child:
        if(root->lchild == NULL && root->rchild == NULL){
            delete root;
            return NULL;
        }

        //Case 2 - Only 1 Child:
        if(root->lchild != NULL && root->rchild == NULL){
            Node* temp = root->lchild;
            delete root;
            return temp;
        }
        else if(root->rchild != NULL && root->lchild == NULL){
            Node* temp = root->rchild;
            delete root;
            return temp;
        }

        //CASE 3 - Both Childs:
        if(root->lchild != NULL && root->rchild != NULL){
            Node* temp = findMin(root->rchild);
            temp->data = root->data;
            root->rchild = deleteNode(root->rchild, root->data);
        }
    }

    return root;
}

int main(){

}