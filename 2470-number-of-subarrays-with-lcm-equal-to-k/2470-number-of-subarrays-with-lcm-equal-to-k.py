import math
from typing import List

class Solution:
    def subarrayLCM(self, nums: List[int], k: int) -> int:
        result = 0
        n = len(nums)
        
        for i in range(n):
            current_lcm = 1
            for j in range(i, n):
                current_lcm = math.lcm(current_lcm, nums[j])
                if current_lcm > k:
                    break
                if current_lcm == k:
                    result += 1
        
        return result