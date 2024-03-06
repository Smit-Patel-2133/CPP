#include <iostream>
#include <string>
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
        cout << n->value<<" , ";
        n = n->Next;
    }
    cout<<endl;
}
Node reverse(Node *head)
{
    if (head == NULL || head->Next == NULL)
    {
        return *head;
    }
    Node p = reverse(head->Next);
    head->Next->Next = head;
    head->Next = NULL;
    return p;
}
int main()
{


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
    Forth->Next = NULL;
    PrintList(First);
    reverse(First);
    PrintList(Forth);

    return 0;
}
