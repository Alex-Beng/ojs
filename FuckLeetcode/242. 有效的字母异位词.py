from collections import Counter

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s)==Counter(t)
        if len(s)!=len(t):
            return False
        n = len(s)
        cnts = [0]*26
        for i in range(n):
            cnts[ord(s[i])-ord('a')] += 1
            cnts[ord(t[i])-ord('a')] -= 1
        return sum([abs(i) for i in cnts])==0
    
s = Solution()
print(s.isAnagram(
    # "rat", "cat"
    "anagram", "nagaram"
))