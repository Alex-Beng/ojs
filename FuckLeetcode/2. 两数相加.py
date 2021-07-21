# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        l1_ptr = l1
        l2_ptr = l2
        res_ptr = None
        res_head = None
        carry_in = 0
        while True:
            l1_val = 0 if l1_ptr is None else l1_ptr.val
            l2_val = 0 if l2_ptr is None else l2_ptr.val
            t_sum = l1_val + l2_val + carry_in
            
            t_node = ListNode(t_sum%10)
            carry_in = t_sum//10
            if res_ptr is None:
                res_ptr = t_node
                res_head = t_node
            else:
                res_ptr.next = t_node
                res_ptr = res_ptr.next
            l1_ptr = l1_ptr.next if not l1_ptr is None else l1_ptr
            l2_ptr = l2_ptr.next if not l2_ptr is None else l2_ptr
            if l1_ptr is None and l2_ptr is None and carry_in == 0:
                break
        return res_head
            

            
