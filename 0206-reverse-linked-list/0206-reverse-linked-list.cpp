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
        ListNode* temp = head; // current node
        ListNode* back = NULL; // previous node of current node

        while(temp != NULL){
           ListNode* front = temp->next; // next node of current node
            temp -> next = back;
            back = temp;
            temp = front;
        }

        return back;
    }
};