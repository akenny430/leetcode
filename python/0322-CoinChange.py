class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        table = [float('inf')] * (amount + 1)
        table[0] = 0
        for i in range(amount + 1):
            for currentCoin in coins: 
                if currentCoin <= i and table[i - currentCoin] != float('inf'):
                    table[i] = table[i] if table[i] < 1 + table[i - currentCoin] else 1 + table[i - currentCoin]
        return table[amount] if table[amount] != float('inf') else -1