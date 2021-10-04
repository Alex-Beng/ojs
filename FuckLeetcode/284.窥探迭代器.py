class PeekingIterator:
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.inter = iterator
        self.cache = iterator.next()

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        return self.cache
        

    def next(self):
        """
        :rtype: int
        """
        if self.cache != -100000:
            t = self.cache
            self.cache = self.inter.next()
            return t
        

    def hasNext(self):
        """
        :rtype: bool
        """
        print(self.cache)
        return self.inter.hasNext() or self.cache != -100000
