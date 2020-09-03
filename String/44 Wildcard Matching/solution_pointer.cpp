/*
 *
 * [44] Wildcard Matching
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s = s.size();
        int len_p = p.size();
        int sptr = 0;
        int pptr = 0;
        int sStar = -1;
        int pStar = -1;

        while (sptr < len_s)
        {
            if (pptr < len_p && (s[sptr] == p[pptr] || p[pptr] == '?')) {
                pptr++;
                sptr++;
            } else if (pptr < len_p && p[pptr] == '*') {
                sStar = sptr;
                pStar = pptr;
                pptr++;     // not sptr++, as pptr may match empty
            } else if (sStar >= 0) {
                sStar++;
                sptr = sStar;
                pptr = pStar + 1;
            } else {
                return false;
            }
        }

        while (pptr < len_p && p[pptr] == '*') pptr++;
        
        return (pptr == len_p);
    }
};