# Run Time: 2.610
def main():
    left_most = 10000
    right_most = 0
    buildings = [0] * 10000

    while True:
        try:
            l, h, r = input().split()
        except EOFError:
            break

        l, h, r = int(l), int(h), int(r)

        left_most = min(left_most, l)
        right_most = max(right_most, r)

        for i in range(l, r):
            buildings[i] = max(buildings[i], h)

    current_height = buildings[left_most]
    print(left_most, current_height, end=" ")
    for i in range(left_most, right_most + 1):
        if buildings[i] != current_height:
            if i != right_most:
                end = " "
            else:
                end = "\n"
            print(i, buildings[i], end=end)
            current_height = buildings[i]


if __name__ == '__main__':
    main()
