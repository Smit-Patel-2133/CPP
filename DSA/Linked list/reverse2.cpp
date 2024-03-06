#include <bits/stdc++.h>

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
LinkedListNode<T> *reverseLinkedList(LinkedListNode<T> *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    LinkedListNode<T> *pos = nullptr;
    LinkedListNode<T> *curr = head;
    LinkedListNode<T> *pre = nullptr;

    while (curr != nullptr)
    {
        pre = curr->next;
        curr->next = pos;
        pos = curr;
        curr = pre;
    }

    return pos;
}

int main()
{
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    LinkedListNode<int> *head = new LinkedListNode<int>(1);
    head->next = new LinkedListNode<int>(2);
    head->next->next = new LinkedListNode<int>(3);
    head->next->next->next = new LinkedListNode<int>(4);
    head->next->next->next->next = new LinkedListNode<int>(5);

    std::cout << "Original linked list: ";
    LinkedListNode<int> *current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Reverse the linked list
    head = reverseLinkedList(head);

    std::cout << "Reversed linked list: ";
    current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Clean up the allocated memory
    while (head != nullptr)
    {
        LinkedListNode<int> *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
