# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        a_ptr = headA
        b_ptr = headB

        while True:
            if a_ptr is None and b_ptr is None:
                return None
            if a_ptr == b_ptr:
                return a_ptr

            if a_ptr is None:
                a_ptr = headB
            else:
                a_ptr = a_ptr.next
            
            if b_ptr is None:
                b_ptr = headA
            else:
                b_ptr = b_ptr.next
        
            
            