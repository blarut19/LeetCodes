class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        s = sum(chalk)
        k %= s
        for i, c in enumerate(chalk):
            k -= c
            if k < 0:
                return i