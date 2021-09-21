#
# @lc app=leetcode.cn id=215 lang=python3
#
# [215] 数组中的第K个最大元素
#

# @lc code=start
class Solution:
    def findKthLargest(self, nums: [int], k: int) -> int:
        def partition(arr, left, right):
            pivot = arr[left]
            while left < right:
                while left<right and arr[right]>=pivot:
                    right -= 1
                arr[left] = arr[right]
                while left<right and arr[left]<=pivot:
                    left += 1
                arr[right] = arr[left]
            arr[left] = pivot
            return left
        def getKth(arr, k):
            n = len(arr)
            t = partition(arr, 0, n-1)
            if t<k:
                return getKth(arr[t+1:], k-t-1)
            elif t>k:
                return getKth(arr[:t], k)
            else:
                return arr[t]
        n = len(nums)
        return getKth(nums, n-k)

# @lc code=end

