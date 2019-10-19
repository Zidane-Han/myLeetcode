class Solution:
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        # sum(A,B) in hash table{value:frequency}, traversal C&D

        count = 0
        dict = {}

        for a in A:
            for b in B:
                sum_ab = a + b
                if sum_ab in dict:
                    dict[sum_ab] += 1
                else:
                    dict[sum_ab] = 1

        for c in C:
            for d in D:
                need = -c - d
                if need in dict:
                    count = count + dict[need]

        return count


if __name__ == '__main__':
    A = [1, 2]
    B = [-2, -1]
    C = [-1, 2]
    D = [0, 2]

    assert (Solution().fourSumCount(A, B, C, D) == 2)
