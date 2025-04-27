class Solution:
    def countSubarrays(self, nums: list[int], k: int) -> int:
        N = len(nums)
        # 先获得前缀和
        preSum = [nums[0]] * N
        for i in range(1, N):
            preSum[i] = preSum[i-1] + nums[i]

        res = 0 if nums[0] >= k else 1
        # 枚举数组Right，对Left进行二分，找出 sum * len < k 的left
        for Rb in range(1, N):
            L = 0
            R = Rb
            while L < R:
                # print(L, R)
                mid = (L+R) // 2
                tempSum = preSum[Rb] - preSum[mid] + nums[mid]
                tempLen = Rb - mid + 1
                if tempSum * tempLen >= k:
                    L = mid + 1
                else:
                    R = mid
            # print(L, Rb)
            tempSum = preSum[Rb] - preSum[L] + nums[L]
            tempLen = Rb - L + 1
            if tempSum * tempLen < k:
                res += Rb - L + 1
        return res
    # 滑动窗口
    def countSubarrays(self, nums: list[int], k: int) -> int:
        N = len(nums)
        # 先获得前缀和
        preSum = [nums[0]] * N
        for i in range(1, N):
            preSum[i] = preSum[i-1] + nums[i]

        res = 0
        # 枚举右端点
        L = 0
        for R in range(N):
            while True:
                if L > R: break
                tempSum = preSum[R] - preSum[L] + nums[L]
                tempLen = R - L + 1
                if tempLen * tempSum < k or L > R:
                    break
                else:
                    L += 1
            if L <= R:
                res += R-L+1

        return res

s = Solution()
r = s.countSubarrays(
    # [2,1,4,3,5], 10
    [9,5,3,8,4,7,2,7,4,5,4,9,1,4,8,10,8,10,4,7], 4
)
print(r)