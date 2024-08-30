struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
#include <bits/stdc++.h>
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL)
            return NULL;
        ListNode* curr = head;
        while(curr->next !=NULL){
            if(curr->val == curr->next->val){
                ListNode* toBeDeleted = curr->next;
                curr->next = curr->next->next;
                delete(toBeDeleted);
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};