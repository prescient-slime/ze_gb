#include "cart/cartridge.h"

#include <format>
#include <print>
#include <span>

auto main(int argc, char *argv[]) -> int {
  std::span<char *> args{argv, static_cast<size_t>(argc)};
  cartridge cart{};
  cart.load_rom(args[1]);
  std::print("Loading rom {}\n", args[1]);
  std::print("ROM:\n");
  cart.print_rom();
  return 0;
}
