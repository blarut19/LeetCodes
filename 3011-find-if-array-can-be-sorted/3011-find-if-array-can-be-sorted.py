class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        prev_max = 0
        curr_bit_count = nums[0].bit_count()
        curr_min = nums[0]
        curr_max = nums[0]
        for n in nums[1:]:
            if n.bit_count() == curr_bit_count:
                curr_min = min(n, curr_min)
                curr_max = max(n, curr_max)
            else:
                prev_max = curr_max
                curr_bit_count = n.bit_count()
                curr_min = n
                curr_max = n
            if curr_min < prev_max:
                return False
        return True