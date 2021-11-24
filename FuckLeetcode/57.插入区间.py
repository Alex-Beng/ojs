#
# @lc app=leetcode.cn id=57 lang=python3
#
# [57] 插入区间
#

# @lc code=start
class Solution:
    def insert(self, intervals: [[int]], newInterval: [int]) -> [[int]]:
        n = len(intervals)
        L = 0
        R = n-1
        while L<=R:
            m = (L+R)//2
            m_rg = intervals[m]
            if m_rg[0] <= newInterval[0]:
                L = m+1
            else:
                R = m-1
        intervals.insert(L, newInterval)

        # 尝试与前面的合并
        if L-1 >= 0:
            if intervals[L-1][0] <= newInterval[0] <= intervals[L-1][1]:
                intervals[L-1][1] = max(newInterval[1], intervals[L-1][1])
                del intervals[L]
                L -= 1
        # 尝试与后面的合并
        while L+1 < len(intervals) and intervals[L][0] <= intervals[L+1][0] <= intervals[L][1]:
            intervals[L][1] = max(intervals[L+1][1], intervals[L][1])
            del intervals[L+1]
        return intervals
# @lc code=end
s = Solution()
s.insert(
    [[1,2],[3,5],[6,7],[8,10],[12,16]], [4,8]
)