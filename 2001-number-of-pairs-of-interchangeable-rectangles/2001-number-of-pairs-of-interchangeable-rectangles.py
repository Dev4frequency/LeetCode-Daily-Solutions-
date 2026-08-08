from collections import defaultdict
from math import gcd

class Solution:
    def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
        count = defaultdict(int)
        result = 0
        for w, h in rectangles:
            g = gcd(w, h)
            ratio = (w // g, h // g)
            result += count[ratio]
            count[ratio] += 1
        return result