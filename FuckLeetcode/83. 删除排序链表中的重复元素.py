from util import *
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        # nhead = ListNode(-1, head)
        def delete():
            nonlocal head

            t_ptr = head
            while t_ptr is not None:
                while True:
                    n_ptr = t_ptr.next
                    if n_ptr is None:
                        return
                
                    if n_ptr.val == t_ptr.val:
                        t_ptr.next = n_ptr.next
                        del n_ptr
                    else:
                        break
                t_ptr = t_ptr.next
        delete()
        return head
s = Solution()
ya = make_link([1,1,1, 7,7 ])
ya = s.deleteDuplicates(ya)
print_link(ya)
