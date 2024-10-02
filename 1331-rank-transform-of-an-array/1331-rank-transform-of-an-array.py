class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        arr_copy = sorted(set(arr))
        
        ranks = {value: rank + 1 for rank, value in enumerate(arr_copy)}
        
        return [ranks[value] for value in arr]