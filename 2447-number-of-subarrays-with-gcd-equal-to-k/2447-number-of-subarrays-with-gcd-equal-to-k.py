import math

class Solution:
    def subarrayGCD(self, nums: List[int], k: int) -> int:
        res = 0
        for i in range(len(nums)):
            gcd = 0
            for j in range(i, len(nums)):
                gcd = math.gcd(gcd, nums[j])
                if gcd == k:
                    res += 1
                elif gcd < k:
                    break
        return res