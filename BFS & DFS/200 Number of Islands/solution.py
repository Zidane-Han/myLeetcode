class Solution:
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        # linear scan, find 1 --> update count
        # dfs from each root until all visited
        count = 0

        if not grid:
            return count

        row = len(grid)
        col = len(grid[0])

        for i in range(row):
            for j in range(col):
                if grid[i][j] == "1":
                    count += 1
                    self.dfs(grid, i, j)  # set all linked points to 0
        return count

    def dfs(self, grid, roww, coll):
        if roww < 0 or coll < 0 or roww >= len(grid) or coll >= len(grid[0]) or grid[roww][coll] != "1":
            return
        grid[roww][coll] = "0"

        self.dfs(grid, roww + 1, coll)
        self.dfs(grid, roww - 1, coll)
        self.dfs(grid, roww, coll + 1)
        self.dfs(grid, roww, coll - 1)


if __name__ == '__main__':

    grid = [['1', '1', '1', '1', '0'],
            ['1', '1', '0', '1', '0'],
            ['1', '1', '0', '0', '0'],
            ['0', '0', '0', '0', '0']]
    assert(Solution().numIslands(grid) == 1)

    grid = [['1', '1', '0', '0', '0'],
            ['1', '1', '0', '0', '0'],
            ['0', '0', '1', '0', '0'],
            ['0', '0', '0', '1', '1']]
    assert(Solution().numIslands(grid) == 3)