# Run Time: 0.020
while True:
    w, h = input().split()

    w = int(w)
    h = int(h)

    if w == 0 and h == 0:
        break

    road = [[1 for y in range(h + 1)] for x in range(w + 1)]

    num_of_locations = int(input())

    for n in range(num_of_locations):
        pos_x, pos_y = input().split()
        pos_x = int(pos_x)
        pos_y = int(pos_y)
        road[pos_x][pos_y] = 0
        if pos_x == 0:
            for rest in range(pos_y, h + 1):
                road[0][rest] = 0
        if pos_y == 0:
            for rest in range(pos_x, w + 1):
                road[rest][0] = 0

    for row in range(1, w + 1):
        for col in range(1, h + 1):
            if road[row][col] != 0:
                road[row][col] = road[row-1][col] + road[row][col-1]

    num_of_paths = road[w][h]

    if num_of_paths == 0:
        print("There is no path.")
    elif num_of_paths == 1:
        print("There is one path from Little Red Riding Hood's house to her grandmother's house.")
    else:
        print("There are {0} paths from Little Red Riding Hood's house to her grandmother's house.".format(num_of_paths))
