class Solution:
    def merge(self, nums1: [int], m: int, nums2: [int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        nums1_copy = [nums1[i] for i in range(m)]
        pnt = 0
        p1 = 0
        p2 = 0

        while p1<m and p2<n:
            if nums1_copy[p1]<nums2[p2]:
                nums1[pnt] = nums1_copy[p1]
                pnt += 1
                p1 += 1
            elif nums1_copy[p1]>nums2[p2]:
                nums1[pnt] = nums2[p2]
                pnt += 1
                p2 += 1
            else:
                nums1[pnt] = nums2[p2]
                nums1[pnt+1] = nums2[p2]
                pnt += 2
                p1 += 1
                p2 += 1
        while p1<m:
            nums1[pnt] = nums1_copy[p1]
            pnt += 1
            p1 += 1
        while p2<n:
            nums1[pnt] = nums2[p2]
            pnt += 1
            p2 += 1
            
s = Solution()
a = [1,2,3,0,0,0]
s.merge(
    a, 3, [2,5,6], 3
)
print(a)
