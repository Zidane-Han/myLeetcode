import copy

class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: None Do not return anything, modify board "in-place" instead.
        """
        row = len(board)
        col = len(board[0])

        # (i, j) in board --> (i+1, j+1) in boardd
        boardd = copy.deepcopy(board)
        for i in range(row):
            boardd[i].insert(0, 0)
            boardd[i].append(0)
        boardd.insert(0, [0] * (col + 2))
        boardd.append([0] * (col + 2))

        for i in range(row):
            for j in range(col):
                summ = boardd[i][j] + boardd[i][j + 1] + boardd[i][j + 2] + boardd[i + 1][j] + boardd[i + 1][j + 2] + \
                       boardd[i + 2][j] + boardd[i + 2][j + 1] + boardd[i + 2][j + 2]

                if board[i][j] == 0 and summ == 3:
                    board[i][j] = 1
                elif board[i][j] and summ < 2:
                    board[i][j] = 0
                elif board[i][j] and summ > 3:
                    board[i][j] = 0

        return board

if __name__ == '__main__':
    board = [[0, 1, 0],
             [0, 0, 1],
             [1, 1, 1],
             [0, 0, 0]]

    result = [[0,0,0],
              [1,0,1],
              [0,1,1],
              [0,1,0]]

    assert(Solution().gameOfLife(board) == result)