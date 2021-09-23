#
# @lc app=leetcode.cn id=430 lang=python3
#
# [430] 扁平化多级双向链表
#
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
# @lc code=start

class Solution:
    def flatten(self, head: 'Node') -> 'Node':

        def flat(head: Node):
            tail = head
            while tail is not None:
                if tail.child is not None:
                    c_tail = flat(tail.child)
                    c_tail.next = tail.next
                    if tail.next is not None:
                        tail.next.prev = c_tail
                    tail.next = tail.child
                    tail.child.prev = tail
                    tail.child = None
                    tail = c_tail
                
                if tail.next is None:
                    return tail
                else:
                    tail = tail.next
        flat(head)
            # return tail
        return head

# @lc code=end

