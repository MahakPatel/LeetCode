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

        // ++++++++++ Brute Force Approch ++++++++++++

        // map<ListNode*,int> mpp; // craete Map 
        // ListNode* temp = head;

        // while(temp != NULL){
        //     if(mpp.find(temp) != mpp.end()){ // check if Node is already present in map or not
        //         return true; // if present return true
        //     }

        //     mpp[temp] = 1; // else put the Node into map
        //     temp = temp -> next; 
        // }

        // return false;


        // ++++ Optimal Solution [TortoiseHare Method] ++++++++++
        
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