#include "mt19937predictor.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::vector<uint32_t> data(624);
    auto b = generator()%10000;
    for (int i = 0; i < b; i++) generator();
    for (auto& a: data) a = generator();
    std::mt19937 predictor = mt19937_predictor(data);
    std::cout << "Original generator:\t" << generator() << std::endl << "Prediction:\t\t" << predictor() << std::endl;
    return 0;
}
