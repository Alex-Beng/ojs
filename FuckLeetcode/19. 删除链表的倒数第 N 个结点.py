# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def print_link(t_ptr):
    while t_ptr is not None:
        print(t_ptr.val, end=' ')
        t_ptr = t_ptr.next
    print()


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        slow_ptr = fast_ptr = head
        
        for _ in range(n):
            fast_ptr = fast_ptr.next

        while fast_ptr is not None and fast_ptr.next is not None:
            fast_ptr = fast_ptr.next
            slow_ptr = slow_ptr.next
        print_link(fast_ptr)
        print_link(slow_ptr)
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




        
        