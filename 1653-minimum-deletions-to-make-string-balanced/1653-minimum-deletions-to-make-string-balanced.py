class Solution:
    def minimumDeletions(self, s: str) -> int:
        c = Counter(s)

        # Costs cost_a and cost_b mean how many a's are in front of
        # the curosr and how many b's are behind the cursor.

        # Cost of deleting all a's after and including index 0.
        cost_a = c["a"]
        # Cost of deleting all b's before index 0.
        cost_b = 0

        min_cost = cost_a
        
        for letter in s:
            # If the current letter is 'a' decrease the cost of deleting
            # a's since it's now on the left side of cursor.
            if letter == "a":
                cost_a -= 1
            # If the current letter is 'b' increse the cost of deleting
            # b's since it's now on the left side of cursor.
            else:
                cost_b += 1
            if min_cost > cost_a + cost_b:
                min_cost = cost_a + cost_b

        return min_cost