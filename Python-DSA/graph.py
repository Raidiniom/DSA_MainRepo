vertex_data = ['A', 'B', 'C', 'D']

adj_matrix = [
    [0, 1, 1, 1],
    [1, 0, 1, 0],
    [1, 1, 0, 0],
    [1, 0, 0, 0],
]

def print_adj_matrix(matrix):
    for row in matrix:
        print(row)

def print_connections(matrix, vertices):
    print("\nConnections for each vertex:")
    for i in range(len(vertices)):
        print(f"{vertices[i]}: ", end="")
        for j in range(len(vertices)):
            if matrix[i][j]:  # if there is a connection
                print(vertices[j], end=" ")
        print()

# print_adj_matrix(adj_matrix)
print_connections(adj_matrix, vertex_data)