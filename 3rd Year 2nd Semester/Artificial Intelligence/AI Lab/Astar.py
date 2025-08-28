import random

# Constants
POPULATION_SIZE = 10
MUTATION_RATE = 0.1
CROSSOVER_RATE = 0.8
TARGET_FITNESS = 28  # The maximum fitness value for the 8-Queens problem
MAX_GENERATIONS = 1000

def generate_initial_population():
    """Generate the initial population."""
    population = []
    # Add initial states
    population.append([7, 0, 3, 6, 2, 5, 1, 6])
    population.append([3, 0, 4, 7, 1, 6, 2, 5])
    population.append([0, 5, 7, 2, 6, 3, 1, 4])
    population.append([4, 7, 3, 0, 2, 5, 1, 6])
    population.append([5, 2, 4, 7, 0, 3, 1, 6])
    return population

def fitness(state):
    """Calculate the fitness of a state. Lower is better."""
    attacking_pairs = 0
    for i in range(len(state)):
        for j in range(i + 1, len(state)):
            if state[i] == state[j] or abs(state[i] - state[j]) == abs(i - j):
                attacking_pairs += 1
    return attacking_pairs

def select_parents(population):
    """Select two parents using tournament selection."""
    tournament_size = 3
    selected = random.sample(population, tournament_size)
    selected.sort(key=lambda x: fitness(x))
    return selected[0], selected[1]

def crossover(parent1, parent2):
    """Perform crossover between two parents."""
    if random.random() > CROSSOVER_RATE:
        return parent1, parent2

    crossover_point = random.randint(1, len(parent1) - 1)
    child1 = parent1[:crossover_point] + parent2[crossover_point:]
    child2 = parent2[:crossover_point] + parent1[crossover_point:]
    return child1, child2

def mutate(individual):
    """Perform mutation on an individual."""
    if random.random() < MUTATION_RATE:
        index = random.randint(0, len(individual) - 1)
        new_value = random.randint(0, len(individual) - 1)
        individual[index] = new_value
    return individual

def genetic_algorithm():
    """Main function to run the genetic algorithm."""
    population = generate_initial_population()
    iteration = 0

    while iteration < MAX_GENERATIONS:
        new_population = []

        for _ in range(POPULATION_SIZE // 2):
            parent1, parent2 = select_parents(population)
            child1, child2 = crossover(parent1, parent2)
            child1 = mutate(child1)
            child2 = mutate(child2)
            new_population.append(child1)
            new_population.append(child2)

        population = new_population
        iteration += 1

        best_solution = min(population, key=lambda x: fitness(x))
        best_fitness = fitness(best_solution)

        print(f"Iteration: {iteration}, Best Fitness: {best_fitness}, Best Solution: {best_solution}")

        if best_fitness == TARGET_FITNESS:
            print("Target fitness reached!")
            return best_solution

    print("Maximum generations reached. Best solution found:", best_solution)

# Run the genetic algorithm
solution = genetic_algorithm()
if fitness(solution) == TARGET_FITNESS:
    print("Solution of target fitness found:", solution)
else:
    print("No solution of target fitness found within the maximum generations.")
