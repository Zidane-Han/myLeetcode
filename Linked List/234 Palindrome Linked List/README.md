# Palindrome Linked List (Easy)

## Description
Given a singly linked list, determine if it is a palindrome.

**Example 1:**
```html
Input: 1->2
Output: false
```
**Example 2:**
```html
Input: 1->2->2->1
Output: true
```
**Follow up:**

Could you do it in O(n) time and O(1) space?

## Idea
It is easy to pass the cases, but it is challenging to do it in O(1) space.

Approach:
1. move the pointer to the middle point of the list;
2. reverse the second half of the list;
3. compare the each value of the first and second halfs.
