class Solution:
    def swapNumbers(self, numbers):
        numbers[0] ^= numbers[1]
        numbers[1] = numbers[0]^numbers[1]
        numbers[0] = numbers[0]^numbers[1]
        return numbers

s = Solution()
print(s.swapNumbers([1,2]))