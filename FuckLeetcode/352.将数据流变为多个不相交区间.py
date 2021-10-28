class SummaryRanges:

    def __init__(self):
        self.rgs = []

    def addNum(self, val: int) -> None:
        l = 0
        r = len(self.rgs)-1
        while l<=r:
            m = (l+r)//2
            rg = self.rgs[m]
            if rg[1] < val:
                l = m+1
            elif val < rg[0]:
                r = m-1
            else:
                # do nothing
                return
        print(l, r)
        self.rgs.insert(l, [val, val])


        if l-1 >= 0 and self.rgs[l-1][1]+1 == val:
            self.rgs[l-1][1] += 1
            del self.rgs[l]

            if l < len(self.rgs) and self.rgs[l][0]-1 == val:
                self.rgs[l-1][1] = self.rgs[l][1]
                del self.rgs[l]
        if l+1<len(self.rgs) and self.rgs[l+1][0]-1 == val:
            self.rgs[l+1][0] -= 1
            del self.rgs[l]

    def getIntervals(self) -> [[int]]:
        return self.rgs

ops = ["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
args = [[], [1], [], [3], [], [7], [], [2], [], [6], []]
exps = [None, None, [[1, 1]], None, [[1, 1], [3, 3]], None, [[1, 1], [3, 3], [7, 7]], None, [[1, 3], [7, 7]], None, [[1, 3], [6, 7]]]
