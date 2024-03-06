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
void insertAtFront(Node **head, int newValue)
{
    // step1 Creating node
    Node *newNode = new Node(); // creating newNode object to access the property of the Node class
    newNode->value = newValue;
    // step 2 put in front of the Current Head Node
    newNode->Next = *head;
    // step 3 move head of the list to point to the newNode
    *head = newNode;
}
int main()
{
    Node *head = new Node();
    Node *Second = new Node();
    Node *Last = new Node();
    // cout<<head<<endl;
    // cout << Second << endl;
    // cout << Last << endl;
    head->value = 20;
    Second->value = 30;
    Last->value = 40;
    head->Next = Second;
    Second->Next = Last;
    Last->Next = NULL;
    cout << "Befor Inserting node" << endl;
    PrintList(head);
    cout << "After Inserting node" << endl;
    insertAtFront(&head, 10);
    PrintList(head);
    insertAtFront(&head, 0);
    PrintList(head);

    return 0;
}