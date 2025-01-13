#include <iostream>
using namespace std;

class Node {
public:
    int data;

    Node(int d)
    {
        data = d;
    }
};

class HashTable {
private:
    Node *table[10];
    int size;
    int elements;

public:
    HashTable()
    {
        elements = 0;

        int size = 10;

        // Initialize all table slots to NULL
        for (int i = 0; i < size; i++)
        {
            table[i] = NULL;
        }
    }

    int hashFunc(int key)
    {
        return key % size; // Ensure the value fits within the table size
    }

    int hashFunc2(int key)
    {
        return 1 + (key % (size - 1)); // Return a number to step with, must not be zero
    }

    // Double Hashing: Resolves collisions by using a secondary hash function to calculate the step size (rather than just a fixed increment), making it less prone to clustering.
    void Double_Hashing_Insert(int val)
    {
        if (elements >= size)
        {
            cout << "Table is full" << endl;
            return;
        }

        Node *newNode = new Node(val);

        int hashkey = hashFunc(newNode->data);
        int stepSize = hashFunc2(newNode->data);

        int step = 0;

        // Use double hashing to handle collisions
        while (table[hashkey] != NULL)
        {
            cout << "! Collision at " << hashkey << " | Node: " << newNode->data << endl;
            step++;
            hashkey = hashkey + stepSize; // Double hashing for collision resolution
            hashkey = hashkey % size;
        }

        cout << "Inserting " << newNode->data << " at " << hashkey << " | Steps: " << step << endl;
        table[hashkey] = newNode;

        elements++;
    }

    // Linear Probing: Resolves collisions by incrementing the hash value by a fixed step size (1) until an empty slot is found.
    void Linear_Probing_Insert(int val)
    {
        if (elements >= size)
        {
            cout << "Table is full" << endl;
            return;
        }

        Node *newNode = new Node(val);

        int hashkey = hashFunc(newNode->data);

        int step = 0;

        // Use linear probing to handle collisions
        while (table[hashkey] != NULL)
        {
            cout << "! Collision at " << hashkey << " | Node: " << newNode->data << endl;
            step++;
            hashkey = hashkey + step; // Increment hashkey and wrap around if needed
            hashkey = hashkey % size;
        }

        cout << "Inserting " << newNode->data << " at " << hashkey << " | Steps: " << step << endl;
        table[hashkey] = newNode;

        elements++;
    }

    // Quadratic Probing: Resolves collisions by incrementing the hash value by the square of the step (step^2).
    void Quadratic_Probing_Insert(int val)
    {
        if (elements >= size)
        {
            cout << "Table is full" << endl;
            return;
        }

        Node *newNode = new Node(val);

        int hashkey = hashFunc(newNode->data);

        int step = 0;

        // Use quadratic probing to handle collisions
        while (table[hashkey] != NULL)
        {
            cout << "! Collision at " << hashkey << " | Node: " << newNode->data << endl;
            step++;
            hashkey = hashkey + (step * step); // Quadratic probing for collision resolution
            hashkey = hashkey % size;
        }

        cout << "Inserting " << newNode->data << " at " << hashkey << " | Steps: " << step << endl;
        table[hashkey] = newNode;

        elements++;
    }

    void display()
    {
        cout << "\nTable: ";
        for (int i = 0; i < size; i++)
        {
            if (table[i] != NULL)
            {
                cout << table[i]->data << " ";
            }
            else
            {
                cout << " - ";
            }
        }
        cout << endl;
    }
};

int main() {
    HashTable ht;

    ht.Linear_Probing_Insert(10);
    ht.Linear_Probing_Insert(20);
    ht.Linear_Probing_Insert(30);
    ht.Linear_Probing_Insert(40);
    ht.Linear_Probing_Insert(50);

    ht.display();

    cout << "\nNow using Quadratic Probing:" << endl;

    HashTable ht2;

    ht2.Quadratic_Probing_Insert(10);
    ht2.Quadratic_Probing_Insert(20);
    ht2.Quadratic_Probing_Insert(30);
    ht2.Quadratic_Probing_Insert(40);
    ht2.Quadratic_Probing_Insert(50);

    ht2.display();

    return 0;
}