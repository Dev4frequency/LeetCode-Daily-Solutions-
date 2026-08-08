class DisjointSetUnion:
    def __init__(self):
        self.parents = {}

    def find(self, node):
        if node != self.parents.setdefault(node, node):
            self.parents[node] = self.find(self.parents[node])
        return self.parents[node]

    def union(self, node1, node2):
        root1, root2 = self.find(node1), self.find(node2)
        if root1 != root2:
            self.parents[root1] = root2

class Solution:
    def gcdSort(self, nums):
        def get_smallest_prime_factors(limit):
            spf = [i for i in range(limit)]
            for i in range(2, limit):
                if spf[i] == i:
                    for j in range(i * i, limit, i):
                        if spf[j] > i:
                            spf[j] = i
            return spf

        def prime_factors_of(num, spf):
            while num > 1:
                yield spf[num]
                num //= spf[num]

        smallest_prime_factors = get_smallest_prime_factors(max(nums) + 1)
        dsu = DisjointSetUnion()

        for number in nums:
            for prime_factor in prime_factors_of(number, smallest_prime_factors):
                dsu.union(number, prime_factor)

        for original, sorted_value in zip(nums, sorted(nums)):
            if dsu.find(original) != dsu.find(sorted_value):
                return False

        return True