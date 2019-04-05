#include "Multiplier.hpp"

using namespace std;

timeval GeneralMultiplier::operator()(const std::vector<std::vector<unsigned int>> &multipliers, const std::vector<unsigned int> &multiplicants, std::vector<unsigned long long> &result) {
    timeval start, end, time_taken;
    size_t j, len = multipliers.size();
    vector<unsigned long long>::iterator r;

    gettimeofday(&start, nullptr);
    for(j = 0, r = result.begin(); j < len && r != result.end(); ++j, ++r) {
        for(int i = 0; i < sizeof(unsigned int); ++i) {
            mem.ReadDelay(4); // Read multiplier
            mem.ReadDelay(8); // Read storing variable
            mem.ReadDelay(4); // Read multiplicant
            for (size_t k = 0; k < multipliers[j][i]; ++k) {
                *r += multiplicants[j];
            }
            usleep(32);
            mem.WriteDelay(8); // Write output to memory
        }
    }
    gettimeofday(&end, nullptr);

    gettimediff(start, end, time_taken);

    return time_taken;
}

