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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*>mp;
        ListNode* dummynode = new ListNode(0);

        dummynode->next = head;
        mp[0]=dummynode;

        int prefixsum=0;

        while(head!=NULL){
            prefixsum += head->val;
            if(mp.find(prefixsum)!=mp.end()){
                ListNode* start = mp[prefixsum];
                ListNode* temp = start;
                int psum = prefixsum;

                while(temp!=head){
                    temp = temp->next;
                    psum += temp->val;

                    if(temp!=head){
                        mp.erase(psum);
                    }
                }
                start->next = head->next;
            }
            else{
                mp[prefixsum] = head;
            }
            
            head= head->next;
        } 
        return dummynode->next;

    }
};