class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()

        out = []

        l1 = len(nums1)
        l2 = len(nums2)
        
        i1 = 0
        i2 = 0
        
        while i1 < l1 and i2 < l2:
            if nums1[i1] == nums2[i2]:
                out.append(nums1[i1])
                i1 += 1
                i2 += 1
                continue
            if nums1[i1] < nums2[i2]:
                i1 += 1
            else:
                i2 += 1

        return out
        