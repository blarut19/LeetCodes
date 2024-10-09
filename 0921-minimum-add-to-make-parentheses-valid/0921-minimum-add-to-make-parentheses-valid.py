class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        i = 0
        count = 0
        for sign in s:
            if(sign == "("):
                i += 1
            else:
                if i > 0:
                    i -= 1
                else:
                    count += 1
        return count + i