# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

from util import *

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        nhead = ListNode(-1, head)
        l_ptr = nhead
        r_ptr = nhead.next

        while r_ptr is not None:
            if r_ptr.val == val:
                l_ptr.next = r_ptr.next
                del r_ptr
                r_ptr = l_ptr.next
                continue
            l_ptr = r_ptr
            r_ptr = r_ptr.next
        return nhead.next
h = make_link([6,7,8,9,6,6,6,6, 1,2,3,9])
s = Solution()
h = s.removeElements(
    h, 6
)
print_link(h)