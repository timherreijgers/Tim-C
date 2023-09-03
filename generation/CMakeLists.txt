set(GENERATION_SOURCES
        src/assembly_program.cpp
        src/generation_factory.cpp
        src/x64_generation.cpp
        src/x64_generation.h)

set(GENERATION_HEADERS
        include/generation/architecture.h
        include/generation/assembly_program.h
        include/generation/igeneration.h
        include/generation/generation_factory.h)

add_library(generation ${GENERATION_SOURCES} ${GENERATION_HEADERS})

target_include_directories(generation PUBLIC include)

target_link_libraries(generation PUBLIC parser)

