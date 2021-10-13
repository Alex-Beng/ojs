class Solution:
    def peakIndexInMountainArray(self, arr: [int]) -> int:
        n = len(arr)
        L = 0
        R = n-1
        while L<=R:
            m = (L+R)//2
            # ans
            if m==0 and arr[m]>arr[m+1] or m==n-1 and arr[m-1]<arr[m] \
                or arr[m-1]<arr[m] and arr[m]>arr[m+1]:
                return m
            elif m==0 or arr[m-1]<arr[m]:
                L = m+1
            else:
                R = m-1