# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
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

class Solution:
    def mergeKLists(self, lists: [ListNode]) -> ListNode:
        res_head = ListNode(-1)
        res_tail = res_head

        head_ptrs = []
        for link_head in lists:
            if link_head is not None:
                head_ptrs.append(link_head)
        
        while len(head_ptrs):
            # heads = [(head_ptrs[i].val, i) for i in range(len(head_ptrs))]
            # heads.sort(key=lambda k: k[0])

            t_idx = sorted( list(range(len(head_ptrs))), key=lambda k: head_ptrs[k].val )[0]

            res_tail.next = head_ptrs[t_idx]
            res_tail = res_tail.next
            
            head_ptrs[t_idx] = head_ptrs[t_idx].next
            if head_ptrs[t_idx] is None:
                del head_ptrs[t_idx]

        return res_head.next


s = Solution()

l1 = make_link([1,4,5])
l2 = make_link([1,3,4])
l3 = make_link([2,6])


res = s.mergeKLists([None])
print_link(res)

