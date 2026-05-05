#include "cart/cartridge.h"

#include <algorithm>
#include <format>
#include <iostream>
#include <print>
#include <ranges>

auto main(int argc, char* argv[]) -> int
{
    cartridge cart{};
    cart.load_rom(argv[1]);
    std::print("Loading rom {}\n", argv[1]);
    return 0;
}
