# Run Time: 0.020
def clockwise(before, after):
    if after < before:
        return 40 - before + after
    else:
        return after - before


def counter_clockwise(before, after):
    if after > before:
        return 40 - after + before
    else:
        return before - after


def main():
    while True:
        pos_0, pos_1, pos_2, pos_3 = input().split()
        if pos_0 == "0" and pos_1 == "0" and pos_2 == "0" and pos_3 == "0":
            break

        pos_0, pos_1, pos_2, pos_3 = int(pos_0), int(pos_1), int(pos_2), int(pos_3)

        degree = 1080 + 9 * (counter_clockwise(pos_0, pos_1) + clockwise(pos_1, pos_2) + counter_clockwise(pos_2, pos_3))

        print(degree)


if __name__ == "__main__":
    main()




