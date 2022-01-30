#
# @lc app=leetcode.cn id=884 lang=python3
#
# [884] 两句话中的不常见单词
#

# @lc code=start
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        wd2ts1 = dict()
        wd2ts2 = dict()
        for wd in s1.split(' '):
            wd2ts1[wd] = wd2ts1.get(wd, 0) + 1
        for wd in s2.split(' '):
            wd2ts2[wd] = wd2ts2.get(wd, 0) + 1
        ans = set()
        for wd, ts in wd2ts1.items():
            if wd not in wd2ts2 and ts==1:
                ans.add(wd)
        for wd, ts in wd2ts2.items():
            if wd not in wd2ts1 and ts==1:
                ans.add(wd)
        return list(ans)
            
# @lc code=end