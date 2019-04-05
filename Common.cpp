#include "Common.hpp"

void gettimediff(timeval &start, timeval &end, timeval &time_diff) {
    time_diff.tv_sec = end.tv_sec - start.tv_sec;
    time_diff.tv_usec = end.tv_usec - start.tv_usec;
    time_diff.tv_usec = (time_diff.tv_usec < 0 ? (--time_diff.tv_sec , time_diff.tv_usec+1000000) : time_diff.tv_usec);
}

/**
 *    Delay while reading from memory.
 * 
 *    @param {unsigned short} num_bytes (number of bytes to read from memory).
 */
void Memory::ReadDelay(unsigned short num_bytes) const {
    while(num_bytes--) {
        usleep(read);
    }
}

/**
 * Delay when writing to memory.
 * 
 * @param {unsigned short} num_bytes (number of bytes to write to memory).
 */
void Memory::WriteDelay(unsigned short num_bytes) const {
    while(num_bytes--){
        usleep(write);
    }
}