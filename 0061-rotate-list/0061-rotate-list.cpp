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
    // +++++++++++++++++ Optimal Solution ++++++++++++++
    // TC O(n)
    // SC O(1)
    ListNode* rotateRight(ListNode* head, int k) {
        // Base case: If the list is empty, has only one node, or no rotation
        // needed (k == 0)
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        ListNode* cur = head;
        int len =
            1; // Initialize length of the list as 1 (since we start at head)

        // Traverse the list to calculate its length and find the last node
        while (cur->next != NULL) {
            len++;           // Increment the length
            cur = cur->next; // Move to the next node
        }

        // If k is equal to the list length, no rotation is needed
        if (k == len)
            return head;

        // Connect the last node to the head to form a circular linked list
        cur->next = head;

        // Reduce k to within the bounds of the list length
        k = k % len;

        // Calculate the number of steps to the new tail (len - k)
        k = len - k;

        // Traverse to the new tail (len - k steps from the head)
        while (k--)
            cur = cur->next;

        // Set the new head to the next node of the new tail
        head = cur->next;

        // Break the circular link by setting the new tail's next to NULL
        cur->next = NULL;

        // Return the new head after rotation
        return head;
    }
};