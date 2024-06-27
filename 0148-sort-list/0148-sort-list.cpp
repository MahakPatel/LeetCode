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
    ListNode* sortList(ListNode* head) {

        // ++++++++++++ Brute Force ++++++++++++++++++++++

        // int arr[];
        // ListNode* temp = head;

        // while (temp != NULL) {
        //     arr.insert(temp->val) temp = temp->next;
        // }

        // sort(arr);
        // int i = 0;
        // temp = head;

        // while (temp != NULL) {
        //     temp->val = arr[i];
        //     i++;
        //     temp = temp->next;
        // }

        // return head;

        // ++++++++++++ Optimal Using mergeSort +++++++++++++++

        if (head == NULL ||
            head->next == NULL) { // check for empty of 1 node in LL
            return head;
        }

        ListNode* middleNode = findMiddleNode(head); // get middle node of LL
        ListNode* right =
            middleNode->next;    // right part start with next of middleNode
        middleNode->next = NULL; // first portion last node next = NULL
        ListNode* left = head;

        left = sortList(left);   // merge call
        right = sortList(right); // merge call

        return merge2list(left, right); // mergesort call
    }

    ListNode* merge2list(ListNode* left, ListNode* right) {
        ListNode* dummyNode = new ListNode(-1); // create dummy node
        ListNode* temp = dummyNode;

        while (left != NULL && right != NULL) {
            if (left->val < right->val) { // swap which ever is smaller
                temp->next = left;
                temp = left;
                left = left->next;
            } else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        if (left)
            temp->next = left; // if left portion still have node
        else
            temp->next = right; // if right portion still have node

        return dummyNode->next;
    }
    ListNode* findMiddleNode(ListNode* head) {
        ListNode* fast = head->next; // move 2 node at a time
        ListNode* slow = head;       // move 1 node at a time

        while (fast != NULL &&
               fast->next !=
                   NULL) { // move till fast and fast->next is not eqaul to null
            slow = slow->next;
            fast = fast->next->next;
        }

        // if fast reach to last node(for odd numbers of nodes in LL)
        // if fast reach to NULL (for even numbers of nodes in LL)

        return slow;
    }
};