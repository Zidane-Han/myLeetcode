# Linked List Cycle (Easy)

## Description

Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

**Example 1:**
```html
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, 
            where tail connects to the second node.
            
3 -> 2 -> 0 -> -4
     ^          |     
     |__________|
```
     
**Example 2:**
```html
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, 
            where tail connects to the first node.
                        
    1 -> 2
    ^    |     
    |____|
```

**Example 3:**
```html
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
```

**Follow up**:

Can you solve it using O(1) (i.e. constant) memory?

## Idea
slow and fast pointers:

each time: slow moves one step; fast moves two step

determine if they can meet finally

