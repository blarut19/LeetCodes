class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        ans = [0]*len(queries)
        xors = [0] * (len(arr) + 1)

        for i, _ in enumerate(arr):
            xors[i + 1] = arr[i]^xors[i]
        
        for i, query in enumerate(queries):
            ans[i] = xors[query[0]] ^ xors[query[1]+1]
        
        return ans