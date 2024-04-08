#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *l3 = new ListNode();
        ListNode *head = l3;
        int carry = 0;
        while (l1 && l2)
        {
            int value = l1->val + l2->val + carry;
            carry = value / 10;
            l3->next = new ListNode(value % 10);
            l1 = l1->next;
            l3 = l3->next;
            l2 = l2->next;
        }
        while (l1)
        {
            int value = l1->val + carry;
            carry = value / 10;
            l3->next = new ListNode(value % 10);
            l1 = l1->next;
            l3 = l3->next;
        }
        while (l2)
        {
            int value = l2->val + carry;
            carry = value / 10;
            l3->next = new ListNode(value % 10);

            l3 = l3->next;
            l2 = l2->next;
        }
        if (carry)
        {
            l3->next = new ListNode(carry);
        }
        return head->next;
    }
};

// Utility function to print a linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Example usage
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution solution;
    ListNode *result = solution.addTwoNumbers(l1, l2);

    std::cout << "Sum: ";
    printList(result);

    // Free memory
    while (result)
    {
        ListNode *temp = result;
        result = result->next;
        delete temp;
    }
    delete l1;
    delete l2;

    return 0;
}
