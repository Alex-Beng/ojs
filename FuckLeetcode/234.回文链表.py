#
# @lc app=leetcode.cn id=234 lang=python3
#
# [234] 回文链表
#
from util import ListNode
# @lc code=start
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        tptr = head
        nums = []
        while tptr is not None:
            nums.append(tptr.val)
            tptr = tptr.next
        n = len(nums)
        for i in range(n):
            if nums[i] != nums[-i-1]:
                return False
        return True
# @lc code=end

