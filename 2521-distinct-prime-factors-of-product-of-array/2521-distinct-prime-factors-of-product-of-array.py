from math import sqrt
from typing import List

class Solution:
    def primeFactors(self, x: int) -> set[int]:
        factors = set()
        for i in range(2, int(sqrt(x)) + 1):
            while x % i == 0:
                factors.add(i)
                x //= i
        if x > 1:
            factors.add(x)
        return factors

    def distinctPrimeFactors(self, nums: List[int]) -> int:
        primes = set()
        for x in nums:
            primes |= self.primeFactors(x)
        return len(primes)