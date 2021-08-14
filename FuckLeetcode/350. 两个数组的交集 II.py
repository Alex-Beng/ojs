class Solution:
    def intersect(self, nums1: [int], nums2: [int]) -> [int]:
        nums1.sort()
        nums2.sort()
        ans = []
        while len(nums1) and len(nums2):
            if nums1[0]>nums2[0]:
                del nums2[0]
            elif nums1[0]<nums2[0]:
                del nums1[0]
            else:
                ans.append(nums1[0])
                del nums1[0]
                del nums2[0]
        return ans