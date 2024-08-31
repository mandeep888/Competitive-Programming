#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }

    ~Node() {
        if (next != nullptr) {
            delete next;
        }
    }
};

template <typename T>
Node<T>* solve(Node<T>* first, Node<T>* second) {
    if (first->next == nullptr) {
        first->next = second;
        return second;
    }

    Node<T>* curr1 = first;
    Node<T>* next1 = curr1->next;

    Node<T>* curr2 = second;
    Node<T>* next2 = curr2->next;

    while (next1 != nullptr && curr2 != nullptr) {
        if ((curr1->data <= curr2->data) && (curr2->data <= next1->data)) {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        } else {
            curr1 = next1;
            next1 = curr1->next;

            if (next1->next == nullptr) {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

template <typename T>
Node<T>* mergeLinkedList(Node<T>* first, Node<T>* second) {
    if (first == nullptr) {
        return second;
    }
    if (second == nullptr) {
        return first;
    }
    if (first->data < second->data) {
        return solve(first, second);
    } else {
        return solve(second, first);
    }
}

template <typename T>
void printList(Node<T>* head) {
    Node<T>* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

template <typename T>
Node<T>* insertEnd(Node<T>* head, T data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) {
        return newNode;
    }
    Node<T>* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

int main() {
    Node<int>* list1 = nullptr;
    Node<int>* list2 = nullptr;

    // Inserting elements into the first list
    list1 = insertEnd(list1, 1);
    list1 = insertEnd(list1, 3);
    list1 = insertEnd(list1, 5);
    list1 = insertEnd(list1, 7);

    // Inserting elements into the second list
    list2 = insertEnd(list2, 2);
    list2 = insertEnd(list2, 4);
    list2 = insertEnd(list2, 6);
    list2 = insertEnd(list2, 8);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    // Merging two sorted linked lists
    Node<int>* mergedList = mergeLinkedList(list1, list2);

    cout << "Merged List: ";
    printList(mergedList);

    // Clean up memory
    delete mergedList;

    return 0;
}
