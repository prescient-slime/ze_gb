#include "cartridge.h"

#include <filesystem>
#include <fstream>
#include <print>
#include <span>
#include <vector>

// auto RomOnly::read_byte(uint16_t target) noexcept -> std::byte {
//   return data_[target];
// }
//
// auto RomOnly::load_rom(std::string const &path) -> void {
//   std::ifstream rom_path{std::filesystem::path{path},
//                          std::ios::binary | std::ios::in};
//   auto file_size{std::filesystem::file_size(path)};
//   data_.resize(file_size);
//   rom_path.read(reinterpret_cast<char *>(data_.data()),
//                 static_cast<std::streamsize>(file_size));
//   load_header({data_.data(), data_.size()});
// }
//
// auto RomOnly::load_header(std::span<const std::byte> const &data) -> void {
//   std::print("Entry point: [ ");
//   for (auto b : data.subspan(0x100u, 4)) {
//     std::print("{:02x} ", std::to_integer<unsigned>(b));
//   }
//   std::print("]\n");
// }
