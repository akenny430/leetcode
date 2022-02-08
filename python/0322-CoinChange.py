class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        # table = [float('inf')] * (amount + 1)
        # table[0] = 0
        table = [0] + [float('inf')] * amount
        for i in range(1, amount + 1):
            for currentCoin in coins: 
                # if currentCoin <= i and table[i - currentCoin] != float('inf'):
                if currentCoin <= i:
                    table[i] = table[i] if table[i] < 1 + table[i - currentCoin] else 1 + table[i - currentCoin]
        return table[amount] if table[amount] != float('inf') else -1

# DIFFERENCES FROM C++ 
# 
# Here we do not have to worry about checking for overflow of MAX_INT, since float('inf') + 1 is still inf 