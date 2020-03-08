# Trapping Rain Water (Hard)

## Description

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

![avatar](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

**Example:**

```html
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
```

## Idea

- Stack method
1. Split the array into two parts by the max element;
2. Left to max element: maintain an increasing queue as left walls;
3. Right to max element: maintain an increasing queue as left walls.

- DP method
1. For each position from left to right, record the left maximum value;
2. For each position from right to left, record the right maximum value;
3. The minimum of the left & right maximum values as the level of water.

- Two pointer
1. Move the smaller of the left and right pointers;
2. When the pointed value is smaller, update volume; otherwise, update the wall.
