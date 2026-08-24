class Solution:
    def __init__(self):
        self.kk = 0
        self.map = {}

    def gcd(self, a, b):
        while b != 0:
            temp = b
            b = a % b
            a = temp
        return a

    def solve(self, nums, index, n, d):
        g = self.gcd(n, d)
        n //= g
        d //= g
        if index == len(nums):
            return 1 if d == 1 and n == self.kk else 0

        key = str(index) + "," + str(n) + "," + str(d)
        if key in self.map:
            return self.map[key]

        cnt = 0
        cnt += self.solve(nums, index + 1, n * nums[index], d)
        cnt += self.solve(nums, index + 1, n, d * nums[index])
        cnt += self.solve(nums, index + 1, n, d)

        self.map[key] = cnt
        return cnt

    def countSequences(self, nums, k):
        self.kk = k
        return self.solve(nums, 0, 1, 1)