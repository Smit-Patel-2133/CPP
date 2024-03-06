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
void insertAfter(Node *Previous, int newValue)
{
    // step1 find if the Position is NULL or not
    if (Previous == NULL)
    {
        cout << "Previous node can not be null";
        return;
    }
    // step2 Creating node
    Node *newNode = new Node(); // creating newNode object to access the property of the Node class
    newNode->value = newValue;
    // step 3 insert the node after the second position
    newNode->Next = Previous->Next;
    Previous->Next = newNode;
}

int main()
{
    Node *head = new Node();
    Node *Second = new Node();
    Node *Third = new Node();
    Node *Forth = new Node();
    // cout<<head<<endl;
    // cout << Second << endl;
    // cout << Last << endl;
    head->value = 20;
    Second->value = 30;
    Third->value = 40;
    Forth->value = 50;
    head->Next = Second;
    Second->Next = Third;
    Third->Next = Forth;
    Forth->Next = NULL;
    cout << "Befor Inserting node" << endl;
    PrintList(head);
    cout << "After Inserting node" << endl;

    insertAfter(Second, 500);

    PrintList(head);

    return 0;
}
