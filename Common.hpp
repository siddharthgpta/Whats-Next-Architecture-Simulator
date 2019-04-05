#ifndef COMMON_HPP
#define COMMON_HPP

#include <sys/time.h>
#include <unistd.h>

using timeval = struct timeval;

//change this later
extern bool started;
extern bool incomplete;

void gettimediff(timeval &start, timeval &end, timeval &time_diff);

class Memory {
    time_t read;
    time_t write;
public:
    inline Memory(time_t r, time_t w) : read(r), write(w) {}
    inline Memory(Memory &&mem) : read(mem.read), write(mem.write) {}
    inline Memory(Memory &mem) : read(mem.read), write(mem.write) {}
    void ReadDelay(unsigned short num_bytes) const;
    void WriteDelay(unsigned short num_bytes) const;
};

#endif