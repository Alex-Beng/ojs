#
# @lc app=leetcode.cn id=160 lang=python3
#
# [160] 相交链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        lenA = 0
        lenB = 0
        t_ptr = headA
        while t_ptr is not None:
            t_ptr = t_ptr.next
            lenA += 1
        t_ptr = headB

        while t_ptr is not None:
            t_ptr = t_ptr.next
            lenB += 1
        
        if lenB > lenA:
            headA, headB = headB, headA
            lenA, lenB = lenB, lenA
        
        delta = lenA-lenB
        ptrA = headA
        ptrB = headB
        for _ in range(delta):
            ptrA = ptrA.next
        while ptrA != ptrB:
            ptrA = ptrA.next
            ptrB = ptrB.next
        return ptrA
        
# @lc code=end

