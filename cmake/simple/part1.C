#include <iostream>
#include <format>

int calc(int x) {
    return x * x;
}

int main(int argc, char **argv) {
    std::cout << std::format("{} {}", calc(3), "qwerty") << std::endl;
}
