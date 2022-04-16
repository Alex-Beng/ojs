from util import *

class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        n_head = ListNode()
        n_head.next = head

        if left==right:
            return head

        l_ptr = n_head
        for _ in range(left-1):
            l_ptr = l_ptr.next
        tt_ptr = l_ptr.next
        for _ in range(right-left):
            mv_ptr = tt_ptr.next
            tt_ptr.next = mv_ptr.next
            
            mv_ptr.next = l_ptr.next
            l_ptr.next = mv_ptr


        return n_head.next

s = Solution()
s.reverseBetween(
    make_link([1,2,3,4,5]),
    2,
    4
)