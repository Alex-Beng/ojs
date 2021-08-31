class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1_nums = [int(i) for i in version1.split('.')]
        v2_nums = [int(i) for i in version2.split('.')]
        n1 = len(v1_nums)
        n2 = len(v2_nums)

        if n1 != n2:
            if n1>n2:
                v2_nums += [0]*(n1-n2)
            else:
                v1_nums += [0]*(n2-n1)
        n = len(v1_nums)

        for i in range(n):
            v1 = v1_nums[i]
            v2 = v2_nums[i]
            if v1>v2:
                return 1
            elif v1<v2:
                return -1
        return 0
s = Solution()
print(s.compareVersion(
    # "1.01", "1.001"
    # "1.0", "1.0.0"
    # "0.1","1.1"
    # "1.0.1", "1"
    "7.5.2.4", "7.5.3"
))
            