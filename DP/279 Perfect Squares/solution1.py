class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        res = n
        for i in range(2, int(math.sqrt(n)) + 1):
            a = n // (i * i)
            b = n % (i * i)
            res = min(res, a + self.numSquares(b))
        
        return res

    
if __name__ == '__main__':

    assert (Solution().numSquares(12) == 3)

    assert (Solution().numSquares(13) == 2)
