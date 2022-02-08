#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
        int n = static_cast<int>(days.size());
        std::unordered_set<int> covered(begin(days), end(days));
        int dayTable[days[n - 1] + 1];
        dayTable[0] = 0;
        
        for (int i = 1; i <= days[n - 1]; ++i)
        {
            if ( covered.find(i) == covered.end() )
                dayTable[i] = dayTable[i - 1];
            else
            {
                dayTable[i] = std::min({
                    dayTable[i - 1] + costs[0], 
                    dayTable[std::max(0, i - 7)] + costs[1], 
                    dayTable[std::max(0, i - 30)] + costs[2]
                });
            }
        }
        return dayTable[days[n - 1]];
    }
};