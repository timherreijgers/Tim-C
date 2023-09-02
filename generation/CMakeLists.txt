set(GENERATION_SOURCES
        src/generation_factory.cpp
        src/x64_generation.cpp)

set(GENERATION_HEADERS
        include/generation/igeneration.h
        include/generation/generation_factory.h)

add_library(generation ${GENERATION_SOURCES} ${GENERATION_HEADERS})

target_include_directories(generation PUBLIC include)

