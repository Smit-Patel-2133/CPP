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
void insertAtEnd(Node **head, int newValue)
{
    // step1 Creating node
    Node *newNode = new Node(); // creating newNode object to access the property of the Node class
    newNode->value = newValue;
    newNode->Next = NULL;
    // step 2 find if the list is empty
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    // step 3 find last  node
    Node *Last = *head;
    while (Last->Next != NULL)
    {
        Last = Last->Next;
    }

    // step 4 insert newNode after last node
    Last->Next = newNode;
}
int main()
{
    Node *head = new Node();
    Node *Second = new Node();
    Node *Third = new Node();
    // cout<<head<<endl;
    // cout << Second << endl;
    // cout << Last << endl;
    head->value = 20;
    Second->value = 30;
    Third->value = 40;
    head->Next = Second;
    Second->Next = Third;
    Third->Next = NULL;
    cout << "Befor Inserting node" << endl;
    PrintList(head);
    cout << "After Inserting node" << endl;

    insertAtEnd(&head, 50);

    PrintList(head);

    return 0;
}
