# Path Sum II (Medium)

## Description

Given the `root` of a binary tree and an integer `targetSum`, return all **root-to-leaf** paths where each path's sum equals `targetSum`.

A **leaf** is a node with no children.



**Example 1:**

![avatar](https://assets.leetcode.com/uploads/2021/01/18/pathsum1.jpg)

```html
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
```

**Example 2:**

![avatar](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)

```html
Input: root = [1,2,3], targetSum = 5
Output: []
```

**Example 3:**

```html
Input: root = [1,2], targetSum = 0
Output: []
```



**Constraints:**

- The number of nodes in the tree is in the range `[0, 5000]`.

- `-1000 <= Node.val <= 1000`

- `-1000 <= targetSum <= 1000`

  

## Idea

DFS