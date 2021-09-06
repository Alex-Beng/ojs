class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        num1 = [ord(i)-ord('0') for i in num1][::-1]
        num2 = [ord(i)-ord('0') for i in num2][::-1]


        if len(num1) > len(num2):
            num1, num2 = num2, num1
        
        carry_in = 0
        for i in range(len(num1)):
            
            num2[i] += (carry_in + num1[i])
            carry_in = num2[i]//10
            num2[i] %= 10
        for i in range(len(num1), len(num2)):
            if carry_in:
                num2[i] += carry_in
                carry_in = num2[i]//10
                num2[i] %= 10
            else:
                break
        if carry_in:
            num2.append(carry_in)
        num2 = [str(i) for i in num2]
        return ''.join(num2)[::-1]
s = Solution()
print(s.addStrings(
    # '123', '777'
    "456", "77"
))