# Singly Linked List (C++)

A simple singly linked list written in C++ with `head` and `tail` pointers.
Each node stores an integer (`data`) and a pointer to the next node (`next`).

## File

- `singly_linked_list.cpp` - all functions and an example `main()`

## Functions

| Function | What it does | Time |
|---|---|---|
| `insert_at_beginning()` | Adds a new node at the front | O(1) |
| `insert_at_end()` | Adds a new node at the back (uses `tail`) | O(1) |
| `insert_at_k(k)` | Adds a new node at position `k` (1-based) | O(k) |
| `delete_at_beginning()` | Removes the first node | O(1) |
| `delete_at_end()` | Removes the last node | O(n) |
| `delete_at_k(k)` | Removes the node at position `k` (1-based) | O(k) |
| `display()` | Prints all values from first to last | O(n) |
| `delete_entire()` | Frees every node and empties the list | O(n) |
| `reverse()` | Reverses the list by changing the links | O(n) |

## Notes

- Positions start from 1 (not 0).
- `head` points to the first node. `tail` points to the last node.
- Every insert and delete function keeps `tail` correct.
- Wrong positions print `Invalid position.`
- Deleting from an empty list prints `The list is already empty.`

## How to Run

```bash
g++ singly_linked_list.cpp -o singly_linked_list
./singly_linked_list
```

## Example

The `main()` function:
1. Inserts 3 values at the end
2. Displays the list
3. Reverses the list and displays it
4. Deletes position 2 and displays it
5. Deletes the entire list and displays it

Input:
```
10 20 30
```

Output:
```
Linked List: 10 20 30
After reversing:
Linked List: 30 20 10
After deleting position 2:
Linked List: 30 10
After deleting the entire list:
The list is empty.
```
