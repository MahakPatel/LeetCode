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
    ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL || head->next == NULL) {
        return head; // Edge case: empty or single-node list
    }

    ListNode* dummy = new ListNode(0); // Dummy node for simplicity
    dummy->next = head;

    ListNode *cur = dummy, *pre = dummy, *nex = dummy;
    int count = 0;

    // Count total nodes in the linked list
    while (cur->next != NULL) {
        cur = cur->next;
        count++;
    }

    // Reverse every k-group
    while (count >= k) {
        cur = pre->next; // First node of the current group
        nex = cur->next; // Second node of the current group

        // Reverse k nodes (k-1 swaps needed)
        for (int i = 1; i < k; i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }

        // Move pre to cur (new end of reversed group)
        pre = cur;
        count -= k; // Reduce remaining count
    }

    return dummy->next; // Return new head of the list
}

};