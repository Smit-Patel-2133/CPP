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
void DeleteAtLast(Node *head)
{
    Node *Last = head;
    while (Last->Next->Next != NULL)
    {
        Last = Last->Next;
    }

    Last->Next = NULL;
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
    cout << "After deleteing node" << endl;
    DeleteAtLast(head);
    PrintList(head);

    return 0;
}
