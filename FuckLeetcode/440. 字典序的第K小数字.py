class Solution:
    def findKthNumber(self, n, k):
        def count_steps(n, curr):
            steps = 0
            first = curr
            last = curr
            while first <= n:
                steps += min(n + 1, last + 1) - first
                first *= 10
                last = last * 10 + 9
            return steps

        curr = 1
        k -= 1
        while k > 0:
            steps = count_steps(n, curr)
            if steps <= k:
                k -= steps
                curr += 1
            else:
                curr *= 10
                k -= 1
        return curr

INPUT = [
    (13, 2)
]