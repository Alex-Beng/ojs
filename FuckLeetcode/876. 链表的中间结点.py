from util import *
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        nhead = ListNode(-1, head)
        t_ptr = nhead
        n = 0
        while t_ptr.next is not None:
            t_ptr = t_ptr.next
            n += 1
        mid = (n+1)//2 if n&1==1 else (n+1)//2+1
        t_ptr = nhead
        for i in range(mid):
            t_ptr = t_ptr.next
        
        # print_link(t_ptr)
        return t_ptr
s = Solution()
ya = make_link([1,2,3,4])
s.middleNode(ya)