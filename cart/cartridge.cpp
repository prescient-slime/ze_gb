#include "cartridge.h"

#include <algorithm>
#include <fstream>
#include <vector>

auto cartridge::load_rom(std::string const& path) -> void
{
    std::ifstream rom_path{std::filesystem::path{path}, std::ios::binary | std::ios::in};
    rom_path.seekg(0, std::ios_base::beg);
    auto file_size{std::filesystem::file_size(path)};
    std::vector<char> char_data(file_size);
    rom_path.read(char_data.data(), static_cast<std::streamsize>(file_size));
    std::ranges::transform(
        char_data, data_.begin(), [](char char_datum) -> uint16_t { return char_datum; });
}

auto cartridge::get_data() -> std::vector<uint16_t>
{
    return data_;
}
