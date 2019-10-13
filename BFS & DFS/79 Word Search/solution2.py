class Solution:
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        self.found = False
        for i in range(len(board)):
            for j in range(len(board[0])):
                self.visited = []
                self.dfs(i, j, board, word)
                if self.found == True:
                    return True
        return False

    def dfs(self, i, j, board, word):
        if len(word) == 0:
            self.found = True
            return

        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or word[0] != board[i][j] or (
                (i, j) in self.visited):
            return

        self.visited.append((i, j))

        self.dfs(i - 1, j, board, word[1:])
        self.dfs(i + 1, j, board, word[1:])
        self.dfs(i, j - 1, board, word[1:])
        self.dfs(i, j + 1, board, word[1:])

        if not self.found:
            self.visited.pop()

if __name__ == '__main__':
    board = [['A', 'B', 'C', 'E'],
             ['S', 'F', 'C', 'S'],
             ['A', 'D', 'E', 'E']]

    word = "ABCCED"
    assert(Solution().exist(board, word) == True)

    word = "SEE"
    assert(Solution().exist(board, word) == True)

    word = "ABCB"
    assert(Solution().exist(board, word) == False)