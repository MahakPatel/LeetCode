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
    ListNode* reverseList(ListNode* head) {

        //+++++++++++++++++ Brute Force Approch +++++++++++++++

        //     // Create a temporary pointer
        // // to traverse the linked list
        // ListNode* temp = head;

        // // Create a stack to temporarily
        // // store the data values
        // stack<int> st;

        // // Step 1: Push the values of the
        // // linked list onto the stack
        // while (temp != nullptr) {
        //     // Push the current node's
        //     // data onto the stack
        //     st.push(temp->val);

        //     // Move to the next node
        //     // in the linked list
        //     temp = temp->next;
        // }

        // // Reset the temporary pointer to
        // // the head of the linked list
        // temp = head;

        // // Step 2: Pop values from the stack
        // // and update the linked list
        // while (temp != nullptr) {
        //     // Set the current node's data to
        //     // the value at the top of the stack
        //     temp->val = st.top();

        //     // Pop the top element from the stack
        //     st.pop();

        //     // Move to the next node
        //     // in the linked list
        //     temp = temp->next;
        // }

        // // Return the new head of
        // // the reversed linked list
        // return head;

        //
        // ++++++++ Optimal solution +++++++++++++
        // ListNode* temp = head; // current node
        // ListNode* back = NULL; // previous node of current node

        // while (temp != NULL) {
        //     ListNode* front = temp->next; // next node of current node
        //     temp->next = back;
        //     back = temp;
        //     temp = front;
        // }

        // return back;

           // +++++++++++++ Recursive Approch ++++++++++++

    if (head == NULL || head -> next == NULL) return head;

    ListNode* newHead = reverseList(head -> next);
    ListNode* front = head -> next;
    front -> next = head;
    head -> next = NULL;

    return newHead;


    }
};