from math import sqrt

class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        for a in range(1, int(sqrt(c)+1)):
            b2 = c - a*a
            b = sqrt(b2)
            if b == round(b):
                  return True
        if c <= 2:
            return True
        return False