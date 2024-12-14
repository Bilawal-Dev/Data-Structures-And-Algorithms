#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int val)
    {
        value = val;
        next = NULL;
    }
};

class NodeList
{
private:
    Node *head;

public:
    NodeList()
    {
        head = NULL;
    }

    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        newNode->next = head;

        head = newNode;
    }

    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *current = head;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newNode;
    }

    void insertAtPosition(int val, int position)
    {

        if (position <= 0)
        {
            return;
        }

        if (position == 1)
        {
            insertAtHead(val);
            return;
        }

        Node *newNode = new Node(val);

        Node *current = head;
        int pos = 1;

        while (pos != position)
        {
            current = current->next;
            pos++;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    int searchInList(int target)
    {
        Node *current = head;

        int count = 1;

        while (current != NULL)
        {

            if (current->value == target)
            {
                cout << "\nThe Target " << target << " Is Found In List At Position : " << count << endl;
                return count;
            }

            current = current->next;
            count++;
        }

        cout << "\nThe Target Is Not Found In The List" << endl;
        return -1;
    }

    void deleteAtEnd()
    {
        Node *temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = NULL;
    }

    void iterativeReverseList()
    {
        Node *prevPtr = NULL;
        Node *currentPtr = head;
        Node *nextPtr = currentPtr->next;

        while (currentPtr != NULL)
        {
            currentPtr->next = prevPtr;

            prevPtr = currentPtr;
            currentPtr = nextPtr;
            if (nextPtr == NULL)
            {
                break;
            }
            nextPtr = nextPtr->next;
        }

        head = prevPtr; // Marks New Head Of The Linked List Which Is The Last Element
    }

    Node *recursiveReverseListHelper(Node *temp)
    {
        // Base case: If list is empty or only one node
        if (temp == NULL || temp->next == NULL)
        {
            return temp;
        }

        // Recurse for the rest of the list
        Node *newHead = recursiveReverseListHelper(temp->next);

        // Reverse the pointers
        temp->next->next = temp;
        temp->next = NULL;

        return newHead; // Return new head at the end of recursion
    }

    void recursiveReverseList()
    {
        head = recursiveReverseListHelper(head);
    }

    void displayList()
    {
        Node *current = head;

        while (current != NULL)
        {
            cout << current->value << " -> ";
            current = current->next;
        }

        cout << "NULL" << endl;
    }
};

int main()
{
    NodeList Numbers;

    // Numbers.displayList();

    // Numbers.insertAtPosition(10, 1);

    // Numbers.displayList();

    Numbers.insertAtHead(20);

    // Numbers.displayList();

    Numbers.insertAtTail(30);

    Numbers.displayList();

    // Numbers.searchInList(10);

    // Numbers.iterativeReverseList();

    Numbers.recursiveReverseList();

    Numbers.displayList();
}