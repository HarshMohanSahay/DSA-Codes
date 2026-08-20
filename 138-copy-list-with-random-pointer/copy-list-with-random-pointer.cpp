/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //make a new list which have new copy node in between
        if(!head) return NULL;
        Node* curr = head;
        while(curr){
            Node* currnext = curr->next;//b
            curr->next = new Node(curr->val);//a-x
            curr->next->next = currnext;
            curr = currnext;

        }

        //set random pointer 
        curr = head;
        while(curr && curr->next){
            if(curr->random == NULL){
                curr->next->random = NULL;
            }
            else{
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        //seprate the lists
        curr = head;
        Node* newhead = head->next;
        Node* newcurr = newhead;

        while(curr  && newcurr){
            curr->next = curr->next==NULL ? NULL :curr->next->next;
            newcurr->next = newcurr->next==NULL ? NULL :newcurr->next->next;

            curr = curr->next;
            newcurr = newcurr->next;
        }
        return newhead;
    }
};