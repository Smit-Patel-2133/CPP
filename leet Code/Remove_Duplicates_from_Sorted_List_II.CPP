#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode dummy(0); // Dummy node to handle edge cases
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                // Skip all nodes that have the same value as current
                while (current->next != nullptr && current->val == current->next->val) {
                    ListNode* temp = current->next;
                    current->next = current->next->next;
                    delete temp; // Free the memory of the duplicate node
                }
                ListNode* temp = current;
                current = current->next;
                delete temp; // Free the memory of the duplicate node
                prev->next = current;
            } else {
                prev = current;
                current = current->next;
            }
        }

        return dummy.next;
    }
};

// Function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Example 1
    int arr1[] = {1, 2, 3, 3, 4, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    ListNode* head1 = createList(arr1, size1);
    std::cout << "Input: ";
    printList(head1);
    ListNode* result1 = solution.deleteDuplicates(head1);
    std::cout << "Output: ";
    printList(result1);

    // Example 2
    int arr2[] = {1, 1, 1, 2, 3};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    ListNode* head2 = createList(arr2, size2);
    std::cout << "Input: ";
    printList(head2);
    ListNode* result2 = solution.deleteDuplicates(head2);
    std::cout << "Output: ";
    printList(result2);

    return 0;
}
