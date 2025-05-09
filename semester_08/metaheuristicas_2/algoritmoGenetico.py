import random
from typing import List


class Item:
    def __init__(self, name, value, weight):
        self.name = name
        self.weight = weight
        self.value = value


class Individual:
    def __init__(self, bits: List[int]):
        self.bits = bits

    def __str__(self):
        return repr(self.bits)

    def __hash__(self):
        return hash(str(self.bits))

    def fitness(self) -> float:
        total_value = sum([bit * item.value for item, bit in zip(items, self.bits)])

        total_weight = sum([bit * item.weight for item, bit in zip(items, self.bits)])

        if total_weight <= MAX_KNAPSACK_WEIGHT:
            return total_value

        return 0


MAX_KNAPSACK_WEIGHT = 879
CROSSOVER_RATE = 0.33
MUTATION_RATE = 0.013
REPRODUCTION_RATE = 0.15

items = [Item("A", 91, 84), Item("B", 72, 83), Item("C", 90, 43), Item("D", 46, 4), Item("E",55,44), Item("F",8,6),Item("G",35,82), Item("H",75,92), Item("I",61,25),Item("J",15,83), Item("K",77,56), Item("L",40,18),Item("M",63,58),Item("N",75,14),Item("O",29,48),Item("P",75,70),Item("Q",17,96),Item("R",78,32), Item("S",40,68),Item("T",44,92)]


def generate_initial_population(count=6) -> List[Individual]:
    population = set()

    # generate initial population having `count` individuals
    while len(population) != count:
        # pick random bits one for each item and
        # create an individual
        bits = [random.choice([0, 1]) for _ in items]
        population.add(Individual(bits))

    return list(population)


### Cambiar a seleccion por ruleta
def selection(population: List[Individual]) -> List[Individual]:
    parents = []
    fitness_list = []
    relative_fitness = []
    comulative_fitness = []
    total_fitness = 0

    # TOTAL FITNESS
    for i in range(len(population)):
        ind_fitness = population[i].fitness()
        total_fitness += ind_fitness
        fitness_list.append(ind_fitness)

    # RELATIVE FITNESS
    for i in range(len(fitness_list)):
        ind_fitness = fitness_list[i] / total_fitness
        relative_fitness.append(ind_fitness)

    # COMULATIVE FITNESS
    comulative_fitness.append(relative_fitness[0])
    for i in range(1, len(relative_fitness)):
        comulative_fitness.append(comulative_fitness[i - 1] + relative_fitness[i])

    # SELECCION RULETA
    for i in range(len(population)):
        r = random.random()
        for i, cum_fit in enumerate(comulative_fitness):
            if r <= cum_fit:
                parents.append(population[i])
                break

    return parents


# Remplazar a un punto de corte
def crossover(parents: List[Individual]) -> List[Individual]:
    PC=random.randint(0, len(items))

    child1 = parents[0].bits[:PC] + parents[1].bits[PC:]
    child2 = parents[1].bits[PC:] + parents[0].bits[:PC]

    return [Individual(child1), Individual(child2)]



def mutate(individuals: List[Individual]) -> List[Individual]:
    for individual in individuals:
        for i in range(len(individual.bits)):
            if random.random() < MUTATION_RATE:
                # Flip the bit
                individual.bits[i] = ~individual.bits[i]


def next_generation(population: List[Individual]) -> List[Individual]:
    next_gen = []
    while len(next_gen) < len(population):
        children = []

        # we run selection and get parents
        parents = selection(population)

        # reproduction
        if random.random() < REPRODUCTION_RATE:
            children = parents
        else:
            # crossover
            if random.random() < CROSSOVER_RATE:
                children = crossover(parents)

            # mutation
            if random.random() < MUTATION_RATE:
                mutate(children)

        next_gen.extend(children)

    return next_gen[: len(population)]


def print_generation(population: List[Individual]):
    for individual in population:
        print(individual.bits, individual.fitness())
    print()
    print("Average fitness", sum([x.fitness() for x in population]) / len(population))
    print("-" * 32)


def average_fitness(population: List[Individual]) -> float:
    return sum([i.fitness() for i in population]) / len(population)


def solve_knapsack() -> Individual:
    population = generate_initial_population()

    avg_fitnesses = []

    for _ in range(100):
        avg_fitnesses.append(average_fitness(population))
        population = next_generation(population)
        print_generation(population)

    population = sorted(population, key=lambda i: i.fitness(), reverse=True)
    return population[0]


if __name__ == "__main__":
    solution = solve_knapsack()
    print(solution, solution.fitness())

