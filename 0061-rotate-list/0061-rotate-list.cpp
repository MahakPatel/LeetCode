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

   ListNode* newNthNode(ListNode* temp,int k){
    int count = 1; // start with 1

    while(temp != NULL){
        if(count == k){ // if count match with k then you reach to length - k node
            return temp;
        }

        count++; // count the node which require to reach last node
        temp = temp -> next; // move temp 
    }

    return temp;
   }
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || k == 0) return head; // base case
        ListNode* tail = head; // to reach last node
        ListNode* temp = head; // for travelsal

        int length = 1; // start with 1 because count head node

        while(tail -> next!= NULL){ 
            length++; // find length of LL
            tail = tail -> next; // move tail to last node
        }

        if(k % length == 0) return head; // if(k is multiple of length of LL then rotation will be not there and return same LL EX 10 % 5 == 0 so no need to rotate)

        k = k % length; // if k is not the maltiple of length the assign the value of k (10 % 4 == 2)

        tail -> next = head;  // tail next(last node) point to head

       ListNode* newLastNode = newNthNode(head,length - k); // will get last node after rotation

       head = newLastNode -> next; // new head will be the lastLastNode of next
       newLastNode -> next = NULL; // last node next point to NULL

        return head;

        
    }
};