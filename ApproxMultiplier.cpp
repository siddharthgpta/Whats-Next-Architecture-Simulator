#include "Multiplier.hpp"

using namespace std;

timeval ApproxMultiplier::operator()(const std::vector<std::vector<unsigned int>> &multipliers, const std::vector<unsigned int> &multiplicants, std::vector<unsigned long long> &result) {
    timeval start, end, time_taken;
    vector<unsigned long long>::iterator r;
    size_t j, len = multipliers.size();

    gettimeofday(&start, nullptr);
    started = true;
    for(int i = 0; incomplete && i < sizeof(unsigned int); ++i) {
        for(j = 0, r = result.begin(); incomplete && j < len && r != result.end(); ++j, ++r) {
            mem.ReadDelay(4); // Read multiplier
            mem.ReadDelay(8); // Read storing variable
            mem.ReadDelay(1); // Read MSB of multiplicant
            for (size_t k = 0; incomplete && k < multipliers[j][i]; ++k) {
                *r += multiplicants[j];
            }
            usleep(8);
            mem.WriteDelay(8); // Write output to memory
        }
    }
    gettimeofday(&end, nullptr);
    
    gettimediff(start, end, time_taken);
    return time_taken;
}