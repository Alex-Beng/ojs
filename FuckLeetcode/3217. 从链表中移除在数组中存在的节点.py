# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from util import ListNode, make_link

from typing import Optional

class Solution:
    def modifiedList(self, nums: 'List[int]', head: 'Optional[ListNode]') -> 'Optional[ListNode]':
        nums = set(nums)

        real_head = ListNode(next=head)
        t_ptr = real_head

        while t_ptr and t_ptr.next != None:
            while t_ptr.next and t_ptr.next.val in nums:
                t_ptr.next = t_ptr.next.next
            t_ptr = t_ptr.next

        return real_head.next


INPUT = [
    ([1, 2, 3], make_link([1,2,3,4,5]))
]