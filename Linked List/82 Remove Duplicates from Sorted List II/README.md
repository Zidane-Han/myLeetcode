# Remove Duplicates from Sorted List II (Medium)

## Description

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

**Example 1:**
```html
Input: 1->2->3->3->4->4->5

Output: 1->2->5
```

**Example 2:**
```html
Input: 1->1->1->2->3

Output: 2->3
```

## Idea
Use two pointers (prev & currt). Move the currt pointer to the place that are not equal to prev.next, then delete the nodes between two pointers.
