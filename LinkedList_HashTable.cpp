#include <iostream>
using namespace std;

// Node class for the linked list
class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// Linked list class
class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    // Insert a node at the end of the list
    void insert(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Remove a node with the given data
    void remove(int data)
    {
        if (head == NULL)
            return;

        if (head->data == data)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL && temp->next->data != data)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
            return;

        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Search for a node with the given data
    bool search(int data)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == data){
                return true;
            }

            temp = temp->next;
        }
        return false;
    }

    // Display the linked list
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Hash table class with chaining
class HashTable
{
private:
    int size;  // Fixed size of the hash table
    LinkedList *table[10];  // Array of LinkedList pointers with fixed size

public:
    HashTable()
    {
        size = 10;
        
        for (int i = 0; i < size; i++)
        {
            table[i] = new LinkedList();  // Initialize each element of the table as a new LinkedList
        }
    }

    int hashFunc(int key)
    {
        return key % size;
    }

    // Insert a key into the hash table
    void insert(int key)
    {
        int hashValue = hashFunc(key);
        table[hashValue]->insert(key);  // Use -> to access the insert method
    }

    // Remove a key from the hash table
    void remove(int key)
    {
        int hashValue = hashFunc(key);
        table[hashValue]->remove(key);  // Use -> to access the remove method
    }

    // Search for a key in the hash table
    bool search(int key)
    {
        int hashValue = hashFunc(key);
        return table[hashValue]->search(key);  // Use -> to access the search method
    }

    // Display the hash table
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << ": ";
            table[i]->display();  // Use -> to access the display method
        }
    }
};

int main()
{
    HashTable ht;

    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.insert(40);
    ht.insert(50);
    ht.insert(15);
    ht.insert(25);

    cout << "Hash Table:" << endl;
    ht.display();

    cout << "\nSearching for 30: " << (ht.search(30) ? "Found" : "Not Found") << endl;
    cout << "Searching for 100: " << (ht.search(100) ? "Found" : "Not Found") << endl;

    ht.remove(30);
    cout << "\nAfter removing 30:" << endl;
    ht.display();

    return 0;
}