#ifndef MULT_HPP
#define MULT_HPP

#include <vector>
#include "Common.hpp"

class Multiplier {
protected:
    const Memory &mem;
public:
    inline Multiplier(const Memory &mem_unit) : mem(mem_unit) {}
    virtual timeval operator()(const std::vector<std::vector<unsigned int>> &multipliers, const std::vector<unsigned int> &multiplicants, std::vector<unsigned long long> &result) = 0;
};

class ApproxMultiplier : public Multiplier {
public:
    inline ApproxMultiplier(const Memory &mem_unit) : Multiplier(mem_unit) {}
    inline ApproxMultiplier(Memory &&mem_unit) : Multiplier(mem_unit) {}
    timeval operator()(const std::vector<std::vector<unsigned int>> &multipliers, const std::vector<unsigned int> &multiplicants, std::vector<unsigned long long> &result) override;
};

class GeneralMultiplier : public Multiplier {
public:
    inline GeneralMultiplier(const Memory &mem_unit) : Multiplier(mem_unit) {}
    inline GeneralMultiplier(Memory &&mem_unit) : Multiplier(mem_unit) {}
    timeval operator()(const std::vector<std::vector<unsigned int>> &multipliers, const std::vector<unsigned int> &multiplicants, std::vector<unsigned long long> &result) override;
};

#endif