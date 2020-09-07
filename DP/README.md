# Dynamic Programming

**Make Set**





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

  $m[i,j]=m[i,k]+m[k+1,j]+p_{i-1}p_{k}p_{j} $

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

- LCS Problem: Longest Common Subsequence 
