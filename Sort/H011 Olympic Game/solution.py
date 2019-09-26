class Solution(object):
    def canAttendMeetings(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: bool
        """
        medal = []
        for i in range(n):
            country, gold, silver, bronze = input()
            temp = [country, int]
            medal.append(temp)
            
        medal.sort(key = lambda x: (-x[1], -x[2], -x[3], x[0]))
        
        res = []
        for item in medal:
            res.append(item[0])
                        
        return res


if __name__ == '__main__':
    intervals = [[0,30],[5,10],[15,20]]
    assert(Solution().canAttendMeetings(intervals) == False)

    intervals = [[7,10],[2,4]]
    assert(Solution().canAttendMeetings(intervals) == True)