class Solution:
    def __init__(self):
        n = 46400
        sqs = set()
        for i in range(n):
            sqs.add(i*i)
        self.sqs = sqs
    def judgeSquareSum(self, c: int) -> bool:
        if c==0:
            return False
        sqs = self.sqs
        i = 1
        while i*i <= c:
            another = c-i*i
            if another in sqs:
                return True
            i += 1
        return False