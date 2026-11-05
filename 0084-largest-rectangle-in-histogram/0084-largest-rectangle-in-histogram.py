class Solution:
    def largestRectangleArea(self, heights):
        stack = []
        area = 0
        
        for i in range(len(heights)):
            start = i
            while stack and stack[-1][1] > heights[i]:
                index, height = stack.pop()
                area = max(area, (i - index) * height)
                start = index
            stack.append((start, heights[i]))
        
        while stack:
            index, height = stack.pop()
            area = max(area, (len(heights) - index) * height)
        
        return area
