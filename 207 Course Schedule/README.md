# Course Schedule (Medium)

## Description

There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite **pairs**, is it possible for you to finish all courses?

**Example 1:**

```html
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
```

**Example 2:**

```html
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
```

**Constraints:**

- The input prerequisites is a graph represented by **a list of edges**, not adjacency matrices. Read more about how a graph is represented.
- You may assume that there are no duplicate edges in the input prerequisites.
- 1 <= numCourses <= 10^5

## Idea

The problem is equivalent to whether a cycle exists in the graph.

- DFS

  Traverse all the nodes in order by dfs. If meeting the node again during traversal, the the cycle exists.

  Time - O(V+E); Space - O(V+E)

- BFS

  Start from with vertices with 0 incoming edge, insert them into a list S. At the same time we reduce the incoming degree of all their outgoing edges，after that find new vertices with 0 incoming edges and go on. In the end, the incoming degree of any nodes is not 0, the cycle exists. 

  Time - O(V+E); Space - O(V+E)

- Improvements: refer to https://www.cnblogs.com/yrbbest/p/4493547.html