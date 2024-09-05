class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m = len(rolls)
        s = sum(rolls)
        target = (m + n) * mean - s
        
        # If cannot construct return empty list.
        if 6*n < target or target < n:
            return []
        # Construct the output given target.
        avg = target // n
        remainder = target % n
        
        out = [avg + 1] * remainder + [avg]*(n-remainder)

        return out