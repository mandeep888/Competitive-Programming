Node* add(Node* head) {
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 1; // Start with 1 as we need to add 1 to the list

    // Traverse the entire linked list
    while (head != NULL || carry != 0) {
        int sum = carry;
        if (head != NULL) {
            sum += head->data;
            head = head->next;
        }
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
    }

    return ansHead;
}
