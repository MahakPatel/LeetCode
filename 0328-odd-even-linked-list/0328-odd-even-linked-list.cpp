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
    ListNode* oddEvenList(ListNode* head) {

      if(head == NULL || head -> next == NULL) return head;

        ListNode* odd = head; // for odd index
        ListNode* even = head->next; // for even index

        ListNode* evenHead = head->next; // to save head of even index

        while(even != NULL && even->next != NULL){
            odd -> next = odd->next->next; // move odd to 2 index
            even -> next = even->next->next;// move even to 2 index

            odd = odd->next; 
            even = even->next;
        }

        odd -> next = evenHead; // connect last node of old to first nide(head of even LL)

        return head;
        // ++++++++++++++ Brute Force +++++++++++++++
        // int arr[];

        // ListNode* temp = head;

        // while(temp != NULL && temp -> next != NULL){
        //     arr.insert(temp -> val);
        //     temp = temp->next->next;
        // }

        // if(temp) arr.insert(temp->val);

        // temp = head -> next;

        // while(temp != NULL && temp -> next != NULL){
        //     arr.insert(temp -> val);
        //     temp = temp->next->next;
        // }

        // if(temp) arr.insert(temp->val);

        // i = 0;
        // temp = head;

        // while(temp != NULL){
        //     temp -> val = arr[i];
        //     i++;
        //     temp = temp -> next;
        // }

        // return head;
    }
};