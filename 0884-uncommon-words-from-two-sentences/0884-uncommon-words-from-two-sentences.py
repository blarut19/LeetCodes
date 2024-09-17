class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        words = s1.split(" ") + s2.split(" ")
        return filter(lambda word: words.count(word) == 1, words)