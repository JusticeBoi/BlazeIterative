#include "BlazeIterative.hpp"
#include <iostream>

using namespace blaze;
using namespace blaze::iterative;

int main() {

    auto B = ReadMtxFormatBlaze<CompressedMatrix<double>>("1138_bus.mtx");
    std::cout << B <<'\n';
    return 0;
}
