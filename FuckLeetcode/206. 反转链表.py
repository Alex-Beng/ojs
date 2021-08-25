# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from util import *
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        nhead = ListNode(-1, head)
        tail = nhead

        n = 0
        while tail.next is not None:
            tail = tail.next
            n += 1
        
        for _ in range(n-1):
            t_ptr = nhead.next
            nhead.next = t_ptr.next
            t_ptr.next = tail.next
            tail.next = t_ptr
        return nhead.next
ya = make_link([])
s = Solution()
ya = s.reverseList(ya)
print_link(ya)