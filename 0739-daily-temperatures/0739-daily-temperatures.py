class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        stack=[]
        result=[0]*len(temperatures)

        for i in range(len(temperatures)-1,-1,-1):
            while(stack and temperatures[i] >= temperatures[stack[-1]]):
                stack.pop()
            if stack:
                result[i]=abs(stack[-1]-i)
            stack.append(i)
        return result