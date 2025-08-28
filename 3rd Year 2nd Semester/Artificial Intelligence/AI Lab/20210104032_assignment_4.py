import random

N_QUEENS = 8
POPULATION_SIZE = 50
MUTATION_RATE = 0.1
CROSSOVER_RATE = 0.8
GENERATIONS = 1000
FITNESS_THRESHOLD = 28


def generate_initial_population():
    population = []

    population.append([7, 0, 3, 6, 2, 5, 1, 6])

    for _ in range(14):
        individual = list(range(1, N_QUEENS + 1))
        random.shuffle(individual)
        population.append(individual)
    return population


def mutate(individual):
    if random.random() < MUTATION_RATE:
        i, j = random.sample(range(N_QUEENS), 2)
        individual[i], individual[j] = individual[j], individual[i]
    return individual


def crossover(parent1, parent2):
    if random.random() > CROSSOVER_RATE:
        return parent1, parent2

    crossover_point = random.randint(1, N_QUEENS - 1)
    child1 = parent1[:crossover_point] + parent2[crossover_point:]
    child2 = parent2[:crossover_point] + parent1[crossover_point:]
    return child1, child2


def fitness(state):
    non_attacking_pairs = 0
    for i in range(N_QUEENS):
        for j in range(i + 1, N_QUEENS):
            if state[i] != state[j] and abs(state[i] - state[j]) != abs(i - j):
                non_attacking_pairs += 1
    return non_attacking_pairs


def genetic_algorithm():
    population = generate_initial_population()
    generation = 0
    best_solution = None
    best_fitness = FITNESS_THRESHOLD

    while generation < GENERATIONS:
        new_population = []

        for individual in population:
            mutated_individual = mutate(individual)
            individual_fitness = fitness(mutated_individual)
            if individual_fitness < best_fitness:
                best_solution = mutated_individual
                best_fitness = individual_fitness
            new_population.append(mutated_individual)

        print(f"Generation {generation}: Best solution: {best_solution}, Fitness: {best_fitness}")

        population = new_population
        generation += 1

        if best_fitness == FITNESS_THRESHOLD:
            print("Targeted fitness found in the Exiting the generations.")
            break

    if best_fitness != 0:
        print("Targeted fitness not found within the generations.")


genetic_algorithm()
