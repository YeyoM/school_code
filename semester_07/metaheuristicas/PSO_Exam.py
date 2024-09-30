import numpy as np
import matplotlib.pyplot as plt
import json
import pandas as pd

# Load data from JSON
with open("reviews.json") as file:
    tasks = json.load(file)

# Extract processing times
processing_times = np.array([task["time"] for task in tasks])

# Number of processors
num_processors = 8

# PSO parameters
num_particles = 30
num_iterations = 10

# PSO parameters
w = 0.5  # inertia weight
c1 = 1  # cognitive parameter
c2 = 2  # social parameter


# Fitness function
def calculate_fitness(particle, times):
    # each particle follows the following structure:
    # particle = [0, 3, 7, 2, 5, 1, 6, 4]
    # where the index represents the task and the value represents the processor
    # so to calculate the fitness we need the sum of the processing times for each processor
    # and then take the maximum of those sums
    loads = np.zeros(num_processors)
    for task, processor in enumerate(particle):
        loads[processor] += times[task]
    return np.max(loads)


# PSO function
def run_pso(times):
    num_tasks = len(times)
    particles = np.random.randint(0, num_processors, size=(num_particles, num_tasks))
    personal_best_positions = particles.copy()
    personal_best_fitness = np.full(num_particles, np.inf)
    global_best_position = particles[0].copy()
    global_best_fitness = np.inf
    velocities = np.zeros_like(particles, dtype=float)

    for _ in range(num_iterations):
        fitness = np.array([calculate_fitness(p, times) for p in particles])
        improved = fitness < personal_best_fitness
        personal_best_positions[improved] = particles[improved]
        personal_best_fitness[improved] = fitness[improved]
        if np.min(fitness) < global_best_fitness:
            global_best_index = np.argmin(fitness)
            global_best_position = particles[global_best_index].copy()
            global_best_fitness = fitness[global_best_index]
        r1, r2 = np.random.rand(2, num_particles, num_tasks)
        velocities = (
            w * velocities
            + c1 * r1 * (personal_best_positions - particles)
            + c2 * r2 * (global_best_position - particles)
        )
        particles = np.clip(particles + velocities.astype(int), 0, num_processors - 1)
        print(f"Iteration: {_ + 1}, Best Fitness: {global_best_fitness}")

    return global_best_position, global_best_fitness


# Function to process batches
def process_batch(batch_size):
    times = processing_times[:batch_size]
    _, parallel_time = run_pso(times)
    sequential_time = np.sum(times)
    return sequential_time, parallel_time


# Process batches
batch_sizes = range(10000, 110000, 10000)
results = []

for batch_size in batch_sizes:
    sequential_time, parallel_time = process_batch(batch_size)
    results.append(
        {
            "Batch Size": batch_size,
            "Sequential Time": sequential_time,
            "Parallel Time": parallel_time,
            "Speedup": sequential_time / parallel_time,
        }
    )
# Create DataFrame
df = pd.DataFrame(results)

# Print table
print(df.to_string(index=False))


# Function to create and save plots
def save_plot(x, y, xlabel, ylabel, title, filename):
    plt.figure(figsize=(12, 6))
    if isinstance(y, dict):
        for key, values in y.items():
            plt.plot(x, values, label=key)
        plt.legend()
    else:
        plt.plot(x, y)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.title(title)
    plt.grid(True)
    plt.savefig(filename, dpi=300, bbox_inches="tight")
    plt.close()


# Create and save comparison graph
save_plot(
    df["Batch Size"],
    {"Sequential Time": df["Sequential Time"], "Parallel Time": df["Parallel Time"]},
    "Batch Size",
    "Processing Time",
    "Sequential vs Parallel Processing Time",
    "processing_time_comparison.png",
)

# Create and save speedup graph
save_plot(
    df["Batch Size"],
    df["Speedup"],
    "Batch Size",
    "Speedup",
    "Speedup vs Batch Size",
    "speedup.png",
)

print("Plots have been saved as 'processing_time_comparison.png' and 'speedup.png'.")
