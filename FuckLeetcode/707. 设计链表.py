class MyLinkListNode:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = MyLinkListNode(-1)
        self.tail = self.head
        self.n = 0

    def print(self, head):
        t_ptr = head
        while t_ptr is not None:
            print(t_ptr.val, end=" ")
            t_ptr = t_ptr.next
        print(f'cao{self.tail.val} {self.n}')

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if index >= self.n or index < 0:
            return -1
        
        t_ptr = self.head
        for i in range(index+1):
            t_ptr = t_ptr.next
        return t_ptr.val


    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        new_node = MyLinkListNode(val, self.head.next)
        self.head.next = new_node
        self.n += 1
        if self.head == self.tail:
            self.tail = new_node

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        new_node = MyLinkListNode(val, self.tail.next)
        self.tail.next = new_node
        self.n += 1

        self.tail = new_node

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. 
        If index equals to the length of linked list, the node will be appended to the end of linked list. 
        If index is greater than the length, the node will not be inserted.
        """
        if index < 0:
            self.addAtHead(val)
            return
        elif index == self.n:
            self.addAtTail(val)
            return
        elif index > self.n:
            return
        t_ptr = self.head
        for i in range(index):
            t_ptr = t_ptr.next
        new_node = MyLinkListNode(val, t_ptr.next)
        t_ptr.next = new_node
        self.n += 1

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if index<0 or index>=self.n:
            return 
        t_ptr = self.head
        for i in range(index):
            t_ptr = t_ptr.next
        del_ptr = t_ptr.next
        t_ptr.next = del_ptr.next
        del del_ptr
        
        if index==self.n-1:
            self.tail = t_ptr
        self.n -= 1

ops = ["MyLinkedList","addAtHead","get","addAtIndex","addAtIndex","deleteAtIndex","addAtHead","addAtHead","deleteAtIndex","addAtIndex","addAtHead","deleteAtIndex"]
args = [[],[9],[1],[1,1],[1,7],[1],[7],[4],[1],[1,4],[2],[5]]

ops = ["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
args = [[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]

# ops = ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
# args = [[],[1],[3],[1,2],[1],[1],[1]]

t = MyLinkedList()

for i in range(len(ops)):
    op = ops[i]
    arg = args[i]
    print(op, arg)
    if op == "MyLinkedList":
        continue
    elif op == "addAtHead":
        t.addAtHead(arg[0])
    elif op == "get":
        ya = t.get(arg[0])
        print(f'get {ya}')
    elif op == "addAtIndex":
        t.addAtIndex(arg[0], arg[1])
    elif op == "addAtTail":
        t.addAtTail(arg[0])
    elif op == "deleteAtIndex":
        t.deleteAtIndex(arg[0])
    t.print(t.head)
