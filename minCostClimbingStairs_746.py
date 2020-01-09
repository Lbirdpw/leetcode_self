
class Solution(object):
	def minCostClimbingStairs(self, cost):
	
	    if 1 == len(cost):
			return cost[0]
	    if 2 == len(cost):
		    return min(cost[0], cost[1])
        one = self.minCostClimbingStairs(cost[:-1]) + cost[-1]
        two = self.minCostClimbingStairs(cost[:-2]) + cost[-1]
        return min(one, two)

if __name__ == "__main__":
    cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
    oSol = Solution()
    print oSol.minCostClimbingStairs(cost)

