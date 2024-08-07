d = {"1": "One",
    "2": "Two",
    "3": "Three",
    "4": "Four",
    "5": "Five",
    "6": "Six",
    "7": "Seven",
    "8": "Eight",
    "9": "Nine",
    "10": "Ten",
    "11": "Eleven",
    "12": "Twelve",
    "13": "Thirteen",
    "14": "Fourteen",
    "15": "Fifteen",
    "16": "Sixteen",
    "17": "Seventeen",
    "18": "Eighteen",
    "19": "Nineteen",
    "20": "Twenty",
    "30": "Thirty",
    "40": "Forty",
    "50": "Fifty",
    "60": "Sixty",
    "70": "Seventy",
    "80": "Eighty",
    "90": "Ninety"
    }
class Solution:
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"
        
        s = str(num)
        s = s.zfill(12)

        # Split num to groups of three.
        billions = s[0:3]
        millions = s[3:6]
        thousands = s[6:9]
        ones = s[9:]

        # Parse billions.
        billionsWord = self.decodeDigitGroup(billions)
        if billionsWord == []:
            pass
        else:
            billionsWord.append("Billion")

        # Parse millions.
        millionsWord = self.decodeDigitGroup(millions)
        if millionsWord == []:
            pass
        else:
            millionsWord.append("Million")

        # Parse thousands.
        thousandsWord = self.decodeDigitGroup(thousands)
        if thousandsWord == []:
            pass
        else:
            thousandsWord.append("Thousand")
        onesWord = self.decodeDigitGroup(ones)

        ans = billionsWord + millionsWord + thousandsWord + onesWord
        return " ".join(ans)
    def decodeDigitGroup(self, group):

        answer = []

        if group == "000":
            return answer
        
        # Parse hundreds.
        if group[0] == "0":
            pass
        else:
            answer.append(d[group[0]] + " Hundred")
        
        # Parse tens.
        if group[1] == "0":
            pass
        elif group[1] == "1":
            answer.append(d[group[1:]])
            return answer
        else:
            answer.append(d[group[1]+"0"])
        
        # Parse ones.
        if group[2] == "0":
            return answer
        else:
            answer.append(d[group[2]])
            return answer