#
# @lc app=leetcode.cn id=382 lang=python3
#
# [382] 链表随机节点
#
from util import ListNode
# @lc code=start
import random
class Solution:

    def __init__(self, head: Optional[ListNode]):
        self.n = 0
        t = head
        while t is not None:
            self.n += 1
            t = t.next
        self.head = head

    def getRandom(self) -> int:
        step = random.randint(0,self.n-1)
        t_ptr = self.head
        for _ in range(step):
            t_ptr = t_ptr.next
        return t_ptr.val 
# @lc code=end