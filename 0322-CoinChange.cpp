#include <vector>
#include <limits>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) 
    {
        // (1)
        int table[amount + 1];
        table[0] = 0;
        
        // (2)
        for (int i = 1; i <= amount; ++i)
        {
            // (3)
            table[i] = INT_MAX;
            // (4)
            for (int currentCoin : coins)
            {
                // (5)
                if ( currentCoin <= i && table[i - currentCoin] != INT_MAX )
                {
                    // (6)
                    table[i] = table[i] < 1 + table[i - currentCoin] ? table[i] : 1 + table[i - currentCoin];
                }
            }
        }
        // (7)
        if (table[amount] == INT_MAX) return -1;
        return table[amount];
    }
};

/**
 * GENERAL NOTES 
 * 
 * This problem can be solved using dynamic programming with a bottom up approach 
 * Motivating example: coins [1, 2, 5] and amount 7
 * From these coins: the only way to get to 7 is:
 *     - Increase from 6 by 1
 *     - Increase from 5 by 2
 *     - Increase from 2 by 5
 * So now we ask, from each of these three previous states (6, 5, 2): 
 *     1. Is it even possible to be in this previous state? If not, then this solution path is implausible 
 *     2. Of the possible states, which one took the least amount of coins to get? 
 * From this, we can work backward to find the smallest number of coins 
 */

/**
 * STRATEGY 
 * 
 * Use infinity (INT_MAX) to represent a state that is unreachable
 * Create an array of length "amount + 1" to store the minimum number of ways you can get to each coin value up to "amount"
 * e.g. if table[3] = 2, this means "to get a value of 3, we need 2 coins"
 * Initialize table[0] = 0, meaning "to get a value of 0, we need minumum 0 coins" 
 * For a given amount, we check each of the possible coins we could use as follows: 
 *     1. Is this coin less than the total amount? e.g. if the coin is 10 and the value is 7, then this coin could not be used 
 *     2. Is the previous state from this coin reachable? If not, then we cannot consider that path. 
 * If both criteria are met, then we set the current value to be the minimum between: 
 *     1. It's current value 
 *     2. 1 + "number of coins at previous spot" 
 * Finally, we return the final index of the table, unless it is INT_MAX, in which case we return -1 
 */

/**
 * COMMENTS 
 * 
 * (1): Here we are initializing two tables to store the intermediate values of the sub-problems
 *      We are also setting the values at the 0 index to be equal to 0, 
 *      which corresponds to "to get a value of 0, we need 0 coins"
 * 
 * (2): For this loop we are moving through all of the sub-problems up to v
 * 
 * (3): Here we initialize each solution to the sub-problem as INT_MAX.
 *      At the end of looping through the coins, if we still have INT_MAX as the value, 
 *      then there is no way to get to that value 
 * 
 * (4): For this loop we are moving through all of the coins 
 *      Note that in C++, it is faster to iterate through the container as opposed to using a for-loop 
 * 
 * (5): For this if, we need two things to be true, 
 *      1) we need the current coin to be less than or equal to the value of the sub-problem, 
 *      otherwise we know it is impossible to use it in solving it **
 *      2) we need the value of the sub-problem that we are looking back at to not equal INT_MAX, 
 *      otherwise we will just keep this one as INT_MAX (since we can't reach it)
 *      We then set the minimum value 
 * 
 * (6): Setting the current value equal to the minimum 
 * 
 * (7): Returning the solution
 */