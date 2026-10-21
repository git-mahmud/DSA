# Linked List

C++ implementations of the two most common linked list types, written for learning Data Structures. Each list is built from scratch using `struct` nodes, raw pointers, and manual memory management (`new` / `delete`).

## Contents

- [Folder Structure](#folder-structure)
- [Singly vs Doubly](#singly-vs-doubly)
- [Singly Linked List](#singly-linked-list)
- [Doubly Linked List](#doubly-linked-list)
- [How to Compile and Run](#how-to-compile-and-run)
- [Example](#example)
- [Notes](#notes)

## Folder Structure

```
Linked List/
├── README.md
├── Singly Linked List/
│   └── singly_linked_list.cpp
└── Doubly Linked List/
    └── doubly_linked_list.cpp
```

## Singly vs Doubly

| Feature | Singly Linked List | Doubly Linked List |
|---|---|---|
| Node fields | `data`, `next` | `data`, `prev`, `next` |
| Traversal | Forward only | Forward and backward |
| Memory per node | Less | More (extra `prev` pointer) |
| Delete at end | O(n) | O(1) |
| Pointers kept | `head`, `tail` | `head`, `tail` |

## Singly Linked List

**File:** `Singly Linked List/singly_linked_list.cpp`

```cpp
struct node {
    int data;
    node *next;
};
```

| Function | Description | Time |
|---|---|---|
| `insert_at_beginning()` | Adds a node at the front | O(1) |
| `insert_at_end()` | Adds a node at the back (uses `tail`) | O(1) |
| `insert_at_k(k)` | Adds a node at position `k` | O(k) |
| `delete_at_beginning()` | Removes the first node | O(1) |
| `delete_at_end()` | Removes the last node | O(n) |
| `delete_at_k(k)` | Removes the node at position `k` | O(k) |
| `display()` | Prints all values from first to last | O(n) |
| `delete_entire()` | Frees every node and empties the list | O(n) |
| `reverse()` | Reverses the list by changing the links | O(n) |

## Doubly Linked List

**File:** `Doubly Linked List/doubly_linked_list.cpp`

```cpp
struct node {
    int data;
    node *prev;
    node *next;
};
```

| Function | Description | Time |
|---|---|---|
| `insert_at_beginning()` | Adds a node at the front | O(1) |
| `insert_at_end()` | Adds a node at the back (uses `tail`) | O(1) |
| `insert_at_k(k)` | Adds a node at position `k` | O(k) |
| `delete_at_beginning()` | Removes the first node | O(1) |
| `delete_at_end()` | Removes the last node (uses `tail->prev`) | O(1) |
| `delete_at_k(k)` | Removes the node at position `k` | O(k) |
| `display()` | Prints all values from first to last | O(n) |
| `reverse()` | Reverses the list by swapping `prev` and `next` | O(n) |

## How to Compile and Run

Requires a C++ compiler such as `g++`.

**Singly Linked List**
```bash
cd "Singly Linked List"
g++ singly_linked_list.cpp -o singly_linked_list
./singly_linked_list
```

**Doubly Linked List**
```bash
cd "Doubly Linked List"
g++ doubly_linked_list.cpp -o doubly_linked_list
./doubly_linked_list
```

## Example

Both programs run the same demo in `main()`:

1. Insert 3 values at the end
2. Display the list
3. Reverse the list and display it
4. Delete position 2 and display it

**Input**
```
10 20 30
```

**Output (Doubly Linked List)**
```
Doubly Linked List: 10 20 30
After reversing:
Doubly Linked List: 30 20 10
After deleting position 2:
Doubly Linked List: 30 10
```

The singly version prints `Linked List:` instead, and also ends by deleting the entire list.

## Notes

- Positions are **1-based** (the first node is position 1).
- `head` points to the first node and `tail` points to the last node.
- Every insert and delete function keeps `head` and `tail` correct, including for empty and single-node lists.
- Invalid positions print `Invalid position.`
- Deleting from an empty list prints `The list is already empty.`
- Each function that inserts reads its value from `cin`.