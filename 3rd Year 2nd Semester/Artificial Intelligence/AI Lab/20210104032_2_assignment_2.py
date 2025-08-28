queens = [(1, 6), (2, 1), (3, 5), (4, 7), (5, 4), (6, 3), (7, 8), (8, 1)]

h = 0  # Initialize the heuristic counter
k=0
for i in range(8):
    for j in range(i + 1, 8):
        if queens[i][0] == queens[j][0] or queens[i][1] == queens[j][1]:
            h += 1
            k = h
        # Check for diagonals
        elif abs(queens[i][0] - queens[j][0]) == abs(queens[i][1] - queens[j][1]):
            h += 1
            k = h
    print(i+1, " ", k)
print("Heuristic (number of attacking pairs):", h)
