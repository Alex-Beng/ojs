#
# @lc app=leetcode.cn id=146 lang=python3
#
# [146] LRU 缓存机制
#

# @lc code=start


def print_link(t_ptr, cap):
    for i in range(cap):
        print(f'{t_ptr.pre.val}->{t_ptr.val}->{t_ptr.nex.val}', end=' ')
        t_ptr = t_ptr.nex
    print('\t')
    for i in range(cap):
        print(f'{t_ptr.pre.val}->{t_ptr.val}->{t_ptr.nex.val}', end=' ')
        t_ptr = t_ptr.nex
    print()



class ListNode:
    def __init__(self, val, pre=None, nex=None):
        self.val = val
        self.pre = pre
        self.nex = nex

class RingList:
    def __init__(self, cap):
        head = t = ListNode(0)
        head.nex = head
        head.pre = None
        for i in range(cap-1):
            tn = ListNode(0)
            tn.nex = t.nex
            t.nex = tn
            tn.pre = t
            tn.nex.pre = tn

            t = tn
        head.pre = t
        self.head = head
class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.keys = RingList(capacity)
        self.key2val = dict()
        self.key2node = dict()

    def update_node(self, node: ListNode):
        if node == self.keys.head:
            return 
        node.pre.nex = node.nex
        node.nex.pre = node.pre

        node.pre = self.keys.head.pre
        node.pre.nex = node
        node.nex = self.keys.head
        self.keys.head.pre = node
        self.keys.head = node


    def get(self, key: int) -> int:
        if key in self.key2val:
            val = self.key2val[key]
            
            node = self.key2node[key]
            self.update_node(node)

            return val
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if key not in self.key2val:
            # 满了要删
            if len(self.key2val) == self.cap:
                del_k = self.keys.head.pre.val
                del self.key2val[del_k]
                del self.key2node[del_k]

            self.key2val[key] = value
    
            self.keys.head = self.keys.head.pre
            self.keys.head.val = key
            self.key2node[key] = self.keys.head
        else:
            self.key2val[key] = value

            node = self.key2node[key]
            self.update_node(node)


# @lc code=end


ops = ["LRUCache","put","put","get","put","get","put","get","get","get"]
args = [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]

ops = ["LRUCache","get","put","get","put","put","get","get"]
args = [[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]

for i in range(len(ops)):
    op = ops[i]
    arg = args[i]
    print(op, arg)
    if op == "put":
        r = t.put(arg[0], arg[1])
    elif op == "get":
        r = t.get(arg[0])
    elif op == "LRUCache":
        t = LRUCache(arg[0])
        r = ''
    print(t.key2val)
    print_link(t.keys.head, t.cap)
    print(r)
    print()

