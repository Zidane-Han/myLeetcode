class Solution(object):
    def shortestSubarray(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        res = -1
        length = len(A)
        nums = [0] * (length + 1)
        tmp = 0
        for i in range(length):
            tmp += A[i]
            nums[i + 1] = tmp

        for i in range(length):
            for j in range(i + 1, length + 1):
                tmp_len = j - i
                if 0 < res < tmp_len:
                    break
                if nums[j] - nums[i] >= K:
                    if res < 0:
                        res = tmp_len
                    else:
                        res = min(res, tmp_len)

        return res


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