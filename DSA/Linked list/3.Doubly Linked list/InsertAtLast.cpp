// there is some problem in the PrintBackward Function
#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *Next;
    Node *prev;
};

void PrintForward(Node *head)
{
    cout << "printing  in froward" << endl;
    while (head != nullptr)
    {
        cout << head->value << endl;
        head = head->Next;
    }
}
void PrintBackward(Node *Tail)
{
    cout << "printing  in Backward" << endl;
    while (Tail != nullptr)
    {
        cout<< Tail->value  << endl;
        Tail = Tail->prev;
    }
}
void insertAtLast(Node *&Tail, int newValue)
{
    Node *temp = new Node();
    temp->value = newValue;
    temp->prev = nullptr;
    temp->Next = nullptr;

    temp->prev = Tail;
    Tail->Next = temp;

    Tail = temp; // Update the reference to the tail outside the function
}

int main()
{
    Node *head;
    Node *tail;
    // creating first node
    Node *node = new Node();
    node->value = 1;
    node->Next = nullptr;
    node->prev = nullptr;
    head = node;
    tail = node;
    // creating 2 node
    node = new Node();
    node->value = 10;
    node->Next = nullptr;
    node->prev = tail;
    tail->Next = node;
    tail = node;
    // creating 3 node
    node = new Node();
    node->value = 20;
    node->Next = nullptr;
    node->prev = tail;
    tail->Next = node;
    tail = node;
    // creating 3 node
    node = new Node();
    node->value = 30;
    node->Next = nullptr;
    node->prev = tail;
    tail->Next = node;
    tail = node;
    // creating 4 node
    node = new Node();
    node->value = 40;
    node->Next = nullptr;
    node->prev = tail;
    tail->Next = node;
    tail = node;
    cout << "befor inserting node" << endl;
    PrintForward(head);
    PrintBackward(tail);
    cout << "after inserting node" << endl;
    insertAtLast(tail, 11);
    PrintForward(head);
    PrintBackward(tail);
    return 0;
}
