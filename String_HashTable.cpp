#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string data;

    Node(string d)
    {
        data = d;
    }
};

class HashTable
{
private:
    Node *table[10];
    int size = 10;
    int elements;

public:
    HashTable()
    {
        elements = 0;

        // Initialize all table slots to NULL
        for (int i = 0; i < size; i++)
        {
            table[i] = NULL;
        }
    }

    int hashFunc(string key)
    {
        int hashValue = 0;

        // Calculate hash value based on ASCII values of characters in the string
        for (int i = 0; i < key.length(); i++)
        {
            hashValue = hashValue + key[i]; // Add ASCII value of each character
        }

        return hashValue % size; // Ensure the value fits within the table size
    }

    int hashFunc2(string key)
    {
        int hashValue = 0;

        // Second hash function, typically a prime number not equal to the table size
        for (int i = 0; i < key.length(); i++)
        {
            hashValue = hashValue + key[i];
        }

        return 1 + (hashValue % (size - 1)); // Return a number to step with, must not be zero
    }

    // Double Hashing: Resolves collisions by using a secondary hash function to calculate the step size (rather than just a fixed increment), making it less prone to clustering.
    void Double_Hashing_Insert(string val)
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
    void Linear_Probing_Insert(string val)
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
    void Quadratic_Probing_Insert(string val)
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

int main()
{
    HashTable ht;

    ht.Linear_Probing_Insert("apple");
    ht.Linear_Probing_Insert("banana");
    ht.Linear_Probing_Insert("grape");
    ht.Linear_Probing_Insert("kiwi");
    ht.Linear_Probing_Insert("orange");

    ht.display();

    cout << "\nNow using Quadratic Probing:" << endl;

    HashTable ht2;

    ht2.Quadratic_Probing_Insert("apple");
    ht2.Quadratic_Probing_Insert("banana");
    ht2.Quadratic_Probing_Insert("grape");
    ht2.Quadratic_Probing_Insert("kiwi");
    ht2.Quadratic_Probing_Insert("orange");

    ht2.display();

    return 0;
}