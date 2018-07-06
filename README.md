You know nothing, Jon Snow
==========================

You Know nothing, Jon Snow, is a dummy project to test a Genetic Algorithm in C++ trying to solve the problem of finding a particular string.


To run the project:

```
$ cmake .
$ make
$ ./main
$ cmake . && make && ./main
```

## How it works

Demonstration of using a genetic algorithm to perform a search

- Setup:
    - Step 1: The Population
        - Create a vector of empty population.
        - Fill the population with a DNA random values.

- Draw:
    - Step 1: Selection
        - Create an empty mating pool vector.
        - For every member of the population, evaluate its fitness based on some criteria.
        - Add this population to a mating pool according with its fitness.
        - More fit it's more likely picked for reproduction.
    - Step 2: Reproduction
        - Pick two "parent" objects from the mating pool.        
        - Crossover: Create a "child" object by mating these two parents.        
        - Mutation: Mutate the child's DNA based on a given probability.        
        - Add the child object to the new population.
    - Step 3: New generation
        - Replace the old population with the new population.
        - Repeat the process until find the expected target.
