from util import *

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        new_head = ListNode()
        new_head.next = head
        head = new_head

        small_head = None
        small_tail = None
        large_head = None

        t_ptr = head
        while t_ptr.next is not None:
            # print_link(small_head)
            # print_link(large_head)
            if t_ptr.next.val < x:
                if small_head is None:
                    small_head = t_ptr.next
                    small_tail = t_ptr.next
                else:
                    small_tail.next = t_ptr.next
                    small_tail = small_tail.next
                t_ptr.next = t_ptr.next.next
                small_tail.next = None
                continue
            else:
                if large_head is None:
                    large_head = t_ptr.next
                t_ptr = t_ptr.next
        if small_tail is not None:
            small_tail.next = large_head
        
        return small_head if small_head is not None else large_head

s = Solution()
h = s.partition(
    make_link([1,4,3,2,5,2]), 3
)
print_link(h)