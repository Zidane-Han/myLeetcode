class Solution:
    def totalHammingDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum((b.count('0') * b.count('1')) for b in zip(*map('{:032b}'.format, nums)))


if __name__ == '__main__':
    nums = [4, 14, 2]

    assert(Solution().totalHammingDistance(nums) == 6)