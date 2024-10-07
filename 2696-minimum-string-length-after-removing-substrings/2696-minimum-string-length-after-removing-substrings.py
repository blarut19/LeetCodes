class Solution:
    def minLength(self, s: str) -> int:
        i = 0
        last_len = len(s)
        while(1):
            s = s.replace("AB", "")
            s = s.replace("CD", "")
            if last_len != len(s):
                last_len = len(s)
                continue
            return len(s)