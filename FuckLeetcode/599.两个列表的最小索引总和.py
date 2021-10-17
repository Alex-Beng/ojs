#
# @lc app=leetcode.cn id=599 lang=python3
#
# [599] 两个列表的最小索引总和
#

# @lc code=start
class Solution:
    def findRestaurant(self, list1: [str], list2: [str]) -> [str]:
        str2idx = dict()
        for i,s in enumerate(list1):
            str2idx[s] = i
        ans_t = float('inf')
        ans_s = ''
        for i,s in enumerate(list2):
            if s in str2idx and i+str2idx[s]<ans_t:
                ans_t = i+str2idx[s]
                ans_s = s
        ans_s = []
        for i,s in enumerate(list2):
            if s in str2idx and i+str2idx[s]==ans_t:
                ans_s.append(s)
        return ans_s

# @lc code=end

