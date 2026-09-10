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
    ListNode* findkthnode(ListNode* head , int k){
        int cnt = 1;
        ListNode* temp = head;
        while(temp!=NULL){
                if(cnt==k) return temp;
                cnt++;
                temp=temp->next;
        }
        return NULL;
        
    }
    ListNode* reverseLinkedll(ListNode* head){
        if(head==NULL || head->next==NULL)return head;
        ListNode* newhead = reverseLinkedll(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newhead;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* kthnode = NULL;
        ListNode* nextnode = NULL;
        ListNode* prevLast = NULL;
        while( temp!=NULL ){
            kthnode = findkthnode(temp,k);
            if(kthnode == NULL){
                if(prevLast) prevLast->next = nextnode;
                break;

            }
            nextnode = kthnode->next;
            kthnode->next = NULL;
            kthnode = reverseLinkedll(temp);
            if(temp==head) head = kthnode;
            else{
                prevLast->next = kthnode;
            }

            prevLast = temp;
            temp = nextnode;
            
        }
        return head;
    }
    
};