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
    ListNode *detectCycle(ListNode *head) {
        // map<ListNode*,int> mpp;
        // ListNode* temp = head;

        // while(temp != NULL){
        //      if(mpp.find(temp) != mpp.end()){ // check if Node is already present in map or not
        //         return temp; // first element that present in map
        //     }

        //     mpp[temp] = 1; // else put the Node into map
        //     temp = temp -> next; 
        // }

        // return NULL;

        // ++++ Optimal Solution [TortoiseHare Method] ++++++++++
        ListNode* slow = head; // move by 1 node everytime
        ListNode* fast = head;// move by 2 node everytime

        while (fast != NULL && fast->next != NULL) { // fast stop at last or NULL node
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow){ // if loop present then both are collide at same node other wise they will not colide
                slow = head; // move slow to head pointer and fast at fast place only( slow and fast at same Node)

                while(slow != fast){
                    slow = slow -> next; // start move slow by 1 node
                    fast = fast -> next; // start move fast by 1 node
                }

                return slow; // slow and fast meet at starting of loop 
            }
        }

        return NULL;
    }
};