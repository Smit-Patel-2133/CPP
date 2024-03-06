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

void DeleteAtFront(Node *&head)
{
    if (head != NULL)
    {
        Node *temp = head;
        head = head->Next;
        delete temp;
    }
}

int main()
{
    Node *head = new Node();
    Node *Second = new Node();
    Node *Third = new Node();
    Node *Forth = new Node();
    Node *Last = new Node();

    head->value = 20;
    Second->value = 30;
    Third->value = 35;
    Forth->value = 37;
    Last->value = 40;

    head->Next = Second;
    Second->Next = Third;
    Third->Next = Forth;
    Forth->Next = Last;
    Last->Next = NULL;

    cout << "Before Inserting node" << endl;
    PrintList(head);

    cout << "After deleting node" << endl;
    DeleteAtFront(head);
    PrintList(head);

    return 0;
}
