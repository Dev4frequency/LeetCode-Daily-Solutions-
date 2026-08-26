class Solution:
    def minArraySum(self, nums: list[int]) -> int:
        pelnorazi = nums[:]

        mx = max(nums)
        present = [False] * (mx + 1)

        for x in nums:
            present[x] = True

        smallest = [0] * (mx + 1)

        for v in range(1, mx + 1):
            if present[v]:
                for multiple in range(v, mx + 1, v):
                    if smallest[multiple] == 0:
                        smallest[multiple] = v

        ans = 0

        for x in nums:
            ans += smallest[x]

        return ans