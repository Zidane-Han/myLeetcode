class Solution:

    def find(self, k, people):
        if k != people[k]:
            people[k] = self.find(people[k], people)
        return people[k]

    def union(self, i, j, people):
        p = self.find(i, people)
        q = self.find(j, people)

        if p == q:
            return
        else:
            people[p] = q

    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        length = len(M)

        if length == 0: return 0

        people = list(range(length))

        for i in range(length):
            for j in range(length):
                if M[i][j] == 1:
                    self.union(i, j, people)

        circle = set(self.find(i, people) for i in range(length))

        return len(circle)

if __name__ == '__main__':
    M = [[1,1,0],
         [1,1,0],
         [0,0,1]]

    assert (Solution().findCircleNum(M) == 2)

    M = [[1,1,0],
         [1,1,1],
         [0,1,1]]

    assert (Solution().findCircleNum(M) == 1)