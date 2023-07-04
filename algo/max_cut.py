from collections import defaultdict

# Function to find cycles in the graph using depth-first search
def find_cycles(graph):
    visited = set()
    cycle_edges = set()

    for node in graph:
        if node not in visited:
            dfs_cycle(graph, node, visited, node, cycle_edges)

    return cycle_edges

# Depth-first search to detect cycles and mark edges to be removed
def dfs_cycle(graph, current_node, visited, parent_node, cycle_edges):
    visited.add(current_node)

    for neighbor in graph[current_node]:
        if neighbor not in visited:
            dfs_cycle(graph, neighbor, visited, current_node, cycle_edges)
        elif neighbor != parent_node:
            # Cycle detected
            cycle_edges.add(tuple(sorted((current_node, neighbor))))

# Function to find the edges to be removed from cycles
def find_edges_to_remove(graph):
    cycle_edges = find_cycles(graph)

    return cycle_edges

# Example graph represented as an adjacency list
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D'],
    'C': ['A', 'D'],
    'D': ['B', 'C','E'],
    'E' : ['D','F','H'],
    'F' : ['E','G'],
    'G' : ['F','H'],
    'H' : ['E','G']
}

# Find the edges to be removed from cycles
edges_to_remove = find_edges_to_remove(graph)

print("Edges to be removed from cycles:")
for edge in edges_to_remove:
    print(edge)
