import heapq

def heuristic(state, goal):
    distance = 0

    for i in range(9):
        if state[i] != 0:
            goal_index = goal.index(state[i])
            distance += abs(i // 3 - goal_index // 3) + abs(i % 3 - goal_index % 3)

    return distance


def get_neighbors(state):
    neighbors = []
    zero = state.index(0)
    row, col = zero // 3, zero % 3

    for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        nr, nc = row + dr, col + dc

        if 0 <= nr < 3 and 0 <= nc < 3:
            new_zero = nr * 3 + nc
            new_state = list(state)

            new_state[zero], new_state[new_zero] = new_state[new_zero], new_state[zero]
            neighbors.append(tuple(new_state))

    return neighbors


def solve(start, goal):
    pq = []
    heapq.heappush(pq, (heuristic(start, goal), 0, start))

    parent = {start: None}
    cost = {start: 0}

    while pq:
        f, g, state = heapq.heappop(pq)

        if state == goal:
            path = []

            while state is not None:
                path.append(state)
                state = parent[state]

            return path[::-1]

        if g != cost[state]:
            continue

        for neighbor in get_neighbors(state):
            new_cost = g + 1

            if neighbor not in cost or new_cost < cost[neighbor]:
                cost[neighbor] = new_cost
                parent[neighbor] = state

                priority = new_cost + heuristic(neighbor, goal)
                heapq.heappush(pq, (priority, new_cost, neighbor))

    return None


start = tuple(map(int, input("Enter initial state (9 numbers): ").split()))
goal = tuple(map(int, input("Enter goal state (9 numbers): ").split()))

path = solve(start, goal)

if path:
    print("Solution found in", len(path) - 1, "moves")

    for state in path:
        for i in range(0, 9, 3):
            print(state[i:i + 3])
        print()
else:
    print("No solution found")
