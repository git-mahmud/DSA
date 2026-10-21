#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
} *head, *tail;

// Insert a node at the beginning.
void insert_at_beginning()
{
    node *temp = new node();

    cout << "Enter value: ";
    cin >> temp->data;

    // The new node has no previous node.
    temp->prev = NULL;

    // Connect the new node to the current first node.
    temp->next = head;

    if (head == NULL)
    {
        // If the list is empty, the new node is both head and tail.
        head = temp;
        tail = temp;
    }
    else
    {
        // Update the old first node's previous pointer.
        head->prev = temp;

        // Make the new node the first node.
        head = temp;
    }
}

// Insert a node at the end.
void insert_at_end()
{
    node *temp = new node();

    cout << "Enter value: ";
    cin >> temp->data;

    // The new node has no next node.
    temp->next = NULL;

    if (head == NULL)
    {
        // If the list is empty, the new node is both head and tail.
        temp->prev = NULL;
        head = temp;
        tail = temp;
    }
    else
    {
        // Connect the current last node to the new node.
        temp->prev = tail;
        tail->next = temp;

        // Update tail to the new last node.
        tail = temp;
    }
}

// Insert a node at position k (1-based indexing).
void insert_at_k(int k)
{
    if (k < 1)
    {
        cout << "Invalid position." << endl;
        return;
    }

    if (k == 1)
    {
        insert_at_beginning();
        return;
    }

    node *cur = head;

    // Move to the node immediately before position k.
    for (int i = 1; i < k - 1 && cur != NULL; i++)
    {
        cur = cur->next;
    }

    if (cur == NULL)
    {
        cout << "Invalid position." << endl;
        return;
    }

    node *temp = new node();

    cout << "Enter value: ";
    cin >> temp->data;

    // Connect the new node to the previous node.
    temp->prev = cur;

    // Connect the new node to the following node.
    temp->next = cur->next;

    // Update the previous node's next pointer.
    cur->next = temp;

    if (temp->next != NULL)
    {
        // Update the following node's previous pointer.
        temp->next->prev = temp;
    }
    else
    {
        // If inserted at the end, update tail.
        tail = temp;
    }
}

// Delete the first node.
void delete_at_beginning()
{
    if (head == NULL)
    {
        cout << "The list is already empty." << endl;
        return;
    }

    node *temp = head;

    // Move head to the second node.
    head = head->next;

    if (head == NULL)
    {
        // If the list becomes empty, reset tail too.
        tail = NULL;
    }
    else
    {
        // The new first node has no previous node.
        head->prev = NULL;
    }

    // Free the old first node's memory.
    delete temp;
}

// Delete the last node.
void delete_at_end()
{
    if (tail == NULL)
    {
        cout << "The list is already empty." << endl;
        return;
    }

    node *temp = tail;

    // Move tail to the previous node.
    tail = tail->prev;

    if (tail == NULL)
    {
        // If the list becomes empty, reset head too.
        head = NULL;
    }
    else
    {
        // The new last node has no next node.
        tail->next = NULL;
    }

    // Free the old last node's memory.
    delete temp;
}

// Delete the node at position k (1-based indexing).
void delete_at_k(int k)
{
    if (head == NULL)
    {
        cout << "The list is already empty." << endl;
        return;
    }

    if (k < 1)
    {
        cout << "Invalid position." << endl;
        return;
    }

    if (k == 1)
    {
        delete_at_beginning();
        return;
    }

    node *cur = head;

    // Move to the node at position k.
    for (int i = 1; i < k && cur != NULL; i++)
    {
        cur = cur->next;
    }

    if (cur == NULL)
    {
        cout << "Invalid position." << endl;
        return;
    }

    // Connect the previous node to the following node.
    cur->prev->next = cur->next;

    if (cur->next != NULL)
    {
        // Update the following node's previous pointer.
        cur->next->prev = cur->prev;
    }
    else
    {
        // If the deleted node was the last node, update tail.
        tail = cur->prev;
    }

    // Free the deleted node's memory.
    delete cur;
}

// Reverse the doubly linked list.
void reverse()
{
    node *cur = head;

    while (cur != NULL)
    {
        // Swap the previous and next pointers.
        swap(cur->prev, cur->next);

        // Move to the next node in the original list.
        cur = cur->prev;
    }

    // Swap head and tail after reversing all links.
    swap(head, tail);
}

// Display the list from beginning to end.
void display()
{
    if (head == NULL)
    {
        cout << "The list is empty." << endl;
        return;
    }

    node *cur = head;

    cout << "Doubly Linked List: ";

    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    head = NULL;
    tail = NULL;

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

    return 0;
}