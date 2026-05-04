# The Cartridge

## Cartridge Header

The cartridge header contains information about the cartridge as well as the
hardware it expects to run on.

## MBC

Most GameBoy games are larger than the 32KB address space provided by the GameBoy
itself. To overcome this limitation, cartridges contain use something called the
`MBC`, or "Memory Bank Controller", which expands the available address space for the
system via bank switching.

## Design

### Responsibilities

The cartridge class must:

- Read various ROMs made for the GameBoy
- Serve ROM reads to other emulator components
- Implement necessary MBC logic
- Provide external RAM if specified by the loaded ROM
