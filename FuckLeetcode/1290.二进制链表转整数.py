#
# @lc app=leetcode.cn id=1290 lang=python3
#
# [1290] 二进制链表转整数
#
from util import ListNode
# @lc code=start
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        t_ptr = head
        ans = 0
        while t_ptr is not None:
            t = t_ptr.val
            ans <<= 1
            ans |= t
            t_ptr = t_ptr.next
        return ans
# @lc code=end