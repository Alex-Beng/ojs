#
# @lc app=leetcode.cn id=143 lang=python3
#
# [143] 重排链表
#

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        stack = []
        t_ptr = head
        while t_ptr is not None:
            stack.append(t_ptr)
            t_ptr = t_ptr.next
        
        nhead = ListNode(-1, head)
        curr_tail = nhead
        while len(stack) != 0:
            th = stack[0]
            del stack[0]
            if len(stack) == 0:
                curr_tail.next = th
                th.next = None
                break

            tt = stack[-1]
            del stack[-1]
            curr_tail.next = th
            th.next = tt
            tt.next = None
            curr_tail = tt
        return nhead.next
        

# @lc code=end

