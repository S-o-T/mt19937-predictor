#include <random>
#include <sstream>
#include <vector>
#include <cstdint>

std::mt19937 mt19937_predictor(const std::vector<uint32_t>& dataSamples) {
    if (dataSamples.size() != 624) throw std::invalid_argument("mt19937_predictor(): Input vector size isn't equal 624.");
    std::stringstream serialisedState;

    for (int i = 0; i < 624; i++) {
        uint32_t y = dataSamples[i];
        y ^= (y >> 18);
        y ^= (y << 15) & 0xefc60000;
        y ^= ((y <<  7) & 0x9d2c5680) ^ ((y << 14) & 0x94284000) ^ ((y << 21) & 0x14200000) ^ ((y << 28) & 0x10000000);
        y ^= (y >> 11) ^ (y >> 22);
        serialisedState << y << " ";
    }

    std::mt19937 g;
    serialisedState >> g;
    return g;
}