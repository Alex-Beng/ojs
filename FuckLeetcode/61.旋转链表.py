from util import *

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        n = 0
        t_ptr = head
        while t_ptr is not None:
            t_ptr = t_ptr.next
            n += 1

        if n==0 or n==1:
            return head

        k %= n
        if k==0:
            return head

        fast = head
        slow = head
        for i in range(k):
            fast = fast.next
        
        while fast.next is not None:
            fast = fast.next
            slow = slow.next
        
        new_head = slow.next
        slow.next = None
        fast.next = head

        return new_head
        

lk = make_link([1,2])
s = Solution()
s.rotateRight(lk, 0)
