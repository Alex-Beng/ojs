# Definition for singly-linked list.
from util import *

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        slow_ptr = fast_ptr = head
        
        for _ in range(n):
            fast_ptr = fast_ptr.next

        while fast_ptr is not None and fast_ptr.next is not None:
            fast_ptr = fast_ptr.next
            slow_ptr = slow_ptr.next
        if fast_ptr is None:# to del head
            t = head
            head = head.next
            del t
            return head

        t = slow_ptr.next
        slow_ptr.next = t.next 
        del t

        return head

s = Solution()

a = [1,2,3,4,5]
ya = []
for i in a:
    ya.append(ListNode(i))
for i in range(0, len(ya)-1):
    ya[i].next = ya[i+1]


print_link(ya[0])

# exit()

ttt = s.removeNthFromEnd(
    ya[0], 2
)

print_link(ttt)




        
        