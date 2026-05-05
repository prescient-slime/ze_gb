set(headers cartridge.h)

set(sources cartridge.cpp)

add_library(cartridge)

target_sources(cartridge PRIVATE ${sources} PUBLIC FILE_SET HEADERS FILES ${headers})
