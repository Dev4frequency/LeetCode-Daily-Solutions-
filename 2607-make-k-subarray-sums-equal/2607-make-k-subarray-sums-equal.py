class Solution:
    def makeSubKSumEqual(self, arr: List[int], k: int) -> int:
        n = len(arr)
        divisor = math.gcd(n, k)
        total_steps = 0
        for i in range(divisor):
            subarray = sorted([arr[j] for j in range(i, n, divisor)])
            middle_value = subarray[len(subarray) // 2]
            total_steps += sum(abs(val - middle_value) for val in subarray)
        return total_steps