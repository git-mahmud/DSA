#include <bits/stdc++.h>
using namespace std;

// Structure representing a node.
struct node {
    int data;
    node *next;
};

// Head points to the first node, and tail points to the last node.
node *head = NULL, *tail = NULL;

// Insert a node at the beginning.
void insert_at_beginning() {
    node *temp = new node();

    cout << "Enter value: ";
    cin >> temp->data;

    // Connect the new node to the current first node.
    temp->next = head;
    head = temp;

    // If the list was empty, the new node is also the last node.
    if (tail == NULL) {
        tail = temp;
    }
}

// Insert a node at the end.
void insert_at_end() {
    node *temp = new node();

    cout << "Enter value: ";
    cin >> temp->data;

    // The new node will be the last node.
    temp->next = NULL;

    if (head == NULL) {
        // If the list is empty, both pointers point to the new node.
        head = temp;
        tail = temp;
    } else {
        // Connect the current last node to the new node.
        tail->next = temp;
        tail = temp;
    }
}

// Insert a node at position k (1-based indexing).
void insert_at_k(int k) {
    if (k < 1) {
        cout << "Invalid position." << endl;
        return;
    }

    if (k == 1) {
        insert_at_beginning();
        return;
    }

    node *cur = head;

    // Move to the node immediately before position k.
    for (int i = 1; i < k - 1 && cur != NULL; i++) {
        cur = cur->next;
    }

    if (cur == NULL) {
        cout << "Invalid position." << endl;
        return;
    }

    node *temp = new node();

    cout << "Enter value: ";
    cin >> temp->data;

    // Connect the new node to the following node.
    temp->next = cur->next;

    // Connect the previous node to the new node.
    cur->next = temp;

    // Update tail if the new node is the last node.
    if (temp->next == NULL) {
        tail = temp;
    }
}

// Delete the first node.
void delete_at_beginning() {
    if (head == NULL) {
        cout << "The list is already empty." << endl;
        return;
    }

    node *temp = head;

    // Move head to the second node.
    head = head->next;

    // If the list becomes empty, reset tail too.
    if (head == NULL) {
        tail = NULL;
    }

    // Free the old first node.
    delete temp;
}

// Delete the last node.
void delete_at_end() {
    if (head == NULL) {
        cout << "The list is already empty." << endl;
        return;
    }

    if (head == tail) {
        // Handle a list containing only one node.
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    node *cur = head;

    // Find the node immediately before the last node.
    while (cur->next != tail) {
        cur = cur->next;
    }

    // Delete the old last node.
    delete tail;

    // Update tail to the new last node.
    tail = cur;
    tail->next = NULL;
}

// Delete the node at position k (1-based indexing).
void delete_at_k(int k) {
    if (head == NULL) {
        cout << "The list is already empty." << endl;
        return;
    }

    if (k < 1) {
        cout << "Invalid position." << endl;
        return;
    }

    if (k == 1) {
        delete_at_beginning();
        return;
    }

    node *cur = head;

    // Move to the node immediately before position k.
    for (int i = 1; i < k - 1 && cur != NULL; i++) {
        cur = cur->next;
    }

    // Check whether the requested position exists.
    if (cur == NULL || cur->next == NULL) {
        cout << "Invalid position." << endl;
        return;
    }

    // Store the node that needs to be deleted.
    node *temp = cur->next;

    // Skip the target node.
    cur->next = temp->next;

    // Update tail if the deleted node was the last node.
    if (temp == tail) {
        tail = cur;
    }

    // Free the deleted node's memory.
    delete temp;
}

// Display all nodes.
void display() {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    node *cur = head;

    cout << "Linked List: ";

    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }

    cout << endl;
}

// Delete the entire linked list.
void delete_entire() {
    node *cur = head;

    while (cur != NULL) {
        // Save the current node.
        node *temp = cur;

        // Move to the next node before deleting.
        cur = cur->next;

        // Free the current node's memory.
        delete temp;
    }

    // Reset both pointers.
    head = NULL;
    tail = NULL;
}

// Reverse the linked list.
void reverse() {
    node *cur = head;
    node *prev = NULL;
    node *next = NULL;

    // The original first node becomes the last node.
    tail = head;

    while (cur != NULL) {
        // Save the next node before reversing the link.
        next = cur->next;

        // Reverse the current node's link.
        cur->next = prev;

        // Move both pointers forward.
        prev = cur;
        cur = next;
    }

    // The original last node becomes the first node.
    head = prev;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Example usage.
    insert_at_end();
    insert_at_end();
    insert_at_end();

    display();

    reverse();
    cout << "After reversing:" << endl;
    display();

    delete_at_k(2);
    cout << "After deleting position 2:" << endl;
    display();

    delete_entire();
    cout << "After deleting the entire list:" << endl;
    display();

    return 0;
}