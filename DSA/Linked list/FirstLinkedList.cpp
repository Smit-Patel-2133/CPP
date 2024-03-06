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
        /* code */
        cout << n->value << "->" << n->Next << endl;
        n = n->Next;
    }
}
int main()
{
    Node *head = new Node();
    Node *Second = new Node();
    Node *Last = new Node();
    // cout<<head<<endl;
    // cout << Second << endl;
    // cout << Last << endl;
    head->value = 21;
    Second->value = 30;
    Last->value = 40;
    head->Next = Second;
    Second->Next = Last;
    Last->Next = NULL;
    PrintList(head);

    return 0;
}
