/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

    // ++++++++++++++ Optimal Solution +++++++++++++++
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL) // check for NULL
            return NULL;

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while (t1 != t2) { // this condition is for first node only (is first node is not a inetersection)
            t1 = t1->next; // move t1
            t2 = t2->next; // move t2

            if (t1 == t2) { // if both node is same then return any of node
                return t1;
            }

            if (t1 == NULL) { // if t1 reaches to last node
                t1 = headB; // place t1 to haed of second LL
            }

            if (t2 == NULL) { // if t2 reaches to last node 
                t2 = headA; // place t2 to head pf first LL
            }
        }

        return t1; // if first node is inetersection return any of node (t1 or t2)
    }

    // ++++++++++++++++ Better Solution ++++++++++++++
    // TC O(N1 + 2N2). SC O(1)
    //     ListNode* collisionPoint(ListNode* t1,ListNode* t2,int d){
    //         while(d){
    //             d--;
    //             t2 = t2 -> next;
    //         }

    //         while(t1 != t2){
    //             t1 = t1->next;
    //             t2 = t2->next;
    //         }

    //         return t1;
    //     }
    // public:
    //     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    //         ListNode* temp1 = headA;
    //         ListNode* temp2 = headB;

    //         int n1=0;
    //         int n2=0;

    //         while(temp1!= NULL){
    //             n1++;
    //             temp1 = temp1 -> next;
    //         }

    //         while(temp2!= NULL){
    //             n2++;
    //             temp2 = temp2 -> next;
    //         }

    //         int d;

    //         if(n1 < n2){
    //             d = n2-n1;
    //             return collisionPoint(temp1,temp2,d);
    //         }
    //            d = n1-n2;
    //          return collisionPoint(temp2,temp1,d);
    //     }

    // //+++++++++++++++++++ Brute Force +++++++++++++++++++++
    // TC O(N1 * LogN1 + N2 * LogN2). SC O(N1 OR N2)
    // map<ListNode*,int> mpp; // create Map

    // ListNode* temp1 = headA; // point to head of fisrt LL

    // while(temp1!= NULL){ // move till last node
    //     mpp[temp1] = 1; // put the Node into map
    //     temp1 = temp1 -> next;
    // }

    // ListNode* temp2 = headB; // point to head of second LL

    // while(temp2 != NULL){
    //     if(mpp.find(temp2) != mpp.end()){ // check if node is present in map
    //         return temp2; // if present in temp2 return temp2
    //     }

    //     temp2 = temp2 -> next;
    // }

    // return NULL; // if intersection not find return NULL
    // }
};