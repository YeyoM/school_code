import random


def one_max_fitness(chromosome):
    """Return the sum of bits in the chromosome (number of 1s)"""
    return sum(chromosome)


def main_eda():
    # Parameters
    chromosome_length = 40
    population_size = 70
    generations = 100
    selection_ratio = 0.9  # Top 90% are selected

    # Initialize population randomly
    population = []
    for _ in range(population_size):
        chromosome = [random.randint(0, 1) for _ in range(chromosome_length)]
        population.append(chromosome)

    best_solution = None
    best_fitness = -1

    # Main EDA loop
    for generation in range(generations):
        # Evaluate fitness
        fitness_scores = [(one_max_fitness(chrom), chrom) for chrom in population]
        fitness_scores.sort(reverse=True)  # Sort by fitness (descending)

        # Store the best solution
        current_best_fitness, current_best = fitness_scores[0]
        if current_best_fitness > best_fitness:
            best_fitness = current_best_fitness
            best_solution = current_best.copy()

        # Print progress
        avg_fitness = sum(f for f, _ in fitness_scores) / population_size
        print(
            f"Generation {generation}: Best = {current_best_fitness}, Avg = {avg_fitness:.2f}"
        )

        # Check if solution found
        if best_fitness == chromosome_length:
            print(f"Perfect solution found in generation {generation}")
            break

        # Elitist selection - select top individuals
        selected_size = int(population_size * selection_ratio)
        selected = [chrom for _, chrom in fitness_scores[:selected_size]]

        # Estimate probability distribution
        probabilities = []
        for i in range(chromosome_length):
            # Probability of 1 at position i
            ones_count = sum(chrom[i] for chrom in selected)
            prob = ones_count / selected_size
            probabilities.append(prob)

        # Sample new population from the probability distribution
        new_population = []

        # Elitism: Keep the best solution
        new_population.append(fitness_scores[0][1])

        # Generate the rest of the population
        while len(new_population) < population_size:
            new_chrom = []
            for prob in probabilities:
                # Sample based on probability
                bit = 1 if random.random() < prob else 0
                new_chrom.append(bit)
            new_population.append(new_chrom)

        population = new_population

    print(f"Best solution: {best_solution}")
    print(f"Best fitness: {best_fitness}")
    return best_solution, best_fitness


# Run the algorithm
if __name__ == "__main__":
    best_solution, best_fitness = main_eda()
