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
    ListNode* mergeNodes(ListNode* head) {
        //head = head->next;
        //if(!head) return NULL;
        //above wrong sequence
        head = head->next;
        if(!head) return NULL;
        
        ListNode* temp = head;
        int sum =0;
        while(temp && temp->val!=0){
            sum += temp->val;
            temp = temp->next;
        }
        head->val = sum;
        head->next = mergeNodes(temp);
        return head;
    }
};