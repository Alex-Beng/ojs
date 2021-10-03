#
# @lc app=leetcode.cn id=506 lang=python3
#
# [506] 相对名次
#

# @lc code=start
class Solution:
    def findRelativeRanks(self, score: [int]) -> [str]:
        n = len(score)
        rank = sorted(range(n), reverse=True, key=lambda k: score[k])
        ans = [0]*n
        def rank2str(r):
            if r==0:
                return "Gold Medal"
            elif r==1:
                return "Silver Medal"
            elif r==2:
                return "Bronze Medal"
            else:
                return str(r+1)
        for r,i in enumerate(rank):
            ans[i] = rank2str(r)

        return ans
# @lc code=end
s = Solution()
r = s.findRelativeRanks(
    [10,3,8,9,4]
)

print(r)