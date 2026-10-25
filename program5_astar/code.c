
def astar(graph, h, start, goal):
    open_list = [start]
    cost = {start: 0}
    parent = {start: None}

    while open_list:
        current = min(open_list, key=lambda n: cost[n] + h[n])
        open_list.remove(current)

        print("Visiting:", current)

        if current == goal:
            path = []

            while current is not None:
                path.append(current)
                current = parent[current]

            path.reverse()

            print("Goal found!")
            print("Path:", " -> ".join(path))
            print("Cost:", cost[goal])
            return

        for neighbor, weight in graph[current]:
            new_cost = cost[current] + weight

            if neighbor not in cost or new_cost < cost[neighbor]:
                cost[neighbor] = new_cost
                parent[neighbor] = current

                if neighbor not in open_list:
                    open_list.append(neighbor)

    print("Goal not found")


graph = {}
n = int(input("Enter number of nodes: "))

for i in range(n):
    node = input("Enter node name: ")
    graph[node] = []

    neighbors = input("Enter neighbors and costs (e.g. B 1 C 4): ").split()

    for j in range(0, len(neighbors), 2):
        neighbor = neighbors[j]
        weight = int(neighbors[j + 1])
        graph[node].append((neighbor, weight))

h = {}

for node in graph:
    h[node] = int(input("Enter heuristic for " + node + ": "))

start = input("Enter start node: ")
goal = input("Enter goal node: ")

astar(graph, h, start, goal)
