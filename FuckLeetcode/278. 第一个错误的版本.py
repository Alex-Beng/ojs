# The isBadVersion API is already defined for you.
# @param version, an integer
# @return an integer
# def isBadVersion(version):
def isBadVersion(t):
    import random
    return random.choice([True, False])

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        L = 1
        R = n
        ans = -1
        while L<=R:
            m = (L+R)//2
            if isBadVersion(m):
                ans = m
                R = m-1
            else:
                L = m+1
        return ans