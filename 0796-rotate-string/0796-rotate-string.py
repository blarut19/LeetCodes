class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) == len(goal):
            goal = goal + goal
            if s in goal:
                return True
        return False