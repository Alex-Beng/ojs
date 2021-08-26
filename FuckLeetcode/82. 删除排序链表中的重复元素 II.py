from util import *
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        nhead = ListNode(2333, head)
        t_ptr = nhead
        
        while True:
            # new val
            if t_ptr.next is not None:
                dup_beg = t_ptr
                t_ptr = t_ptr.next
                # check duplicates
                if t_ptr.next is None:
                    break

                if t_ptr.next.val == t_ptr.val:
                    dup_end = t_ptr
                    while dup_end.next is not None and dup_end.next.val == t_ptr.val:
                        dup_end = dup_end.next
                    dup_beg.next = dup_end.next
                    
                    del_ptr = t_ptr
                    while del_ptr!=dup_end:
                        ttt = del_ptr
                        del_ptr = del_ptr.next
                        del ttt
                    del del_ptr
                    t_ptr = dup_beg
                else:
                    continue
            else:
                break
        return nhead.next
s = Solution()
ya = make_link([1,3,3,3,3,6, 9, 4,4,4,5,7,7,7,])
ya = s.deleteDuplicates(
    ya
)
print_link(ya)