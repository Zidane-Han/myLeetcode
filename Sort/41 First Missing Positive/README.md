# First Missing Positive (Hard)

## Description

Given an unsorted integer array, find the smallest missing positive integer.

**Example 1:**

```html
Input: [1,2,0]
Output: 3
```

**Example 2:**

```html
Input: [3,4,-1,1]
Output: 2
```

**Example 3:**

```html
Input: [7,8,9,11,12]
Output: 1
```

**Follow up:**

Your algorithm should run in O(n) time and uses constant extra space.

## Idea

"bucket sort": move value i to the i-th position 

pay attention: keep swaping the values until the value at i-th postion cannot be moved any more. This requires while operation, not if operation.