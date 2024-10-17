class Solution:
    def maximumSwap(self, num: int) -> int:

        maxPossible = "".join(sorted(str(num), reverse=True))
        strNum = str(num)

        for i, digit in enumerate(maxPossible):
            if digit != strNum[i]:
                j = len(strNum) - 1
                while digit != strNum[j]:
                    j -= 1
                return int(strNum[:i] + digit + strNum[i+1:j] + strNum[i] + strNum[j+1:])

        return num