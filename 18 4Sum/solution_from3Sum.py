class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        # a, b, c, d,
        solution = []
        nums.sort()
        length = len(nums)

        if length < 4:
            return solution

        a = 0
        while a < length - 2:
            nums_a = nums[a]

            if nums_a == nums[a - 1] and a > 0:
                a = a + 1
            else:
                sum_three = target - nums_a
                # find the other three b=a+1
                self.threeSum(nums_a, nums[a + 1:], sum_three, solution)

                a = a + 1

        return solution

    def threeSum(self, num, nums, target0, solution):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # i<m<n, i<=target0, n>=target0

        length = len(nums)

        i = 0
        while i < length - 1 and length >= 3:

            if nums[i] == nums[i - 1] and i > 0:
                i = i + 1
            else:
                need_sum = target0 - nums[i]

                m, n = i + 1, length - 1

                while m < n:
                    real_sum = nums[m] + nums[n]
                    if nums[m] == nums[m - 1] and m > i + 1:
                        m = m + 1
                    elif real_sum == need_sum:
                        solution.append([num, nums[i], nums[m], nums[n]])
                        m, n = m + 1, n - 1
                    elif real_sum < need_sum:
                        m = m + 1
                    else:
                        n = n - 1
                i = i + 1

                """
                # out of time
                for m in range(i+1,length-1):
                    need_ele = need_sum - nums[m] # should be the biggest
                    if need_ele < nums[m] or need_ele < 0:
                        break
                    elif nums[m] == nums[m-1] and m > i+1:
                        continue
                    elif need_ele in nums[m+1:]:
                        solution0 = [nums[i], nums[m], need_ele]
                        solution.append(solution0)
                i = i+1
                """
        return solution

if __name__ == '__main__':
    nums = [1, 0, -1, 0, -2, 2]
    target = 0

    print(Solution().fourSum(nums, target))
    print("Solution:")
    print("[[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]")