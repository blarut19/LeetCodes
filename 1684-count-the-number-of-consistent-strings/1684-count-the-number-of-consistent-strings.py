class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        n = 0
        allowed = set(allowed)
        for word in words:
            for letter in word:
                valid = 1
                if letter not in allowed:
                    valid = 0
                    break
            n += valid
        return n