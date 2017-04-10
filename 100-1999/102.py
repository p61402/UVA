# Run Time: 0.190
def main():
    color_order = ["BCG", "BGC", "CBG", "CGB", "GBC", "GCB"]
    while True:
        try:
            number_list = input().split()
        except EOFError:
            break

        for i in range(len(number_list)):
            number_list[i] = int(number_list[i])

        moving = [number_list[1] + number_list[2] + number_list[3] + number_list[4] + number_list[6] + number_list[8],
                  number_list[1] + number_list[2] + number_list[3] + number_list[5] + number_list[6] + number_list[7],
                  number_list[0] + number_list[1] + number_list[4] + number_list[5] + number_list[6] + number_list[8],
                  number_list[0] + number_list[1] + number_list[3] + number_list[5] + number_list[7] + number_list[8],
                  number_list[0] + number_list[2] + number_list[4] + number_list[5] + number_list[6] + number_list[7],
                  number_list[0] + number_list[2] + number_list[3] + number_list[4] + number_list[7] + number_list[8]]

        min_move = min(moving)

        for i in range(len(moving)):
            if moving[i] == min_move:
                print("{0} {1}".format(color_order[i], min_move))
                break


if __name__ == "__main__":
    main()

