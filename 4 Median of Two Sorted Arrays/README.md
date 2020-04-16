# Median of Two Sorted Arrays (Hard)

## Description

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

**Example 1:**

```html
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
```

**Example 2:**

```html
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```

## Idea

The problem can be solved by finding (m+n+1)/2 and (m+n+2)/2 elements and getting their average. Therefore, this problem is converted to "find the k-th value among the lists".

The new problem is achieved by binary search. Each time k/2 element of one list will be discard until the target element has been found. There are several cases to consider:

- If the k/2-th element exist in both lists, discard the k/2 elements in the smaller list;
- If the k/2-th element does not exist in either list, discard the k/2 elements in another list;
- If either list is empty, return the element with the right index in another list;
- If k is 1, just return the smaller of the first element of two lists.
