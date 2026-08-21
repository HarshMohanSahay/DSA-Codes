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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next)return {-1,-1};
        ListNode* prev = head;
        ListNode* curr = head->next;
        int firstcriticalnode =-1;
        int prevcriticalnode = -1;
        int i =1;
        int maxdist = INT_MIN;
        int mindist = INT_MAX;
        while(curr && curr->next){
            if(prev->val<curr->val&& curr->val>curr->next->val || prev->val>curr->val&& curr->val<curr->next->val){
                if (firstcriticalnode == -1) {
                    firstcriticalnode = i;
                }
                 if (prevcriticalnode != -1) {
                    mindist = min(mindist, i - prevcriticalnode);
                    }
                
                prevcriticalnode = i;

            }
            i++;
            prev = curr;
            curr = curr->next;
        }
        if (firstcriticalnode == prevcriticalnode)
    return {-1, -1};
        maxdist = prevcriticalnode-firstcriticalnode;
        return {mindist,maxdist};
    }
};