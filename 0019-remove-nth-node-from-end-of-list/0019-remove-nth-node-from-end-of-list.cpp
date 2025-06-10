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

        // +++++++++++++++ Brute Force ++++++++++++ TC O(2N). SC O(1)
        // int count =0;
        // ListNode* temp = head;

        // while(temp != NULL){ // find the length of LL
        //     count++;
        //     temp = temp -> next;
        // }

        // if(count == n ){ // if n == length of LL means the head of the LL
        // then make the head->next is a new Head
        //     ListNode* newHead = head -> next;
        //     delete(head);

        //     return newHead;
        // }

        // int resultNode = count - n; // total minus given number

        // temp = head;

        // while(temp!=NULL){
        //     resultNode--;

        //     if(resultNode == 0) break;

        //     temp = temp->next;
        // }

        // ListNode* deletedNode = temp -> next; // for delete

        // temp->next = temp->next->next; // previous node of deleted nod
        // connect to next Node of deleted node delete(deletedNode);

        // return head;
    }
};