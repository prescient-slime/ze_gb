#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include <cstddef>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <print>
#include <ranges>
#include <vector>

struct cartridge {
  std::vector<std::byte> data;
  auto load_rom(std::filesystem::path const &rom_path) -> void {
    std::ifstream rom_stream{rom_path, std::ios::binary | std::ios::in};
    std::error_code error{};
    auto rom_size{std::filesystem::file_size(rom_path, error)};
    if (error) {
      std::print(std::cerr, "Failed to get ROM size: {}", error.message());
    }
    data.resize(rom_size);
    if (!rom_stream.read(reinterpret_cast<char *>(data.data()),
                         static_cast<std::streamsize>(rom_size))) {
      throw std::runtime_error{"Failed to read " + rom_path.string()};
    }
  }
  auto print_rom() -> void {
    for (auto const &chunk : data | std::views::chunk(0x10)) {
      std::print("[ ");
      for (auto const &b : chunk) {
        std::print("{:02x} ", static_cast<unsigned>(b));
      }
      std::print("]\n");
    }
  }
};

#endif
