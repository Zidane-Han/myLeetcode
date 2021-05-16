# Kth Largest Element in an Array (Easy)

## Description

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.


**Example 1:**

```html
Input: [3,2,1,5,6,4] and k = 2
Output: 5
```


**Example 2:**

```html
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
```
Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

## Idea
Method 1: time O(NlgN); space O(1)

Method 2: time O(Nlgk); space O(k)

Method 3: time O(N) in average and O(N^2) worst; space O(1)