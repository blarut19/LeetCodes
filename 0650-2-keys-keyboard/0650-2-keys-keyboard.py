class Solution:
    def minSteps(self, n: int) -> int:
        def is_prime(n):
            if n <= 1:
                return False
            for i in range(2, int(n**0.5)+1):
                if n % i == 0:
                    return False
            return True
        
        def prime_divisor_sum(n):
            divisors = filter(lambda x: n % x == 0 and is_prime(x), range(2, n+1))
            s = 0
            for divisor in divisors:
                n_copy = n
                while n_copy % divisor == 0:
                    n_copy /= divisor
                    s += divisor
            return s
        
        # Driver code
        return prime_divisor_sum(n)