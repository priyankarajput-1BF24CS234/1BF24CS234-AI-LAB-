
def dls(graph, node, goal, depth, path):
    print(node, end=" ")  # Show each node visited

    if node == goal:
        print("\nPath:", " -> ".join(path))
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
        print("\nSearching at depth", depth)
        print("Traversal:", end=" ")

        if dls(graph, start, goal, depth, [start]):
            print("\nGoal found at depth", depth)
            return

    print("\nGoal not found")


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
