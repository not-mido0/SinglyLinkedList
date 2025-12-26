# SinglyLinkedList


This repository contains a robust implementation of a **Singly Linked List** in C++, including basic operations and advanced problem-solving techniques. 
The project covers fundamental concepts and several complex scenarios often found in competitive programming and technical interviews.

## 🛠 Features Implemented

### 1. Basic Operations
- `insert_front(val)`, `insert_last(val)`, `insert_at(index, val)`
- `delete_front()`, `delete_last()`, `delete_at(index)`
- `find(val)`, `index_of(val)`, `get_nth(n)`

### 2. Advanced Algorithms (The Fun Part!)
- **Recursive Operations:** `print_recursive`, `max_recursive`.
- **Duplicate Removal:** `rm_dublicates_from_sorted` (Uses a Dummy Head for efficiency).
- **List Manipulation:** `reverse_chains(k)` (reverses segments), `left_rotate(k)`, `move_to_back(key)`.
- **Mathematical Logic:** `add_2_numbers` (Adds two numbers represented by lists with carry handling).
- **Rearranging:** `ArrangeODD_EVEN_Nodes` (Odd indices first, then even).

---

##  Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| `reverse_nodes_recursive` | $O(n)$ | $O(1)$ |
| `add_2_numbers` | $O(\max(n, m))$ | $O(\max(n, m))$ |
| `rm_dublicates_from_sorted` | $O(n)$ | $O(1)$ |
| `reverse_chains(k)` | $O(k)$ | $O(1)$ |
| `insert_last` | $O(n)$ | $O(1)$ |

> **Note:** Time complexity for some operations can be improved to $O(1)$ by adding a `tail` pointer.

---

##  Credits
Special thanks to **Dr. Mostafa Saad** for the challenging homework problems that helped shape the advanced logic in this project.

##  Author
**Medo (not-mido0)**
- CS Student.
