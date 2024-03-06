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
void DeleteBefore(Node **head, int befor)
{

    if (*head == NULL)
    {
        *head = NULL;
        return;
    }
    // step 3 find  node
    Node *Last = *head;
    Node *post;
    while (Last->Next->value != befor)
    {
        post = Last;
        Last = Last->Next;
       
    }
    
    //one way to delete node =>{
    Last = post;
    Last->Next = Last->Next->Next;//    }
    // second way to delete node =>     post->Next = Last->Next;

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
    cout << "After Deleting node" << endl;
    DeleteBefore(&head, Third->value);
    PrintList(head);

    return 0;
}
