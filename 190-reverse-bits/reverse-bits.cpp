#include <iostream>
#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        for (int i = 0; i < 32; i++) {
            // Shift result left to make room for the next bit
            result <<= 1;

            // Add the last bit of n
            result |= (n & 1);

            // Unsigned right shift
            n >>= 1;
        }

        return result;
    }
};