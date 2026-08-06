from collections import defaultdict
from math import gcd
from typing import List

class Solution:
    def getCoprimes(self, nums: List[int], edges: List[List[int]]) -> List[int]:
        res = [-1] * len(nums)
        graph = defaultdict(list)
        number_paths = [[] for _ in range(51)]
        visited_nodes = set()

        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        def explore(node, level):
            if node in visited_nodes:
                return
            visited_nodes.add(node)
            closest_ancestor = -1
            for num in range(1, 51):
                if gcd(nums[node], num) == 1:
                    if number_paths[num]:
                        last_ancestor, last_level = number_paths[num][-1]
                        if last_level > closest_ancestor:
                            closest_ancestor = last_level
                            res[node] = last_ancestor
            number_paths[nums[node]].append((node, level))
            for neighbor in graph[node]:
                explore(neighbor, level + 1)
            number_paths[nums[node]].pop()

        explore(0, 0)
        return res