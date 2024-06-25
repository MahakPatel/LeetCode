/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        

        //++++ Optimal Solution [TortoiseHare Method] ++++++++++
        ListNode* slow = head; // move by 1 node everytime
        ListNode* fast = head;// move by 2 node everytime

        while (fast != NULL && fast->next != NULL) { // fast stop at last or NULL node
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow) // if loop present then both are collide at same node other wise they will not colide
                return true;
        }

        return false;
    }
};