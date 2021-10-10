class Solution:
    def intToRoman(self, num: int) -> str:
        num2rm = {
            1:'I',
            4:'IV',
            5:'V',
            9:'IX',
            10:'X',
            40:'XL',
            50:'L',
            90:'XC',
            100:'C',
            400:'CD',
            500:'D',
            900:'CM',
            1000:'M'
        }
        nums = list(num2rm.keys())
        n = len(nums)
        res = ''
        while num != 0:
            l = 0
            r = n-1
            ans = 0
            while l<=r:
                m = (l+r)//2
                t = nums[m]
                if num >= t:
                    ans = m
                    l = m+1
                else:
                    r = m-1
            res += num2rm[nums[ans]]
            num -= nums[ans]
        return res
        print(res)
s = Solution()
s.intToRoman(1994)