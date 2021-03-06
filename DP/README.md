# Dynamic Programming

## Steps

1. Characterize the structure of an optimal solution.
2. Recursively define the value of an optimal solution.
3. Compute the value of an optimal solution, typically in a bottom-up fashion.
4. Construct an optimal solution from computed information.

## Classical Problems


- Rod Cutting Problem

  Given a rod of length *n* inches and a table of prices $p_{i}$ for i = 1,2,...,n, determine the maximum revenue $r_{n}$ obtainable by cutting up the rod and selling the pieces. Note that if the price $p_{n}$ for a rod of length *n* is large enough, an optimal solution may require no cutting at all.

  ```html
  let r[0..n] be a new array
  r[0] = 0
  for j = 1 to n
      q = 0
      for i = 1 to j
          q = max(q, p[i]+r[j-i])
      r[j] = q
  return r[n]
  ```

- Matrix-chain Multiplication Problem

  Given a chain <A1, A2,...,An> of n matrices, where for i = 1,2,...,n, matrix Ai has dimension $p_{i-1}*p_{i}$, fully parenthesize the product A1A2...An in a way that minimizes the number of scalar multiplications.

  $ m[i,j]=m[i,k]+m[k+1,j]+p_{i-1}p_{k}p_{j} $

  ```
  n = p.length-1
  let m[1..n, 1..n] and s[1..n-1, 2..n] be new tables
  
  for i = 1 to n
      m[i,i] = 0
  
  for l = 2 to n	// l is the chain length
      for i = 1 to n-l+1
          j = i+l-1
          m[i,j] = INT_MAX
          for k = i to j-1
              q = m[i,k] + m[k+1,j] + p(i-1)p(k)p(j)
              if q < m[i,j]
                  m[i,j] = q
                  s[i,j] = k
  return m and s
  ```

- LCS Problem: [Longest Common Subsequence](https://github.com/Zidane-Han/myLeetcode/tree/master/DP/1143%20Longest%20Common%20Subsequence)

  c[i,j] = 0    if i = 0 or j = 0;

  c[i,j] = c[i-1,j-1] + 1   if i,j > 0 and Xi = Yi;
  
  c[i,j] = max(c[i,j-1],c[i-1,j])   if i,j > 0 and Xi != Yi;

  ```
  m = X.length
  n = Y.length
  let b[1..m, 1..n] and c[0..m, 0..n] be new tables

  for i = 1 to n
      c[i,0] = 0
  for j = 0 to n
      c[0,j] = 0

  for i = 1 to m
      for j = 1 to n
          if X[i] == Y[j]
              c[i,j] = c[i-1,j-1] + 1
              b[i,j] = "\"
          else if c[i-1,j] >= c[i,j-1]
              c[i,j] = c[i-1,j]
              b[i,j] = "|"
          else 
              c[i,j] = c[i,j-1]
              b[i,j] = "-"
  return c and b
  ```
