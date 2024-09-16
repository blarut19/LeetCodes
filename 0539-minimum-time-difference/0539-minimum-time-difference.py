class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        points = set(timePoints)
        if len(points) < len(timePoints):
            return 0

        points = map(lambda point: int(point[0:2])*60 + int(point[3:5]), points)
        points = sorted(points)
        
        minDiff = min(1440 - points[-1] + points[0], points[-1] - points[0])

        for i in range(len(points) - 1):
            minDiff = min(minDiff, points[i+1] - points[i])
            if minDiff == 1:
                break

        return minDiff