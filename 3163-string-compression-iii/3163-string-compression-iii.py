class Solution:
    def compressedString(self, word: str) -> str:
        comp = ""
        prev_c = word[0]
        count = 1
        for c in word[1:]:
            if c != prev_c or count >= 9:
                comp += str(count) + prev_c
                count = 1
                prev_c = c
            else:
                count += 1
        comp += str(count) + prev_c
        return comp