class Solution(object):
    def canAttendMeetings(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: bool
        """
        length = len(intervals)
        intervals.sort(key=lambda x: x[0])

        for i in range(1, length):
            if intervals[i][0] < intervals[i - 1][1]:
                return False

        return True


if __name__ == '__main__':
    intervals = [[0, 30], [5, 10], [15, 20]]
    assert(Solution().canAttendMeetings(intervals) == False)

    intervals = [[7, 10], [2, 4]]
    assert(Solution().canAttendMeetings(intervals) == True)