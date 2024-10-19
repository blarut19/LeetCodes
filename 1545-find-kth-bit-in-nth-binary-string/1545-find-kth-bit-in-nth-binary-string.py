
class Solution:
    def findKthBit(self, n: int, k: int, flip = 0) -> str:
        if k == 1:
            return str(flip)
        if k == 2:
            return str(1 - flip)
        # Check if k is a power of 2
        if (k-1 & k == 0) and k != 0:
            return str(1 - flip)
        if 2**n - k > k:
            return self.findKthBit(n-1, k, flip)
        return self.findKthBit(n-1, 2**n - k, 1 - flip)