class Solution(object):
    def minTotalDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        a = len(grid)
        b = len(grid[0])

        pos_a = []
        pos_b = []
        for x in range(a):
            sub_grid = grid[x]
            for y in range(b):
                if sub_grid[y] == 1:
                    pos_a.append(x)
                    pos_b.append(y)

        # median
        pos_a.sort()
        pos_b.sort()
        meet_a = pos_a[len(pos_a) // 2]
        meet_b = pos_b[len(pos_a) // 2]

        return self.distance(meet_a, meet_b, pos_a, pos_b)

    def distance(self, meet_a, meet_b, pos_a, pos_b):
        dist_a = sum(abs(meet_a - pos_aa) for pos_aa in pos_a)
        dist_b = sum(abs(meet_b - pos_bb) for pos_bb in pos_b)

        return dist_a + dist_b


if __name__ == '__main__':

    grid = [[1, 0, 0, 0, 1],
            [0, 0, 0, 0, 0],
            [0, 0, 1, 0, 0]]

    assert(Solution().minTotalDistance(grid) == 6) # There is no way for the ball to STOP at the destination