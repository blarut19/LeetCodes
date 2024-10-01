class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        m = map(lambda x: ((x % k) + k) % k, arr)
        c = Counter(m)
        for i in range(k):
            if i == 0:
                if c[i] % 2 == 0:
                    continue
                else:
                    return False
            if c[i] != c[k-i]:
                return False 
        return True