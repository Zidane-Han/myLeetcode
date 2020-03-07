class Solution(object):
    def shortestSubarray(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        length = len(A)
        nums = [0] * (length + 1)
        for i in range(length):
            nums[i + 1] = nums[i] + A[i]

        res = length + 1
        monoq = []
        for index, item in enumerate(nums):
            while monoq and item <= nums[monoq[-1]]:
                monoq.pop()

            while monoq and item - nums[monoq[0]] >= K:
                res = min(res, index - monoq.pop(0))

            monoq.append(index)

        if res < length + 1:
            return res
        else:
            return -1


if __name__ == '__main__':

    A = [1]
    K = 1
    assert(Solution().shortestSubarray(A, K) == 1)

    A = [1, 2]
    K = 4
    assert (Solution().shortestSubarray(A, K) == -1)

    A = [2, -1, 2]
    K = 3
    assert (Solution().shortestSubarray(A, K) == 3)