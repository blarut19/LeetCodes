class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        myString = ""
        count = [["a", a], ["b", b], ["c", c]]
        count = sorted(count, key=lambda x: x[1], reverse=True)
        
        # Add first letter to the string
        myString += count[0][0]
        count[0][1] -= 1
        count = sorted(count, key=lambda x: x[1], reverse=True)

        
        # Add second letter to the string if possible
        if count[0][1] > 0:
            myString += count[0][0]
            count[0][1] -= 1

        while count[0][1] + count[1][1] + count[2][1]:
            count = sorted(count, key=lambda x: x[1], reverse=True)
            if myString[-1] == count[0][0]:
                if myString[-2] == count[0][0]:
                    if count[1][1] > 0:
                        myString += count[1][0]
                        count[1][1] -= 1
                        continue
                    else:
                        break
            myString += count[0][0]
            count[0][1] -= 1

        return myString
        
