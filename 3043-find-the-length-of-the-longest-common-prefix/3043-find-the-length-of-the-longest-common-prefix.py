class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        prefixes = set()
        for num in arr1:
            prefix = str(num)
            for i in range(len(prefix)):
                if prefix not in prefixes:
                    prefixes.add(prefix)
                    prefix = prefix[:-1]
                else:
                    break
        
        longestPrefixLength = 0
        for num in arr2:
            prefix = str(num)
            for i in range(len(prefix)):
                if prefix in prefixes:
                    longestPrefixLength = max(longestPrefixLength, len(prefix))
                    break
                prefix = prefix[:-1]
        
        return longestPrefixLength