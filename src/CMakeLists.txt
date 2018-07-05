
MESSAGE(STATUS "Created Library Moriorgames DNA")

add_library(
        moriorgames_dna
        MoriorGames/Parsers/FileParser.cpp MoriorGames/Parsers/FileParser.h)

target_link_libraries(moriorgames_dna)
