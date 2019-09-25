class Solution:
    def findLonelyPixel(self, picture):
        """
        :type picture: List[List[str]]
        :rtype: int
        """
        number = 0

        rows = len(picture)
        cols = len(picture[0])

        if rows == 0 or cols == 0:
            return number

        row_list = [0 for i in range(rows)]
        col_list = [0 for i in range(cols)]
        Bset = []

        for row in range(rows):
            for col in range(cols):
                if picture[row][col] == 'B':
                    row_list[row] += 1
                    col_list[col] += 1
                    Bset.append([row, col])

        for item in Bset:
            if row_list[item[0]] == 1 and col_list[item[1]] == 1:
                number += 1

        return number



if __name__ == '__main__':
    picture = [['W', 'W', 'B'],
               ['W', 'B', 'W'],
               ['B', 'W', 'W']]
    assert(Solution().findLonelyPixel(picture) == 3)

