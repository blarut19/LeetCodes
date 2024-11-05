class Solution:
    def minChanges(self, s: str) -> int:
        c = 0
        l = len(s) // 2
        for i in range(l):
            if s[2*i] != s[2*i+1]:
                c += 1
        return c