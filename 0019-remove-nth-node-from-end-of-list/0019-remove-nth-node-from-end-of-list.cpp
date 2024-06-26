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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // +++++++++++++++ Brute Force ++++++++++++ TC O(2N). SC O(1)
        int count =0;
        ListNode* temp = head;

        while(temp != NULL){ // find the length of LL
            count++;
            temp = temp -> next;
        }

        if(count == n ){ // if n == length of LL means the head of the LL then make the head->next is a new Head
            ListNode* newHead = head -> next;
            delete(head);

            return newHead;
        }

        int resultNode = count - n; // total minus given number

        temp = head;

        while(temp!=NULL){
            resultNode--;

            if(resultNode == 0) break;

            temp = temp->next;
        }

        ListNode* deletedNode = temp -> next; // for delete 

        temp->next = temp->next->next; // previous node of deleted nod connect to next Node of deleted node
        delete(deletedNode);

        return head;
    }
};