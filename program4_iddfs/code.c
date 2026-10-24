
def dls(graph, node, goal, depth, path):
    if node == goal:
        print("Path:", " -> ".join(path))
        return True

    if depth == 0:
        return False

    for neighbor in graph[node]:
        if neighbor not in path:
            if dls(graph, neighbor, goal, depth - 1, path + [neighbor]):
                return True

    return False


def ids(graph, start, goal, max_depth):
    for depth in range(max_depth + 1):
        print("Searching at depth:", depth)

        if dls(graph, start, goal, depth, [start]):
            print("Goal found at depth", depth)
            return

    print("Goal not found")


graph = {}
n = int(input("Enter number of nodes: "))

for i in range(n):
    node = input("Enter node name: ")
    neighbors = input("Enter neighbors separated by spaces: ").split()
    graph[node] = neighbors

start = input("Enter start node: ")
goal = input("Enter goal node: ")
max_depth = int(input("Enter maximum depth: "))

ids(graph, start, goal, max_depth)
