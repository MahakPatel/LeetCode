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
    ListNode* middleNode(ListNode* head) {


        // +++++++++++++++ TortoiseHare Method ++++++++++++
        ListNode* fast = head; // move 2 node at a time
        ListNode* slow = head; // move 1 node at a time

        while(fast != NULL && fast->next != NULL){ // move till fast and fast->next is not eqaul to null
            slow = slow->next;
            fast = fast->next->next;
        }

        // if fast reach to last node(for odd numbers of nodes in LL)
        // if fast reach to NULL (for even numbers of nodes in LL)

        return slow; // once above condition satisfied slow pointer always at mid of LL   
    }
};