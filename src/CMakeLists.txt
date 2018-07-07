
MESSAGE(STATUS "Created Library Moriorgames DNA")

add_library(
        moriorgames_dna
        MoriorGames/Containers/Population.cpp
        MoriorGames/DTO/Configuration.cpp
        MoriorGames/DTO/DNA.cpp
        MoriorGames/Parsers/FileParser.cpp
        MoriorGames/Parsers/JsonParser.cpp
        MoriorGames/Services/FitnessCalculator.cpp
        MoriorGames/Services/Mutator.cpp MoriorGames/Services/Mutator.h MoriorGames/Services/NaturalSelection.cpp MoriorGames/Services/NaturalSelection.h MoriorGames/Services/Randomizer.cpp MoriorGames/Services/Randomizer.h)

target_link_libraries(moriorgames_dna)
