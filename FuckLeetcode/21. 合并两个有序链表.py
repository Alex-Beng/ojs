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
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        res_head = ListNode(-1)

        t_ptr1 = l1
        t_ptr2 = l2
        t_res_ptr = res_head
        while t_ptr1 is not None and t_ptr2 is not None:
            # t_ptr1 = t_ptr1.next
            # t_ptr2 = t_ptr2.next
            print(t_ptr1, t_ptr2.val)
            if t_ptr1 is None or t_ptr2 is None:
                break

            if t_ptr1.val > t_ptr2.val:
                t_res_ptr.next = t_ptr2
                t_res_ptr = t_res_ptr.next
                t_ptr2 = t_ptr2.next
            elif t_ptr1.val < t_ptr2.val:
                t_res_ptr.next = t_ptr1
                t_res_ptr = t_res_ptr.next
                t_ptr1 = t_ptr1.next
            else:
                t_res_ptr.next = t_ptr2
                t_res_ptr = t_res_ptr.next
                t_ptr2 = t_ptr2.next

                t_res_ptr.next = t_ptr1
                t_res_ptr = t_res_ptr.next
                t_ptr1 = t_ptr1.next
        while t_ptr1 is not None:
            t_res_ptr.next = t_ptr1
            t_res_ptr = t_res_ptr.next
            t_ptr1 = t_ptr1.next
        while t_ptr2 is not None:
            t_res_ptr.next = t_ptr2
            t_res_ptr = t_res_ptr.next
            t_ptr2 = t_ptr2.next
        return res_head.next

s = Solution()

a = [0]
ya = []
for i in a:
    ya.append(ListNode(i))
for i in range(0, len(ya)-1):
    ya[i].next = ya[i+1]

l1 = ya[0]
print_link(l1)


a = [1,]
ya = []
for i in a:
    ya.append(ListNode(i))
for i in range(0, len(ya)-1):
    ya[i].next = ya[i+1]

l2 = ya[0]
print_link(l2)

res = s.mergeTwoLists(
    # l1, l2
    None, l2
)

print(res)
print_link(res)