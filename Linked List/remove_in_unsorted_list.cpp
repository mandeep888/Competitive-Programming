#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        map<int,bool> visited;
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL) {
            if(visited[curr->val]) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                visited[curr->val] = true;
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};

int main() {
    // Create an unsorted linked list with duplicates
    // Example: 5 -> 1 -> 3 -> 2 -> 5 -> 3 -> 4 -> 1
    ListNode* head = new ListNode(5);
    head->next = new ListNode(1);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next->next = new ListNode(1);

    // Print the original linked list
    cout << "Original list: ";
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Remove duplicates
    Solution solution;
    head = solution.deleteDuplicates(head);

    // Print the updated linked list
    cout << "List after removing duplicates: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Clean up the remaining nodes
    while (head != nullptr) {
        ListNode* node = head;
        head = head->next;
        delete node;
    }

    return 0;
}
