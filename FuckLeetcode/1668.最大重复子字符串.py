class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        n = len(sequence)
        m = len(word)
        dp = [0] * (n+1)
        for i in range(m, n+1):
            if sequence[i-m:i] != word:
                dp[i] = 0
            else:
                if i-m >= 0:
                    dp[i] = dp[i-m] + 1
                else:
                    dp[i] = 1
        # print([str(c) for c in dp])
        # print(list(sequence))
        return max(dp)

INPUT = [
    (
        "aaabaaaabaaabaaaabaaaabaaaabaaaaba",
        "aaaba",
    ),
    (
        "1", "1"
    ),
]