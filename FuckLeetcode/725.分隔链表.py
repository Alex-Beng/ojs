#
# @lc app=leetcode.cn id=725 lang=python3
#
# [725] 分隔链表
#
from util import ListNode, make_link
# @lc code=start
from copy import deepcopy
class Solution:
    def splitListToParts(self, head: ListNode, k: int) -> [ListNode]:
        n = 0
        tptr = head
        while tptr is not None:
            n += 1
            tptr = tptr.next
        if not n:
            return [None]*k
        lens = [n//k]*k
        for i in range(n%k):
            lens[i] += 1
        hts = [[head]*2 if i==0 else [None]*2 for i in range(k)]

        for j in range(lens[0]-1):
            hts[0][1] = hts[0][1].next
            if hts[0][1] is None:
                return [i[0] for i in hts]
        # print(hts)
        for i in range(1, k):
            hts[i][0] = hts[i-1][1].next
            hts[i-1][1].next = None

            if hts[i][0] is None:
                return [i[0] for i in hts]

            hts[i][1] = hts[i][0]
            for j in range(lens[i]-1):
                hts[i][1] = hts[i][1].next
            
        # print(lens)
        return [i[0] for i in hts]
        
                
# @lc code=end

s = Solution()
res = s.splitListToParts(make_link([1,2,3,4,5,6,7,8,9,10]), 3)
