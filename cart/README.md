# The Cartridge

## Cartridge Header

The cartridge header contains information about the cartridge as well as the
hardware it expects to run on.

## MBC

Most GameBoy games are larger than the ram provided by the SoC in the GameBoy
itself. To address this, cartridges contain a component called the `MBC`, or
"Memory Bank Controller", which expands the available address space for the
system via bank switching.
