
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: Node):
        t_ptr = head
        n_head = None
        n_tail = None
        o2n_map = dict()
        o2n_map[None] = None
        
        while t_ptr is not None:
            t_n_ptr = Node(t_ptr.val)
            o2n_map[t_ptr] = t_n_ptr
            if n_head is None:
                n_head = t_n_ptr
                n_tail = t_n_ptr
            else:
                n_tail.next = t_n_ptr
                n_tail = n_tail.next
            t_ptr = t_ptr.next 

        t_ptr = head
        t_n_ptr = n_head
        while t_ptr is not None:
            t_n_ptr.random = o2n_map[t_ptr.random]
            t_ptr = t_ptr.next
            t_n_ptr = t_n_ptr.next
        return n_head

head = [[7,None],[13,0],[11,4],[10,2],[1,0]]
n0 = Node(7)
n1 = Node(13)
n2 = Node(11)
n3 = Node(10)
n4 = Node(1)

n0.next = n1
n1.next = n2
n2.next = n3
n3.next = n4
n4.next = None

n0.random = None
n1.random = n0
n2.random = n4
n3.random = n2
n4.random = n0

s = Solution()
head = s.copyRandomList(n0)
while head is not None:
    print(head.val, end=" ")
    if head.random is not None:
        print(head.random.val)
    else:
        print("None")
    head = head.next