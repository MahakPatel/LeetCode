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
    // ++++++++++++ Optimal Solution +++++++++++++
    // TC O(n)
    //SC O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;
        ListNode* slow = head;

        for (int i = 0; i < n; i++) { // move fast till given n
            fast = fast->next;
        }

        if (fast == NULL) { // if n= length of LL then return second node as newHead
            ListNode* newHead = head->next;
            delete (head);
            return newHead;
        }

        while (fast->next != NULL) { // now move fast and slow by one node
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* deletedNode = slow->next; // save the delete node
        slow->next = slow->next->next; // connnect previous node of delete node
                                       // with next node of dleted node

        delete (deletedNode);

        return head;
        
    }
};