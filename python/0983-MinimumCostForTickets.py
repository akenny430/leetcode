class Solution(object):
    def mincostTickets(self, days, costs):
        """
        :type days: List[int]
        :type costs: List[int]
        :rtype: int
        """
        relevantDays = set(days)
        dayTable = [0] * (days[-1] + 1)
        
        for i in range(1, days[-1] + 1):
            if i not in relevantDays:
                dayTable[i] = dayTable[i - 1]
            else:
                dayTable[i] = min(
                    dayTable[i - 1] + costs[0],
                    dayTable[max(0, i - 7)] + costs[1],
                    dayTable[max(0, i - 30)] + costs[2],
                )
        return dayTable[days[-1]]