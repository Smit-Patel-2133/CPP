// #include <iostream>
// using namespace std;
// //  Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
// };

// class Solution
// {
// public:
//     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
//     {
//         ListNode *head = l1;

//         while (*l1->next != NULL && l2->next != NULL)
//         {
//             l1->val = l1->val + l2->val;

//             l1 = l1->next;
//             l2 = l2->next;
//         }

//         return l1;
//     }
// };
// int main()
// {
//     ListNode *head1 = new ListNode();
//     ListNode *Second1 = new ListNode();
//     ListNode *Third1 = new ListNode();
//     ListNode *Forth1 = new ListNode();
//     head1->val = 20;
//     Second1->val = 30;
//     Third1->val = 40;
//     Forth1->val = 50;
//     head1->next = Second1;
//     Second1->next = Third1;
//     Third1->next = Forth1;
//     Forth1->next = NULL;

//     // second Linked list
//     ListNode *head2 = new ListNode();
//     ListNode *Second2 = new ListNode();
//     ListNode *Third2 = new ListNode();
//     ListNode *Forth2 = new ListNode();
//     head2->val = 1;
//     Second2->val = 2;
//     Third2->val = 3;
//     Forth2->val = 4;
//     head2->next = Second2;
//     Second2->next = Third2;
//     Third2->next = Forth2;
//     Forth2->next = NULL;
//     Solution s1;
//     ListNode *fi;
//     fi=s1.addTwoNumbers(head1, head2);
//     while (fi->next!=NULL)
//     {
//         /* code */
//         cout<<fi->val<<endl;
//         fi=fi->next;
//     }
    
// }