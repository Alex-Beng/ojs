class Solution:
    def findMedianSortedArrays(self, nums1: [int], nums2: [int]) -> float:
        len1 = len(nums1)
        len2 = len(nums2)

        nums = []
        p1 = p2 = 0

        while len(nums1)!=0 and len(nums2)!=0:
            if nums1[0]>nums2[0]:
                nums.append(nums2[0])
                del nums2[0]
            elif nums1[0]<nums2[0]:
                nums.append(nums1[0])
                del nums1[0]
            else:
                nums.append(nums1[0])
                nums.append(nums2[0])
                del nums1[0]
                del nums2[0]
        
        while len(nums1)!=0:
            nums.append(nums1[0])
            del nums1[0]
        while len(nums2)!=0:
            nums.append(nums2[0])
            del nums2[0]
        # print(nums)
        n = len(nums)
        if n&1 == 0:
            return (nums[n//2]+nums[n//2-1])/2
        else:
            return nums[n//2]


s = Solution()
print(s.findMedianSortedArrays(
    [1,3], [2]
))