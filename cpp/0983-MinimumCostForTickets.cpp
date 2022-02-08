#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
        // (1)
        int n = static_cast<int>(days.size());
        std::unordered_set<int> relevantDay(begin(days), end(days));
        int dayTable[days[n - 1] + 1];
        dayTable[0] = 0;
        
        // (2)
        for (int i = 1; i <= days[n - 1]; ++i)
        {
            // (3)
            if ( relevantDay.find(i) == relevantDay.end() )
                dayTable[i] = dayTable[i - 1];
            else
            {
                // (4)
                dayTable[i] = std::min({
                    dayTable[i - 1] + costs[0], 
                    dayTable[std::max(0, i - 7)] + costs[1], 
                    dayTable[std::max(0, i - 30)] + costs[2]
                });
            }
        }
        // (5)
        return dayTable[days[n - 1]];
    }
};

/**
 * COMMENTS 
 * 
 * Dynamic programming 
 * Made use of vectors, unordered_set, and min/max
 * Could have used days.back(), but finding last element and indexing seemed faster
 * 
 * (1): Initializing stuff for the problem, namely
 *          - the size of the number of days we can travel 
 *          - an unordered_set of all of the days we need to travel on 
 *          - an array of all of the days up to the last possible day 
 *          - initializing the first element of this array to 0, i.e. "it costs $0 to travel on day 0"
 * 
 * (2): Looping through each of the possible days starting from 1 up to the final day 
 * 
 * (3): Checking to see if the current day is a day that we need to travel on. 
 *      If it is not, then the cost of traveling on this day is the same as the cost of the previous day 
 *      If it is, then we move on (see (4))
 * 
 * (4): Finding the minimum from the three possible scenarios: 
 *          1. One day travel, look at the cost one day back and add the cost of one day travel 
 *          2. Seven day travel, look at the cost seven days back and add the cost of seven day travel 
 *          3. Thirty day travel, look at the cost thirty days back and add the cost of thirty day travel 
 *      For seven day and thirty day travel, if we are not far enough along, then we just use the initial cost for them 
 * 
 * (5): Returning the minimum cost 
 */