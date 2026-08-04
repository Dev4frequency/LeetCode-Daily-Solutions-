from math import comb
from collections import Counter

MOD = 10**9 + 7

class Solution:
    def waysToFillArray(self, queries: List[List[int]]) -> List[int]:
        def prime_factors(x):
            factors = Counter()
            d = 2
            while d * d <= x:
                while x % d == 0:
                    factors[d] += 1
                    x //= d
                d += 1
            if x > 1:
                factors[x] += 1
            return factors

        def ways(n, k):
            factors = prime_factors(k)
            res = 1
            for count in factors.values():
                res = res * comb(n + count - 1, count) % MOD
            return res

        return [ways(n, k) for n, k in queries]