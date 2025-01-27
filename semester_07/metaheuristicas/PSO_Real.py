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
    loads = np.zeros(num_processors)
    for task, processor in enumerate(particle):
        loads[processor] += times[task]
    return np.max(loads)


# PSO function
def run_pso(times):
    num_tasks = len(times)
    particles = np.random.randint(0, num_processors, size=(num_particles, num_tasks))
    # print the size of a particle
    print(particles[0].shape)
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
    best_assignment, parallel_time = run_pso(times)
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

# Create graph
plt.figure(figsize=(12, 6))
plt.plot(df["Batch Size"], df["Sequential Time"], label="Sequential Time")
plt.plot(df["Batch Size"], df["Parallel Time"], label="Parallel Time")
plt.xlabel("Batch Size")
plt.ylabel("Processing Time")
plt.title("Sequential vs Parallel Processing Time")
plt.legend()
plt.grid(True)
plt.show()

# Create speedup graph
plt.figure(figsize=(12, 6))
plt.plot(df["Batch Size"], df["Speedup"])
plt.xlabel("Batch Size")
plt.ylabel("Speedup")
plt.title("Speedup vs Batch Size")
plt.grid(True)
plt.show()
