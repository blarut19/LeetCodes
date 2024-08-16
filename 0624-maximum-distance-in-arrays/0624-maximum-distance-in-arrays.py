class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        firstMin, firstMax = arrays[0][0], arrays[0][-1]
        secondMin, secondMax = firstMax, firstMin
          
        maxIndex = minIndex = 0
        for i, array in enumerate(arrays[1:], 1):
            if array[0] < firstMin:
                secondMin = firstMin
                firstMin = array[0]
                minIndex = i
            elif array[0] < secondMin:
                secondMin = array[0]

            if array[-1] > firstMax:
                secondMax = firstMax
                firstMax = array[-1]
                maxIndex = i
            elif array[-1] > secondMax:
                secondMax = array[-1]
                
        if minIndex == maxIndex:
            return max(firstMax - secondMin, secondMax - firstMin)
        return firstMax - firstMin