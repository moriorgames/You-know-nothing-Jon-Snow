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
        - Fill the population with a DNA random values *Population::initialize()*.

- Process:
    - Step 1: Selection
        - For every member of the population, evaluate its fitness based on some criteria *Population::calculateFitness()*.
        - Sort all the DNA by fitness *Population::sortByFitness()*.
        - Check if any of the given DNA is the perfect solution we are looking for *Population::evaluate(int generation)*.
        - Apply the environment extinction over less fitness DNA *Population::environmentExtinction()*.
        - Process the new generation *Population::newGeneration*.
        - Add the remaining population to a mating pool according with its fitness.
        - More fit it's more likely picked for reproduction.
    - Step 2: Reproduction
        - Pick two "parent" objects from the mating pool.        
        - Crossover: Create N random "child" object by mating these two parents.        
        - Mutation: Mutate the child's DNA based on a given probability.        
        - Add the child object to the new population.
    - Step 3: New generation
        - Replace the old population with the new population.
        - Repeat the process until find the expected target.

## Running in Docker container

Create a docker container, install all dependencies and build the project with cmake.
This will give us an image with the compiled application ready to *run* and *test*.

* To create the docker image
```
$ docker build -t moriorgames/dna .
```

* Run the container
```
$ docker run -td --name moriorgames_dna moriorgames/dna
```

* Execute the program
```
$ docker exec -ti moriorgames_dna ./main
```

* Execute the Tests
```
$ docker exec -ti moriorgames_dna ./tests/testsuite
```

* Execute the code coverage locally
```
$ sh scripts/coverage.sh
```


## Sample of output

```
.
.
.
==: Generation 118 Population 164
- genes: you know notbing, jon snow Fitness: 0.961538
- genes: you know notging, jon snow Fitness: 0.961538
- genes: you know notying, jon snow Fitness: 0.961538
- genes: you know notring, jon snow Fitness: 0.961538
- genes: you know notbing, jon snow Fitness: 0.961538
- genes: you know notbing, jon snow Fitness: 0.961538
- genes: you know notbing, jon snow Fitness: 0.961538
- genes: you know notring, jon snow Fitness: 0.961538
- genes: you know notbing, jon snow Fitness: 0.961538
- genes: you know notbing, jon snow Fitness: 0.961538
==: Generation 119 Population 154
==== We found the perfect solution at Generation 119 ==
- genes: you know nothing, jon snow Fitness: 1.000000
- genes: you know nothing, jon snow Fitness: 1.000000
- genes: you know notbing, jon snow Fitness: 0.961538
- genes: you know notbing, jon snow Fitness: 0.961538
- genes: you know notbing, jon snow Fitness: 0.961538
- genes: you know notbing, jon snow Fitness: 0.961538
- genes: you know notbing, jon snow Fitness: 0.961538
- genes: you know notbing, jon snow Fitness: 0.961538
- genes: you know notbing, jon snow Fitness: 0.961538
- genes: you know notbing, jon snow Fitness: 0.961538
- genes: you know notbing, jon snow Fitness: 0.961538

Elapsed time 13.414517
```
