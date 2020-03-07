class Solution:
    def fourSum(self, nums, target):
        two_sums = {}
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if (target - nums[i] - nums[j]) in two_sums:
                    two_sums[target - nums[i] - nums[j]].append([i, j])
                else:
                    two_sums[target - nums[i] - nums[j]] = [[i, j]]

        four_sums = []
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                temp = nums[i] + nums[j]
                if temp in two_sums:
                    for twos in two_sums[temp]:
                        if not (twos[0] == i or
                                twos[0] == j or
                                twos[1] == i or
                                twos[1] == j):
                            four_sums.append([nums[i], nums[j], nums[twos[0]], nums[twos[1]]])

        return sorted(list(set(map(lambda x: tuple(sorted(x)), four_sums))))

if __name__ == '__main__':
    nums = [1, 0, -1, 0, -2, 2]
    target = 0

    print(Solution().fourSum(nums, target))
    print("Solution:")
    print("[[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]")