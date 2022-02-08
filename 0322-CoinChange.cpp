#include <vector>
#include <limits>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) 
    {
        int table[amount + 1];
        table[0] = 0;
        
        for (int i = 1; i <= amount; ++i)
        {
            table[i] = INT_MAX;
            // for (int j = 0; j < static_cast<int>(coins.size()); ++j)
            for (int j : coins)
            {
                if ( j <= i && table[i - j] != INT_MAX )
                {
                    // table[i] = table[i] < 1 + table[i - coins[j]] ? table[i] : 1 + table[i - coins[j]];
                    table[i] = table[i] < 1 + table[i - j] ? table[i] : 1 + table[i - j];
                }
            }
        }
        if (table[amount] == INT_MAX) return -1;
        return table[amount];
    }
};