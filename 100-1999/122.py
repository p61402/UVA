# Run Time: 0.020
from collections import OrderedDict


def create_tree(input_tuple):
    tree = {}

    for key, value in input_tuple:
        location = 1
        for v in value:
            if v == "L":
                location *= 2
            elif v == "R":
                location = location * 2 + 1
            else:
                break
        if location not in tree.keys():
            tree[location] = int(key)
        else:
            return False

    return tree


def is_complete(d):
    tree = create_tree(d)
    if not tree:
        print("not complete")
        return False

    sort_tree = OrderedDict(sorted(tree.items(), key=lambda t: t[0]))

    complete = True
    for e in sort_tree.keys():
        if e == 1:
            continue
        if int(e/2) not in sort_tree:
            complete = False
            break

    if complete:
        num_of_element = len(sort_tree)
        count = 0
        for element in sort_tree.values():
            if element != 0:
                count += 1
                if count != num_of_element:
                    end = " "
                else:
                    end = "\n"
                print(element, end=end)
    else:
        print("not complete")


a = []
while True:
    try:
        input_line = input()
        new_input_line = input_line.replace('(', ' ').replace(')', ' ').replace(',', ' ').split()
        a.extend(new_input_line)
        for i in range(len(a) - 1):
            if a[i].isdigit() and a[i+1].isdigit():
                a.insert(i+1, "T")
        if a[-1].isdigit():
            a.append("T")
    except EOFError:
        break

    if input_line[-2] + input_line[-1] == "()":
        keys = a[::2]
        values = a[1::2]
        tuple_a = tuple(zip(keys, values))
        is_complete(tuple_a)
        a = []
