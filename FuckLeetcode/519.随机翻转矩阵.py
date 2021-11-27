import random

class Solution:

    def __init__(self, m: int, n: int):
        self.m = m
        self.n = n
        self.total = m*n
        self.map = dict()

    def flip(self) -> [int]:
        x = random.randint(0, self.total-1)
        if x in self.map:
            idx = self.map[x]
        else:
            idx = x
        self.total -= 1
        if self.total in self.map:
            self.map[x] = self.map[self.total]
        else:
            self.map[x] = self.total
        return [idx//self.n, idx%self.n]


    def reset(self) -> None:
        m = self.m
        n = self.n
        self.total = m*n
        self.map.clear()

ops = ["Solution", "flip", "flip", "flip", "reset", "flip"]
args = [[3, 1], [], [], [], [], []]
exps = [None, [1, 0], [2, 0], [0, 0], None, [2, 0]]
