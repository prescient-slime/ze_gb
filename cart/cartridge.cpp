#include "cartridge.h"

#include <filesystem>
#include <fstream>
#include <vector>

auto RomOnly::read_byte(uint16_t target) noexcept -> unsigned char
{
    return data_[target];
}

auto RomOnly::load_rom(std::string const& path) -> void
{
    std::basic_ifstream<unsigned char> rom_path{
        std::filesystem::path{path}, std::ios::binary | std::ios::in};
    auto file_size{std::filesystem::file_size(path)};
    data_.reserve(file_size);
    rom_path.read(data_.data(), static_cast<std::streamsize>(file_size));
}
