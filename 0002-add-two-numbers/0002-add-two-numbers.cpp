/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1; // temmp1 head
        ListNode* temp2 = l2; //temp2 head

        int carry = 0;

        ListNode* dummyNode = new ListNode(-1); // create dummy node 
        ListNode* currentNode = dummyNode; // place currentNode at dummyNode

        while (temp1 != NULL || temp2 != NULL) { // run till both is not NULL
            int sum = carry; // put carry int sum

            if (temp1)  // if temp1 is available or valid
                sum = sum + temp1->val; // sum the value of temp1 -> data
            if (temp2)// if temp2 is available or valid
                sum = sum + temp2->val;// sum the value of temp2 -> data

            ListNode* newNode = new ListNode(sum % 10); // create the newNode with denomiter

            carry = sum / 10; // and put the reminder into carry

            currentNode->next = newNode; // connect currentNode with newNode
            currentNode = currentNode->next; // move currentNode to next Node

            if (temp1) // if temp1 is valid then move by 1 node
                temp1 = temp1->next;
            if (temp2)// if temp2 is valid then move by 1 node
                temp2 = temp2->next;
        }

        if (carry) { // is carry is available then
            ListNode* newNode = new ListNode(carry); // create new node with that carry
            currentNode->next = newNode; // and connect currentNode with that carry newNode
        }

        return dummyNode->next; // dummyNode(-1) is previous node of head so to return head we need to return dummyNode -> next which is head
    }
};