# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        slow = fast = head
        
        while slow is not None and fast is not None:
            slow = slow.next
            if fast.next is not None:
                fast = fast.next.next
            else:
                break

            if slow == fast:
                return True
        return False