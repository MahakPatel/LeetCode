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
    bool isPalindrome(ListNode* head) {

        // ++++++++++++ Brute Force ++++++++++ TC O(2N).    SC O(N)
        // Create an empty stack
        // to store values
        // stack<int> st;

        // // Initialize a temporary pointer
        // // to the head of the linked list
        // ListNode* temp = head;

        // // Traverse the linked list and
        // // push values onto the stack
        // while (temp != NULL) {

        //     // Push the data from the
        //     // current node onto the stack
        //     st.push(temp->val);

        //     // Move to the next node
        //     temp = temp->next;
        // }

        // // Reset the temporary pointer back
        // // to the head of the linked list
        // temp = head;

        // // Compare values by popping from the stack
        // // and checking against linked list nodes
        // while (temp != NULL) {
        //     if (temp->val != st.top()) {

        //         // If values don't match,
        //         // it's not a palindrome
        //         return false;
        //     }

        //     // Pop the value from the stack
        //     st.pop();

        //     // Move to the next node
        //     // in the linked list
        //     temp = temp->next;
        // }

        // // If all values match,
        // // it's a palindrome
        // return true;

        // ++++++++++++++++++ Optimal Approch ++++++++++
            ListNode* temp = head;

            if (temp == NULL || temp->next == NULL) { // if zero or one node
                return true;
            }

            ListNode* fast = head;
            ListNode* slow = head;

            while (fast->next != NULL && fast->next->next != NULL) { // movefast till last node (for odd length of LL) or second last node(if even length of LL)
                fast = fast->next->next;
                slow = slow->next; // will reach at middle of LL
            }

            ListNode* newHead = reverse(slow->next); // reverse second portion of LL (slow at middle Node of LL)

            ListNode* first = head; // first portion of LL
            ListNode* second = newHead; // first node of second portion of LL

            while (second != NULL) {
                if (first->val != second->val) { // if both value not same
                    reverse(newHead); // we reverse the given LL so we moving back to given data 
                    return false; // return false
                }

                first = first->next;
                second = second->next;
            }

            reverse(newHead); // we reverse the given LL so we moving back to given data

            return true; // if all the comparision is successfull return true;
        }

        ListNode* reverse(ListNode* head) {
            if (head == NULL || head->next == NULL)
                return head;

            ListNode* newHead = reverse(head->next);
            ListNode* front = head->next;
            front->next = head;
            head->next = NULL;

            return newHead;
    }
};