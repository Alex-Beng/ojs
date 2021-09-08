from util import *

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        def merge(l1: ListNode, l2: ListNode) -> ListNode:
            if l1 is None:
                return l2
            elif l2 is None:
                return l1
            
            if l1.val<l2.val:
                head = l1
                head.next = merge(l1.next, l2)
            else:
                head = l2
                head.next = merge(l1, l2.next)
            return head
        return merge(l1, l2)
l1 = make_link([1,2,4])
l1 = None
l2 = make_link([1,3,4])
# l2 = None
s = Solution()
res = s.mergeTwoLists(l1, l2)
print_link(res)
            