class Solution:
    def reverseBits(self, n: int) -> int:
        masks = [
            int('0xAAAAAAAA',base=16),
            int('0xCCCCCCCC',base=16),
            int('0xF0F0F0F0',base=16),
            int('0xFF00FF00',base=16),
            int('0xFFFF0000',base=16)
        ]
        for i in range(5):
            shift = (1<<i)

            even = n&masks[i]
            odd = n&(masks[i]>>shift)

            even >>= shift
            odd <<= shift

            n = even | odd
        return n
            
s = Solution()
n = s.reverseBits(
    int('11111111111111111111111111111101', base=2)
)

print(bin(n))