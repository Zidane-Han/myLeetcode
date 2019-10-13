class Solution:
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # + or - must be initial
        # . appear only once
        # refraction ??
        # delete left & right space
        s = s.lstrip()
        s = s.rstrip()

        if len(s) == 0 or s != s.strip():
            return False

        # no space below
        s_list = list(s)

        if s_list[0] in ["-", "+"]:
            del s_list[0]
            if len(s_list) == 0:
                return False

        i = 0
        digit_flag = False
        e_flag = False
        dot_flag = False
        sign_flag = False

        while i < len(s_list):
            xx = s_list[i]
            if xx.isdigit():
                i = i + 1
                digit_flag = True
            elif xx == "e" and digit_flag and not e_flag:
                i = i + 1
                e_flag = True
                digit_flag = False
                dot_flag = True
                sign_flag = False
            elif xx == "." and not dot_flag:
                i = i + 1
                dot_flag = True
                sign_flag = True
            elif xx in ["+", "-"] and not sign_flag and not digit_flag:
                i = i + 1
                sign_flag = True
            else:
                return False

        if digit_flag:
            return True
        else:
            return False


if __name__ == '__main__':

    s = "0"
    assert(Solution().isNumber(s) == True)

    s = " 0.1"
    assert(Solution().isNumber(s) == True)

    s = "abc"
    assert(Solution().isNumber(s) == False)

    s = "2e10"
    assert(Solution().isNumber(s) == True)

    s = " -90e3"
    assert(Solution().isNumber(s) == True)

    s = "53.5e93"
    assert(Solution().isNumber(s) == True)

    s = "95a54e53"
    assert(Solution().isNumber(s) == False)

    ## problem with these two cases
    s = " --6"
    assert (Solution().isNumber(s) == False)
    s = "-+3"
    assert (Solution().isNumber(s) == False)
