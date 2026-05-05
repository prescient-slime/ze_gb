#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include <cstdint>
#include <string>
#include <vector>

class Cartridge
{

public:
    virtual ~Cartridge() = default;
    auto operator=(const Cartridge&) -> Cartridge& = delete;
    auto operator=(Cartridge&&) -> Cartridge& = delete;
    Cartridge(Cartridge&& other) = delete;
    Cartridge(Cartridge& other) = delete;

    virtual auto load_rom(std::string const& path) -> void = 0;
    [[nodiscard]] virtual auto read_byte(uint16_t target) noexcept
        -> unsigned char = 0;

protected:
    Cartridge() = default;
};

class RomOnly : public Cartridge
{
public:
    RomOnly() = default;
    auto load_rom(std::string const& path) -> void override;
    [[nodiscard]] auto read_byte(uint16_t target) noexcept -> unsigned char override;

private:
    std::vector<unsigned char> header_data_;
    std::vector<unsigned char> data_;
};

#endif
