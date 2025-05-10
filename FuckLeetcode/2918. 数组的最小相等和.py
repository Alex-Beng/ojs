class Solution:
    def minSum(self, nums1: 'List[int]', nums2: 'List[int]') -> int:
        z1 = 0 in nums1
        z2 = 0 in nums2
        sum1 = sum(nums1)
        sum2 = sum(nums2)
        zn1 = nums1.count(0)
        zn2 = nums2.count(0)
        sum1_ex = sum1 + zn1
        sum2_ex = sum2 + zn2
        if not z1 and not z2 and sum1 != sum2 \
        or sum1 < sum2 and not z1 \
        or sum2 < sum1 and not z2 \
        or sum1_ex > sum2_ex and not z2 \
        or sum2_ex > sum1_ex and not z1:
            return -1
        
        
        diff = abs(sum1_ex-sum2_ex)
        return min(sum1_ex, sum2_ex) + diff
        pass
INPUT = [
    # ([3,2,0,1,0], [6,5,0]),
    ([9,5], [15,12,5,21,4,26,27,9,6,29,0,18,16,0,0,0,20])
]