from util import *
class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        slow_ptr = fast_ptr = head
        
        for _ in range(k):
            if fast_ptr is None:
                return None
            fast_ptr = fast_ptr.next

        while fast_ptr is not None:
            fast_ptr = fast_ptr.next
            slow_ptr = slow_ptr.next

        return slow_ptr
s = Solution()
ya = make_link([1,2,3,4,5])
ya = s.getKthFromEnd(ya, 2)
print_link(ya)