# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        n_head = ListNode(-1, head)

        curr_ptr = n_head
        next_ptr = n_head.next

        while next_ptr is not None and next_ptr.next is not None:
            print(curr_ptr.val, next_ptr.val)
            # swap curr.next and next.next
            t = next_ptr.next
            curr_ptr.next.next = t.next
            t.next = next_ptr
            curr_ptr.next = t

            curr_ptr = next_ptr
            next_ptr = curr_ptr.next
        
        return n_head.next

def make_link(nums):
    if len(nums)==0:
        return None
    ya = []
    for i in nums:
        ya.append(ListNode(i))
    for i in range(0, len(ya)-1):
        ya[i].next = ya[i+1]
    return ya[0]

def print_link(t_ptr):
    while t_ptr is not None:
        print(t_ptr.val, end=' ')
        t_ptr = t_ptr.next
    print()
s = Solution()

ya = make_link([1,1,2,2,3,4,5,6,])
ya = s.swapPairs(ya)
print_link(ya)