#
# @lc app=leetcode.cn id=986 lang=python3
#
# [986] 区间列表的交集
#

# @lc code=start
class Solution:
    def intervalIntersection(self, firstList: [[int]], secondList: [[int]]) -> [[int]]:
        def inter(rg1, rg2):
            l = max(rg1[0], rg2[0])
            r = min(rg1[1], rg2[1])
            if l>r:
                return False, None
            else:
                return True, [l,r]
        n1 = len(firstList)
        n2 = len(secondList)
        i = 0
        j = 0
        ans = []
        while i<n1 and j<n2:
            rg1 = firstList[i]
            rg2 = secondList[j]

            valid, it_rg = inter(rg1, rg2)
            if valid:
                ans.append(it_rg)
            
            if rg1[1] > rg2[1]:
                j += 1
            elif rg1[1] < rg2[1]:
                i += 1
            else:
                i += 1
                j += 1

        return ans
        
# @lc code=end

