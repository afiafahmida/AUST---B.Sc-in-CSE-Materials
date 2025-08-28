graph_data = [
    ('i', 'a', 35), ('a', 'i', 35), ('i', 'b', 45), ('b', 'i', 45),
    ('a', 'c', 22), ('c', 'a', 22), ('a', 'd', 32), ('d', 'a', 32),
    ('b', 'd', 28), ('d', 'b', 28), ('b', 'e', 36), ('e', 'b', 36),
    ('b', 'f', 27), ('f', 'b', 27), ('c', 'd', 31), ('d', 'c', 31),
    ('c', 'g', 47), ('g', 'c', 47), ('d', 'g', 30), ('g', 'd', 30),
    ('e', 'g', 26), ('g', 'e', 26)
]

heuristics = {
    'i': 80, 'a': 55, 'b': 42, 'c': 34,
    'd': 25, 'e': 20, 'f': 17, 'g': 0
}

def get_neighbors(node):
    return [(dst, cost) for src, dst, cost in graph_data if src == node]


def a_star_search(start, goal):
    open_list = [(heuristics[start], 0, start, [start])]
    closed_set = set()

    while open_list:
        f_score, g_score, current_node, path = min(open_list)
        open_list.remove((f_score, g_score, current_node, path))

        if current_node == goal:
            return path, g_score

        closed_set.add(current_node)

        for neighbor, cost in get_neighbors(current_node):
            if neighbor not in closed_set:
                new_g_score = g_score + cost
                new_f_score = new_g_score + heuristics[neighbor]
                new_path = path + [neighbor]
                open_list.append((new_f_score, new_g_score, neighbor, new_path))

    return None, float('inf')


def display(path, cost):
    if path:
        print("Path:", path)
        print("Cost:", cost)
    else:
        print("No path found")


def main():
    start_node = 'i'
    goal_node = 'g'
    path, cost = a_star_search(start_node, goal_node)
    display(path, cost)

if __name__ == "__main__":
    main()
