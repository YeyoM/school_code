import json
import random


class Particle:
    def __init__(self, dimension):
        self.position = [random.randint(0, len(tasks) - 1) for _ in range(dimension)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimension)]
        self.best_position = self.position.copy()
        self.best_fitness = float("inf")
        self.fitness = float("inf")

    def evaluate(self, fitness_func):
        self.fitness = fitness_func(self.position)
        if self.fitness < self.best_fitness:
            self.best_position = self.position.copy()
            self.best_fitness = self.fitness


def load_tasks(filename):
    with open(filename, "r") as f:
        data = json.load(f)
    return data


def calculate_fitness(positions):
    processor_times = [0] * num_processors
    for i, task_index in enumerate(positions):
        processor_times[i % num_processors] += tasks[task_index]["time"]
    return max(processor_times)


def update_velocity(particles, global_best):
    w = 0.5  # inertia weight
    c1 = 1.5  # cognitive parameter
    c2 = 1.5  # social parameter
    for particle in particles:
        for i in range(len(particle.position)):
            r1, r2 = random.random(), random.random()
            particle.velocity[i] = (
                w * particle.velocity[i]
                + c1 * r1 * (particle.best_position[i] - particle.position[i])
                + c2 * r2 * (global_best[i] - particle.position[i])
            )


def update_position(particles):
    for particle in particles:
        for i in range(len(particle.position)):
            particle.position[i] = int(
                particle.position[i] + particle.velocity[i]
            ) % len(tasks)


def main():
    global_best = particles[0].position.copy()
    global_best_fitness = float("inf")

    for iteration in range(num_iterations):
        for particle in particles:
            particle.evaluate(calculate_fitness)

            if particle.fitness < global_best_fitness:
                global_best = particle.position.copy()
                global_best_fitness = particle.fitness

        update_velocity(particles, global_best)
        update_position(particles)

    # Assign tasks to processors based on global best position
    assignments = {p: [] for p in range(num_processors)}
    for i, task_index in enumerate(global_best):
        assignments[i % num_processors].append(task_index)

    # Calculate sequential and parallel processing times
    seq_time = sum(task["time"] for task in tasks)
    par_time = max(
        sum(tasks[i]["time"] for i in processor) for processor in assignments.values()
    )

    # Display statistics
    print("Load Balancing Results:")
    print(f"Sequential processing time: {seq_time:.2f} seconds")
    print(f"Parallel processing time: {par_time:.2f} seconds")
    print(f"Speedup: {seq_time / par_time:.2f}x")
    print("\nProcessor Assignments:")
    for i, processor_tasks in assignments.items():
        total_time = sum(tasks[task_index]["time"] for task_index in processor_tasks)
        print(f"Processor {i+1}:")
        print(f"  Tasks completed: {len(processor_tasks)}")
        print(f"  Total time: {total_time:.2f} seconds")
        print(f"  Task indices: {processor_tasks[0:15]}")
        print()


if __name__ == "__main__":
    filename = "reviews.json"
    num_processors = 8
    num_particles = 8
    num_iterations = 100

    tasks = load_tasks(filename)
    particles = [Particle(len(tasks)) for _ in range(num_particles)]

    main()
