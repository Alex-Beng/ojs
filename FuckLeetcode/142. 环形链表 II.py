from util import *

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        fast = slow = head
        cross = None

        s_step = 0
        while fast is not None and fast.next is not None:
            s_step += 1
            fast = fast.next.next
            slow = slow.next

            if fast == slow:
                # has loop
                cross = fast
                break
        if cross is None:
            return cross

        fast = head
        slow = slow
        while fast != slow:
            fast = fast.next
            slow = slow.next
        return slow
        

ya = make_link([3,2,0,-1])
# ya.next.next.next.next = ya.next
ya.next.next.next.next = ya.next

s = Solution()
print(s.detectCycle(
    ya
).val)
