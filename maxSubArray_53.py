
class Solution(object):
    def maxSubArray(self, nums):
        maxsum = 0
        import sys
        oldsum = -sys.maxint - 1
        for val in nums:
            maxsum += val
            if maxsum < val:
                maxsum = val
            if maxsum > oldsum:
                oldsum = maxsum
            print "{}:{}".format(maxsum, oldsum)
        return oldsum
if __name__ == "__main__":
    nums = [-2,1,-3,4,-1,2,1,-5,4]
    oSol = Solution()
    print oSol.maxSubArray(nums)
