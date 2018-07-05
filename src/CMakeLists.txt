
MESSAGE(STATUS "Created Library Moriorgames DNA")

add_library(
        moriorgames_dna
        MoriorGames/DTO/Configuration.cpp
        MoriorGames/Parsers/FileParser.cpp
)

target_link_libraries(moriorgames_dna)
