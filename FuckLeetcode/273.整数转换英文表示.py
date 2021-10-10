class Solution:
    def numberToWords(self, num: int) -> str:
        scale2str = {
            1:'',
            100:'Hundred',
            1000:'Thousand',
            1000000:'Million',
            1000000000:'Billion'
        }
        num2str = {
            0:'',
            1:'One',
            2:'Two',
            3:'Three',
            4:'Four',
            5:'Five',
            6:'Six',
            7:'Seven',
            8:'Eight',
            9:'Nine',
            10:'Ten',
            11:'Eleven',
            12:'Twelve',
            13:'Thirteen',
            14:'Fourteen',
            15:'Fifteen',
            16:'Sixteen',
            17:'Seventeen',
            18:'Eighteen',
            19:'Nineteen',
            20:'Twenty',
            30:'Thirty',
            40:'Forty',
            50:'Fifty',
            60:'Sixty',
            70:'Seventy',
            80:'Eighty',
            90:'Ninety'
        }

        def n32wd(num):
            h = num//100
            res = [] if h==0 else [num2str[h], scale2str[100]]
            n2 = num%100
            n1 = num%10
            if n2 in num2str:
                return res + [num2str[n2]]
            else:
                return res + [num2str[n2-n1], num2str[n1]]

        ans = []
        scale = 1
        if num==0:
            return 'Zero'
        while num != 0:
            last_3 = num%1000
            print(last_3, scale)
            ans = n32wd(last_3) + [scale2str[scale]] + ans

            num //= 1000
            scale *= 1000
        ans = [i for i in ans if i!='']
        ans = ' '.join(ans)
        ans = ans.replace('Billion Million Thousand', 'Billion')
        ans = ans.replace('Million Thousand', 'Million')
        return ans
        
s = Solution()
r = s.numberToWords(
2000

)
print(r)