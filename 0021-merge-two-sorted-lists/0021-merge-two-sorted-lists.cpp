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
    // ++++++++++++++ Brute Force ++++++++++++++++++++
    // TC O(n+m)
    // SC O(n+m)
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     ListNode* dummy = new ListNode(-1); // Dummy node to simplify merging
    //     ListNode* current = dummy;          // Pointer to build the merged list

    //     // Traverse both lists until one becomes NULL
    //     while (list1 != NULL && list2 != NULL) {
    //         if (list1->val <= list2->val) {
    //             current->next = list1; // Attach list1 node if smaller
    //             list1 = list1->next;
    //         } else {
    //             current->next = list2; // Attach list2 node if smaller
    //             list2 = list2->next;
    //         }
    //         current = current->next; // Move forward in merged list
    //     }

    //     // Attach any remaining nodes from either list
    //     if (list1 != NULL)
    //         current->next = list1;
    //     if (list2 != NULL)
    //         current->next = list2;

    //     return dummy->next; // Return merged list (skipping dummy node)
    // }

    // ++++++++++++++ Optimal Solution ++++++++++++++++++++
    // TC O(n+m)
    // SC O(1)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Base cases: if either list is empty, return the other list
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        // Ensure list1 always has the smaller head value
        if (list1->val >= list2->val)
            std::swap(list1, list2);

        // The merged list will start with the smaller head value
        ListNode* res = list1;

        // Iterate while both lists are non-empty
        while (list1 != NULL && list2 != NULL) {
            ListNode* temp =
                NULL; // Temporary pointer to track the last sorted node

            // Move list1 forward while its value is smaller or equal to list2's
            // value
            while (list1 != NULL && list1->val <= list2->val) {
                temp = list1;
                list1 = list1->next;
            }

            // Link the last node of list1 to list2 (merging step)
            temp->next = list2;

            // Swap list1 and list2 so that list1 always remains the smaller
            // current node
            std::swap(list1, list2);
        }

        return res; // Return the merged sorted linked list
    }
};