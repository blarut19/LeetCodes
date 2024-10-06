class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        words1 = sentence1.split(" ")
        words2 = sentence2.split(" ")
        l1 = len(words1)
        l2 = len(words2)

        i = 0
        while words1[i] == words2[i]:
            i += 1
            if(i >= l1 or i >= l2):
                break
        
        j = 0
        while words1[-j-1] == words2[-j-1]:
            j += 1
            if(j >= l1 or j >= l2):
                break

        if l1 <= i + j or l2 <= i + j:
            return True
        
        return False