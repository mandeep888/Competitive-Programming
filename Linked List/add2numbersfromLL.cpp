#include <iostream>
using namespace std;

class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

void printList(Node *node) {
    while (node!= NULL) {
        cout << node -> data << " ";
        node = node -> next;
    }
    cout << endl;
}

Node* reverseList(Node *&head) {
    Node *prev = NULL;
    Node *current = head;
    Node *nextNode;
    
    while (current!= NULL) {
        nextNode = current -> next;
        current -> next = prev;
        prev = current;
        current = nextNode;
    }
    
    return prev;
}

void insertAtTail(Node* &ansHead , Node* &ansTail, int digit){
    Node* newNode = new Node(digit);
    
    if(ansHead == NULL){
        ansHead = ansTail = newNode;
    }else{
        ansTail -> next = newNode;
        ansTail = newNode;
    }
}

Node* add(Node* &first , Node*& second){
    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while (first!= NULL || second!= NULL || carry!= 0) {
        int val1 = 0; //value of first->data
        if(first!=NULL){ // if first is NULL then it will be considered 0.
            val1 = first -> data;
            first = first -> next;
        }
        int val2 = 0; // value of second->data
        if(second!=NULL){ // if second is NULL then it will be considered 0.
            val2 = second -> data;
            second = second -> next;
        }
        int sum = val1 + val2 + carry;
        int digit = sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry = sum / 10;
    }
    
    return ansHead;  // returning the head of the reversed resultant list.  // Note: the head of the reversed resultant list is actually the tail of the original list. So, it is correct to return ansTail.  // Note: The original list is not modified in this function.  // Note: The original list is not modified in this function.  // Note: The original list is not modified in this function.  // Note: The original list is not modified in
}

Node* addTwoList(Node* first , Node* second){
    //reversing given lists
    first = reverseList(first);
    second = reverseList(second);

    //adding the lists
    Node *ans = add(first,second);
    
    //reversing the resultant list
    ans = reverseList(ans);
    
    return ans;
}


int main() {
    // Create first linked list: 3 -> 4 -> 2  (represents the number 243)
    Node* first = new Node(3);
    first->next = new Node(4);
    first->next->next = new Node(2);

    // Create second linked list: 4 -> 6 -> 5  (represents the number 564)
    Node* second = new Node(4);
    second->next = new Node(6);
    second->next->next = new Node(5);

    // Add the two lists
    Node* result = addTwoList(first, second);

    // Print the result
    cout << "Sum of two numbers: ";
    printList(result);

    return 0;
}