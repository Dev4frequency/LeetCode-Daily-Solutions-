class Solution:
    def minOperations(self, nums: List[int]) -> int:
        
        def fun(n):
            for i in range(2, int(sqrt(n)+1)):
                if n%i==0:
                    return n/i
            return 1

        ans = 0
        for i in range(len(nums)-1, 0, -1):
            if nums[i]<nums[i-1]:
                while(nums[i]<nums[i-1]):
                    ans+=1
                    div = fun(nums[i-1])
                    if div == 1:
                        return -1
                    nums[i-1]= nums[i-1]/div
        return ans