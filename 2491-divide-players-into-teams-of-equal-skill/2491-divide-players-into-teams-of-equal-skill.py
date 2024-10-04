class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        skill = sorted(skill)
        skill_sum = skill[0] + skill[-1]
        chem_sum = 0
        n = len(skill)
        for i in range(n//2):
            new_sum = skill[i] + skill[-i-1]
            if skill_sum == new_sum:
                chem_sum += skill[i] * skill[-i-1]
            else:
                return -1
        return chem_sum

