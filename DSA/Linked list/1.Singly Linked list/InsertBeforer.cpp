#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *Next;
};

void PrintList(Node *n)

{
    while (n != NULL)
    {
        cout << n->value << "->" << n->Next << endl;
        n = n->Next;
    }
}
void insertBefore(Node **head, int before, int newValue)
{
    // step1 Creating node
    Node *newNode = new Node(); // creating newNode object to access the property of the Node class
    newNode->value = newValue;

    // step 2 find if the list is empty
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    // step 3 find node
    Node *last = *head;
    Node *post = NULL;

    while (last != NULL && last->value != before)
    {
        post = last;
        last = last->Next;
    }

    // Check if the 'before' value is not found in the list
    if (last == NULL)
    {
        cout << "Node with value " << before << " not found in the list." << endl;
        delete newNode; // Clean up allocated memory for newNode
        return;
    }

    // Insert the newNode before the found node
    newNode->Next = last;

    // Check if the node to be inserted is at the beginning of the list
    if (post == NULL)
    {
        *head = newNode;
    }
    else
    {
        post->Next = newNode;
    }
}

int main()
{
    Node *head = new Node();
    Node *Second = new Node();
    Node *Third = new Node();
    Node *Forth = new Node();

    head->value = 10;
    Second->value = 20;
    Third->value = 30;
    Forth->value = 40;
    head->Next = Second;
    Second->Next = Third;
    Third->Next = Forth;
    Forth->Next = NULL;
    cout << "Befor Inserting node" << endl;
    PrintList(head);
    cout << "After Inserting node" << endl;

    insertBefore(&head, 30, 25);

    PrintList(head);

    return 0;
}
