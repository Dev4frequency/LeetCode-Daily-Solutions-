from collections import Counter
from functools import lru_cache

class Solution:
    def numberOfGoodSubsets(self, nums):
        primes_list = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
        number_count = Counter(nums)
        prime_bitmask = [sum(1 << i for i, prime in enumerate(primes_list) if x % prime == 0) for x in range(31)]
        excluded = {4, 8, 9, 12, 16, 18, 20, 24, 25, 27, 28}
        MODULUS = 10**9 + 7
        
        @lru_cache(None)
        def recurse(mask, num):
            if num == 1: return 1
            result = recurse(mask, num - 1)
            if num not in excluded and mask | prime_bitmask[num] == mask:
                result += recurse(mask ^ prime_bitmask[num], num - 1) * number_count[num]
            return result % MODULUS

        return ((recurse(1023, 30) - 1) * pow(2, number_count[1], MODULUS)) % MODULUS