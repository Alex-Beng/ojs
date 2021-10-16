#
# @lc app=leetcode.cn id=148 lang=python3
#
# [148] 排序链表
#

from util import ListNode,make_link,print_link

# @lc code=start

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        def merge(h1: ListNode, h2: ListNode) -> ListNode:
            if h1 is None and h2 is None:
                return None
            if h1 is None:
                return h2
            if h2 is None:
                return h1
            t1 = h1
            t2 = h2
            if h1.val < h2.val:
                ans = h1
                t1 = t1.next
            else:
                ans = h2
                t2 = t2.next
            t3 = ans
            while t1 is not None and t2 is not None:
                if t1.val < t2.val:
                    t3.next = t1
                    t1 = t1.next
                    t3 = t3.next
                    t3.next = None
                else:
                    t3.next = t2
                    t2 = t2.next
                    t3 = t3.next
                    t3.next = None
            while t1 is not None:
                t3.next = t1
                t1 = t1.next
                t3 = t3.next
                t3.next = None
            while t2 is not None:
                t3.next = t2
                t2 = t2.next
                t3 = t3.next
                t3.next = None
            return ans
        def merge_sort(node: ListNode) -> ListNode:
            if node is None:
                return None
            if node.next is None:
                return node
            nnode = ListNode(-1, node)
            t1 = nnode
            t2 = nnode
            while t2 is not None and t2.next is not None:
                t1 = t1.next
                t2 = t2.next
                t2 = t2.next
            t = t1
            t1 = t1.next
            t.next = None

            # print_link(node)
            # print_link(t1)

            h1 = merge_sort(node)
            h2 = merge_sort(t1)
            # print_link(h1)
            # print_link(h2)
            return merge(h1, h2)
        return merge_sort(head)
# @lc code=end

ya = make_link(
    [-1,5,3,4,0]

)
s = Solution()
r = s.sortList(ya)
print_link(r)