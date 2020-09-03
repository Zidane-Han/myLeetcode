# Longest Valid Parentheses (Hard)

## Description

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

**Example 1:**

```html
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
```

**Example 2:**

```html
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
```

## Idea

1. Stack

    Use a stack to store the pos of "(";

    Use a pointer to store the left pos of the potential substring;

    When traverse to a ")", pop out the "(" at the top of the stack; update the result;

    When the stack is now empty, it is reasonable to update the result with start point;

    Otherwise, update with the one at the top of the stack.

2. DP

    Define dp[i] as the matched paranthese ended with s[i-1]. So dp[i] has values only when s[i-1] is ')'.

    Transition A: if s[i-2] is '(', then dp[i] = dp[i-2] + 2.

    Transition B (hard): if s[i-2] is ')', the one matching with it should be s[i-1-dp[i-1]]. Then update only when s[i-2-dp[i-1]] is '(', so dp[i] = dp[i-2-dp[i-1]] + dp[i-1] + 2.
