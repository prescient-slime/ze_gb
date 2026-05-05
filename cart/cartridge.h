#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include <filesystem>
#include <vector>

class cartridge
{
    static constexpr uint32_t LOWER_RANGE{0x7FFF};
    static constexpr uint32_t UPPER_RANGE{0x7FFF};

public:
    cartridge() = default;
    cartridge& operator=(const cartridge&) = delete;
    cartridge& operator=(cartridge&&) = delete;
    cartridge(cartridge&& other) = delete;
    cartridge(cartridge& other) = delete;

    auto load_rom(std::string const& path) -> void;
    [[nodiscard]] auto read_byte(uint16_t target) noexcept -> char;
    [[nodiscard]] auto read_bytes(uint16_t target) noexcept -> std::vector<char>;
    auto get_data() -> std::vector<uint16_t>; // temporary. Remove later

private:
    std::filesystem::path rom_path_;
    std::vector<uint16_t> data_;
};

#endif
