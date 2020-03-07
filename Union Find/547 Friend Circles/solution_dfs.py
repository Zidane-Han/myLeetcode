class Solution:

    def dfs(self, M, row):
        # if row < 0 or row == len(M):
        # return

        for col in range(len(M[0])):
            if M[row][col] == 1:
                M[row][col] = 0
                M[col][row] = 0
                self.dfs(M, col)

    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        number = 0

        rows = len(M)
        cols = len(M[0])

        if rows == 0 or cols == 0:
            return number

        for row in range(rows):
            if sum(M[row]) > 0:
                number += 1
                self.dfs(M, row)

        return number


if __name__ == '__main__':
    M = [[1,1,0],
         [1,1,0],
         [0,0,1]]

    assert (Solution().findCircleNum(M) == 2)

    M = [[1,1,0],
         [1,1,1],
         [0,1,1]]

    assert (Solution().findCircleNum(M) == 1)