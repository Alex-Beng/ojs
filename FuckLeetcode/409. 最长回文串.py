class Solution:
    def longestPalindrome(self, s: str) -> int:
        cha2times = dict()
        for cha in s:
            if cha in cha2times:
                cha2times[cha] += 1
            else:
                cha2times[cha] = 1
        # print(cha2times)
        max_odd = 0
        even_part = 0
        for k in cha2times:
            v = cha2times[k]
            if v&1:
                max_odd = max(max_odd, v)
                even_part += v//2*2
            else:
                even_part += v
        return even_part - max_odd//2*2 + max_odd
s = Solution()
print(s.longestPalindrome(
    # "abccccdd"
    "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth"
))