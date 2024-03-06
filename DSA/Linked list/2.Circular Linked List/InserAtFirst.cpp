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
    Node *temp = n;
    do
    {
        cout << n->value << "->" << n->Next << endl;
        n = n->Next;
    } while (n != temp);
}
void insertAtFront(Node *head, int newValue)
{
    Node *temp = new Node();
    temp->value = newValue;
    temp->Next = NULL;
    temp->Next = head;
    Node *tempPTR = head;
    head = head->Next;
    while (head->Next != tempPTR)
    {
        /* code */
        head = head->Next;
    }
    head->Next = temp;
}
int main()
{
    Node *head;
    Node *First = new Node();
    Node *Second = new Node();
    Node *Third = new Node();
    Node *Forth = new Node();
    First->value = 10;
    Second->value = 20;
    Third->value = 30;
    Forth->value = 40;
    First->Next = Second;
    Second->Next = Third;
    Third->Next = Forth;
    Forth->Next = First;
    head = First;
    cout << "Befor Inserting node" << endl;
    PrintList(head);
    cout << "After Inserting node" << endl;
    insertAtFront(head, 11);
    Node *tempPTR = head;
    head = head->Next;
    while (head->Next != tempPTR)
    {
        head = head->Next;
    }
    tempPTR = head;
    PrintList(head);
    return 0;
}
