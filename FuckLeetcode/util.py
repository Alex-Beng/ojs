# LINK LIST
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

# TREE
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right