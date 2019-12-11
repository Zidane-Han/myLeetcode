# Queue Reconstruction by Height (Medium)

## Description

Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

**Note:**
The number of people is less than 1,100.

 
**Example**
```html
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
```

## Idea
Support we are going to arrange (h, k) and the people higher than h have been in the queue. Then the person (h, k) will be arranged at the (k+1)-th position of the queue.

Approach:
- Sort the give array from the highest to shortest. If they have the same height, they will be sorted by the second number, from smallest to largest.
- Put the person of the new array into the queue. The person (h, k) will be inserted into the (k+1) pos of the queue. 
