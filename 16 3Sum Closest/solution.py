class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        length = len(nums)
        # val = abs(sum-target)
        # dict: {val:sum}
        # i, m, n
        dict = {}
        sum = nums[0] + nums[1] + nums[2]
        val = abs(sum - target)
        dict[val] = sum

        i = 0
        while i < length - 2 and val != 0:
            m, n = i + 1, length - 1

            while m < n and val != 0:
                sum = nums[i] + nums[m] + nums[n]
                if sum == target:
                    val = 0
                    dict[0] = target
                    break
                elif sum < target:
                    m = m + 1
                    dict[target - sum] = sum
                    val = min(val, target - sum)
                else:
                    n = n - 1
                    dict[sum - target] = sum
                    val = min(val, sum - target)
            i = i + 1

        return dict[val]

if __name__ == '__main__':
    nums = [-1, 2, 1, -4]
    target = 1.

    assert(Solution().threeSumClosest(nums, target) == 2)