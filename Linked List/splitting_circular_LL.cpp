#include<bits/stdc++.h>
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


//code to split circular linked list
void split_List(Node* &head , Node* &firstHead,Node* &secondHead) {
    Node* slow = head;
    Node* fast = head;
    while(fast->next!=head){ // if u want to split singly linked list change head to NULL
        fast = fast -> next;
        if(fast->next!=head){ // if u want to split singly linked list change head to NULL
            fast = fast -> next;
        slow = slow->next;
        }
    }
    firstHead = head;
    secondHead = slow -> next;
    slow -> next = firstHead;
    fast->next = secondHead;
}

void printCircularList(Node* head) {
    if (head == nullptr) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    // Create a circular linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 1
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    Node* six = new Node(5);
    Node* seven = new Node(5);
    Node* eight = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = six;  // Completes the circle
    six->next = seven;  // Completes the circle
    seven->next = eight;  // Completes the circle
    eight->next = head;  // Connects the head to the end of the circle

    // Print original circular linked list
    cout << "Original circular list: ";
    printCircularList(head);

    // Split the list
    Node* firstHead = nullptr;
    Node* secondHead = nullptr;
    split_List(head, firstHead, secondHead);

    // Print the two circular linked lists
    cout << "First circular list: ";
    printCircularList(firstHead);

    cout << "Second circular list: ";
    printCircularList(secondHead);

    // Cleanup (deleting nodes)
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
        if (head == firstHead || head == secondHead) break;
    }
    while (firstHead != nullptr) {
        temp = firstHead;
        firstHead = firstHead->next;
        delete temp;
        if (firstHead == secondHead) break;
    }
    while (secondHead != nullptr) {
        temp = secondHead;
        secondHead = secondHead->next;
        delete temp;
        if (secondHead == head) break;
    }

    return 0;
}