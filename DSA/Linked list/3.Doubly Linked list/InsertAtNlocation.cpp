
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
        cout<< head->value << endl;
        head = head->Next;
    }
}
void PrintBackward(Node *Tail)
{
    cout << "printing  in Backward" << endl;
    while (Tail != nullptr)
    {
        cout  << Tail->value<< endl;
        Tail = Tail->prev;
    }
}
void insertAtFront(Node *head, int newValue, int value)
{
    Node *temp = new Node();
    Node *tempPTR = new Node();
    temp->value = newValue;
    temp->prev = nullptr;
    temp->Next = nullptr;
    while (head->value != value)
    {
        tempPTR = head;
        head = head->Next;
    }
    temp->Next = head;
    temp->prev = tempPTR;
    head->prev = temp;
    tempPTR->Next = temp;
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
    // cout << "befor inserting node" << endl;
    // PrintForward(head);
    // PrintBackward(tail);
    // cout << "after inserting node" << endl;
    PrintForward(head);
    cout<<"afteri inserting node:"<<endl;
    insertAtFront(head, 11, 30);
    PrintForward(head);
    PrintBackward(tail);
    return 0;
}
