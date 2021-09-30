#
# @lc app=leetcode.cn id=228 lang=python3
#
# [228] 汇总区间
#

# @lc code=start
class Solution:
    def summaryRanges(self, nums: [int]) -> [str]:
        n = len(nums)
        if not n:
            return []
        ans = [[nums[0]]]
        for i in range(1, n):
            t = nums[i]
            # merge
            if t==ans[-1][-1]+1:
                if len(ans[-1])==1:
                    ans[-1].append(t)
                else:
                    ans[-1][-1] = t
            # new
            else:
                ans.append([t])
        ans = [f"{i[0]}->{i[1]}" if len(i)==2 else f"{i[0]}" for i in ans]
        print(ans)
        return ans
# @lc code=end

