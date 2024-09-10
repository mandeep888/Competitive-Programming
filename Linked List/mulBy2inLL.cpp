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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void insertAtTail(ListNode* &ansHead , ListNode* &ansTail, int digit){
    ListNode* newNode = new ListNode(digit);
    
    if(ansHead == NULL){
        ansHead = ansTail = newNode;
    }else{
        ansTail -> next = newNode;
        ansTail = newNode;
    }
}

    ListNode* times2(ListNode* head){
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        int carry = 0;
        while(head!=NULL || carry!=0){
            int val = 0;
            if(head!=NULL){
                val = head->val;
                head = head->next;
            }
            
            int mulVal = (val * 2)+carry;
            int digit = mulVal%10;
            insertAtTail(ansHead,ansTail,digit);
            carry = mulVal/10;
            
            
            
        }
        return ansHead;
    }
    
    ListNode* doubleIt(ListNode* head) {
        //step1: reversing the list
        head = reverse(head);
        
        //step 2: calling fucntion to doubke the list
        head = times2(head);
        
        //step3 : reversing again
        head = reverse(head);
        return head;
    }
};