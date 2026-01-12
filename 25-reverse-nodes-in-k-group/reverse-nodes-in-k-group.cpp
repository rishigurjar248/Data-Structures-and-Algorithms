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
    ListNode* reverseKGroup(ListNode* head, int k) {

        int n = 0;
        ListNode* current = head;
        while (current != nullptr) {
            n++;
            current = current->next;
        }

        ListNode*dummy=new ListNode(-1,head);
        ListNode*temp1=dummy;
        for(int i=0;i<n/k;i++){
            ListNode*prev=temp1;
            ListNode*curr=temp1->next;
            ListNode*next=curr;
            for(int i=0;i<k;i++){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            ListNode*temp2=temp1->next;
            temp1->next->next=next;
            temp1->next=prev;
            temp1=temp2;
        }
        return dummy->next;
    }
};