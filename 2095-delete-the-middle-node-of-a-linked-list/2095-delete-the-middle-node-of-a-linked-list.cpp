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
    ListNode* deleteMiddle(ListNode* head) {

        if(head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode* slow = head; // we need to move slow previous of middle mode so we will skip one interation of slow
        ListNode* fast = head; // move 2 node at time

        fast = fast->next->next; // just move fast and skip 1 interation of slow

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* deletedNode = slow->next; // save deleted node
        slow->next = slow->next->next; // connect previous node with next node of delete
        delete (deletedNode);

        return head;

        // +++++++++++++++ Brute Force +++++++ TC O(N + N/2) SC O(1)

        // int n = 0;
        // ListNode* temp = head;

        // while (temp != NULL) { // fing the length of LL
        //     n++;
        //     temp = temp->next;
        // }

        // temp = head;

        // int mid = n / 2; // mid = length of LL /2
        // while (temp != NULL) { // move temp till second last node of middle
        // one
        //     mid--;
        //     if (mid == 0) {
        //         ListNode* deletedNode = temp->next; // save the deleted node
        //         temp->next = temp->next->next; // connect previous node to
        //         next node of deleted node delete (deletedNode); break;
        //     }

        //     temp = temp->next;
        // }

        // return head;
    }
};