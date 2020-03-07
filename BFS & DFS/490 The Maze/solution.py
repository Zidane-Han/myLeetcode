class Solution:
    def hasPath(self, maze, start, destination):
        """
        :type maze: List[List[int]]
        :type start: List[int]
        :type destination: List[int]
        :rtype: bool
        """
        visited = set()
        m, n = len(maze), len(maze[0])

        def dfs(i, j, m, n):
            if [i, j] == destination:
                return True
            if (i, j) in visited:
                return False
            visited.add((i, j))

            # Down
            x = i
            while x + 1 < m and maze[x + 1][j] != 1:
                x += 1
            if dfs(x, j, m, n):
                return True

            # Up
            x = i
            while x - 1 >= 0 and maze[x - 1][j] != 1:
                x -= 1
            if dfs(x, j, m, n):
                return True

            # Right
            x = j
            while x + 1 < n and maze[i][x + 1] != 1:
                x += 1
            if dfs(i, x, m, n):
                return True

            # Left
            x = j
            while x - 1 >= 0 and maze[i][x - 1] != 1:
                x -= 1
            if dfs(i, x, m, n):
                return True

            return False

        return dfs(start[0], start[1], m, n)


if __name__ == '__main__':
    maze = [[0, 0, 1, 0, 0],
            [0, 0, 0, 0, 0],
            [0, 0, 0, 1, 0],
            [1, 1, 0, 1, 1],
            [0, 0, 0, 0, 0]]
    start = [0, 4]
    destination = [4, 4]
    assert(Solution().hasPath(maze, start, destination) == True)

    maze = [[0, 0, 1, 0, 0],
            [0, 0, 0, 0, 0],
            [0, 0, 0, 1, 0],
            [1, 1, 0, 1, 1],
            [0, 0, 0, 0, 0]]
    start = [0, 4]
    destination = [3, 2]
    assert(Solution().hasPath(maze, start, destination) == False) # There is no way for the ball to STOP at the destination