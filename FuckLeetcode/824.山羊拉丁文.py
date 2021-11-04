#
# @lc app=leetcode.cn id=824 lang=python3
#
# [824] 山羊拉丁文
#

# @lc code=start
class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        yy = {'a','e','i','o','u'}

        wds = sentence.split(' ')
        for i,wd in enumerate(wds):
            wds[i] = f"{wd+'ma' if wd[0].lower() in yy else wd[1:]+wd[0]+'ma'}{'a'*(i+1)}"
        return ' '.join(wds)
# @lc code=end

