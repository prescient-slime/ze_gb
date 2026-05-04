#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include <filesystem>
#include <vector>

class cartridge
{
public:
    cartridge() = default;
    cartridge(cartridge&& other) = delete;
    cartridge(cartridge& other) = delete;

    auto load_rom(std::string path) -> void;
    [[nodiscard]] auto read_byte(uint16_t target) noexcept -> char;
    [[nodiscard]] auto read_bytes(uint16_t target) noexcept -> std::vector<char>;

private:
    std::filesystem::path rom_path;
    std::vector<char> rom_data;
};

#endif
