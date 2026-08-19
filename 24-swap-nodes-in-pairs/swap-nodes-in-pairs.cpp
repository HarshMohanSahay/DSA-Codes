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
    ListNode* swapPairs(ListNode* head) {
      if(!head || !head->next ){
        return head;
      }
      //a - head
      // b - head->next
      //c - head->next->next

      // a->next = swapPairs(c);
      // b->next = a;
      // return current head which is b
    
    //   head->next = swapPairs(head->next->next);
    //   head->next->next = head; this will make problem beacuse head->next is changin so store this

    ListNode* temp = head->next;
    head->next = swapPairs(head->next->next);
    temp->next = head;

    return temp;



    }
};