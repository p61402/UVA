# Run Time: 0.050
def move_onto(a, b):
    for element in block_world.values():
        if a in element:
            while element[-1] != a:
                return_block(element[-1])
                del element[-1]
            del element[-1]

    for element in block_world.values():
        if b in element:
            while element[-1] != b:
                return_block(element[-1])
                del element[-1]
            element.append(a)


def move_over(a, b):
    for element in block_world.values():
        if a in element:
            while element[-1] != a:
                return_block(element[-1])
                del element[-1]
            del element[-1]

    for element in block_world.values():
        if b in element:
            element.append(a)


def pile_onto(a, b):
    pile = []
    for element in block_world.values():
        if a in element:
            while element[-1] != a:
                pile.insert(0, element[-1])
                del element[-1]
            pile.insert(0, a)
            del element[-1]

    for element in block_world.values():
        if b in element:
            while element[-1] != b:
                return_block(element[-1])
                del element[-1]
            element.extend(pile)


def pile_over(a, b):
    pile = []
    for element in block_world.values():
        if a in element:
            while element[-1] != a:
                pile.insert(0, element[-1])
                del element[-1]
            pile.insert(0, a)
            del element[-1]

    for element in block_world.values():
        if b in element:
            element.extend(pile)


def return_block(a):
    block_world[a].append(a)


def is_legal_command(a, b):
    for element in block_world.values():
        if a in element and b in element:
            return False
    return True


if __name__ == "__main__":
    block_number = int(input())

    block_world = {}

    for i in range(block_number):
        block_world[i] = [i]

    while True:
        command = input()
        if command == "quit":
            break

        split_command = command.split()

        block_a = int(split_command[1])
        block_b = int(split_command[3])

        if not is_legal_command(block_a, block_b):
            continue

        if split_command[0] == "move":
            if split_command[2] == "onto":
                move_onto(block_a, block_b)
            else:
                move_over(block_a, block_b)
        else:
            if split_command[2] == "onto":
                pile_onto(block_a, block_b)
            else:
                pile_over(block_a, block_b)

    for key, value in block_world.items():
        if len(value) == 0:
            end = "\n"
        else:
            end = " "
        print("{0}:".format(key), end=end)
        for v in value:
            if v != value[-1]:
                end = " "
            else:
                end = "\n"
            print(v, end=end)
