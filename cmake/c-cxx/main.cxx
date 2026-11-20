#include <iostream>

extern "C" int binary_log(int n);

int main(int argc, const char *argv[]) {
    std::cout << binary_log(std::stoi(argv[1])) << '\n';

    return 0;
}
