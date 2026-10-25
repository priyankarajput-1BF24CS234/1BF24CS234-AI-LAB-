
import random
import math

def simulated_annealing(start, temperature, cooling_rate, low, high):
    current = start
    best = current

    while temperature > 0.1:
        next_state = current + random.choice([-1, 1])

        if next_state < low or next_state > high:
            temperature *= cooling_rate
            continue

        delta = next_state**2 - current**2

        if delta > 0:
            current = next_state
        else:
            probability = math.exp(delta / temperature)

            if random.random() < probability:
                current = next_state

        if current**2 > best**2:
            best = current

        temperature *= cooling_rate

    print("Best state:", best)
    print("Maximum value:", best**2)


start = int(input("Enter initial state: "))
temperature = float(input("Enter initial temperature: "))
cooling_rate = float(input("Enter cooling rate (0 to 1): "))
low = int(input("Enter lower limit: "))
high = int(input("Enter upper limit: "))

if low <= start <= high and 0 < cooling_rate < 1 and temperature > 0:
    simulated_annealing(start, temperature, cooling_rate, low, high)
else:
    print("Invalid input")
