# Largest Rectangle in Histogram (Hard)

## Description

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

![avatar](https://assets.leetcode.com/uploads/2018/10/12/histogram.png)

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

![avatar](https://assets.leetcode.com/uploads/2018/10/12/histogram_area.png)

The largest rectangle is shown in the shaded area, which has area = 10 unit.

**Example:**

```html
Input: [2,1,5,6,2,3]
Output: 10
```

## Idea

- maintain a monotomous queue.
- move the pointer, when meeting a larger value, add it to the queue; otherwise, pop the number from the monoq until the new value can be added. (Pay attention to the length of the bins to be estimated. It is important.)
- in order to parse all the values, it is necessary to add value "0" or "-1" to the end of the *height* vector.
