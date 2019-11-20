class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        time = [0] * 26

        for task in tasks:
            time[ord(task) - ord("A")] += 1

        maxTime = max(time)
        numElements = time.count(maxTime)

        return max(len(tasks), (n + 1) * (maxTime - 1) + numElements)


if __name__ == '__main__':

    tasks = ["A", "A", "A", "B", "B", "B"]
    n = 2

    assert (Solution().leastInterval(tasks, n) == 8)
