class Solution:
    def minimumSteps(self, s: str) -> int:
        trainLength = 0
        swaps = 0
        for ball in s:
            if ball == "1":
                trainLength += 1
            else:
                swaps += trainLength
        return swaps
