class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        nums = set(nums)
        max_streak = 0
        for num in nums:
            current_streak = 1
            square = num * num
            while square in nums:
                current_streak += 1
                square *= square
            max_streak = max(max_streak, current_streak)
        if max_streak == 1:
            return -1
        return max_streak