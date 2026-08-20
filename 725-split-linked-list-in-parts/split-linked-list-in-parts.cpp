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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k);
        int l =0;
        ListNode* curr = head;
        while(curr){
            l++;
            curr = curr->next;
        }

        int perpartnode = l/k;
        int remainingnode = l%k;

        curr = head;
        ListNode* prev  = NULL;
        for(int i =0;i<k;i++){
            result[i] = curr;
            for(int i = 1;i<=perpartnode + (remainingnode>0?1:0);i++){
                prev = curr;
                curr = curr->next;
            }
            if(prev!=NULL)
            prev->next = NULL;
            remainingnode--;
        }
        return result;

    }
};