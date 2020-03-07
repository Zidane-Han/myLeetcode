import collections

class Solution:
    def fourSum(self, nums, target):
        pairs = collections.defaultdict(list)

        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                pairs[nums[i] + nums[j]].append((i, j))

        res = set()

        for s, ps in pairs.items():
            for a, b in ps:
                if target - s in pairs:
                    for k, v in pairs[target - s]:
                        if a != k and a != v and b != k and b != v:
                            res.add(tuple((sorted([nums[i] for i in [a, b, k, v]]))))
        return res

if __name__ == '__main__':
    nums = [1, 0, -1, 0, -2, 2]
    target = 0

    print(Solution().fourSum(nums, target))
    print("Solution:")
    print("[[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]")