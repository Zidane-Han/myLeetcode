class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums:
            return []

        val = [[]]
        count = 0
        for num in sorted(nums):
            # plus ele to the avialble subsets in the list
            val = val + self.duplicated(num, val)
        return val

    def duplicated(self, num, val):
        list0 = []
        for value in val:
            value = value + [num]
            list0.append(value)

        return list0


if __name__ == '__main__':
    nums = [1, 2, 3]

    result = [[3],
              [1],
              [2],
              [1, 2, 3],
              [1, 3],
              [2, 3],
              [1, 2],
              []]

    print(Solution().subsets(nums))
    print(result)