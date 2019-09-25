class Solution(object):
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """

        intervals.sort(key=lambda x: x[0])

        if not intervals:
            return 0

        rooms = [intervals[0][1]]  # list of end times

        for i in range(1, len(intervals)):
            rooms.sort()
            if intervals[i][0] < rooms[0]:
                rooms.append(intervals[i][1])
            else:
                rooms[0] = intervals[i][1]

        return len(rooms)


if __name__ == '__main__':
    intervals = [[0,30],[5,10],[15,20]]
    assert(Solution().minMeetingRooms(intervals) == 2)

    intervals = [[7,10],[2,4]]
    assert(Solution().minMeetingRooms(intervals) == 1)