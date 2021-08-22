from util import ListNode, make_link, print_link

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        nhead = ListNode(-1, head)
        curr_ptr = nhead
        
        while curr_ptr is not None:
            # print_link(nhead)

            curr_tail = curr_ptr
            
            reverse = True
            for _ in range(k):
                curr_tail = curr_tail.next
                if curr_tail is None:
                    reverse = False
                    break
            next_head = curr_ptr.next
            if reverse:
                # 我傻了，怎么翻转
                for _ in range(k-1):
                    t = curr_ptr.next
                    curr_ptr.next = t.next
                    t.next = curr_tail.next
                    curr_tail.next = t
                # print_link(nhead)
            else:
                break

            curr_ptr = next_head
        return nhead.next

                
s = Solution()

ya = make_link([1,2,3,4,5])
yaya = s.reverseKGroup(
    ya, 2
)
print_link(yaya)