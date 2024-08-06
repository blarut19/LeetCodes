class Solution:
    def minimumPushes(self, word: str) -> int:
        c = Counter(word)
        i = 0
        total = 0

        for _, count in c.most_common():
            total += count * (1 + i // 8)
            i += 1
        return total