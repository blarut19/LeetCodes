class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        if k == 1:
            return nums
        n = len(nums)
        current_streak = 1
        prev = nums[0]
        index = -k + 1
        ans = [-1] * (n - k + 1)
        for num in nums[1:]:
            index += 1
            if num - 1 == prev:
                current_streak += 1
            else:
                current_streak = 1
            if(current_streak >= k):
                ans[index] = num
            prev = num

        return ans