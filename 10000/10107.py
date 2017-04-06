# Run Time: 0.430
def main():
    integer_list = []

    while True:
        try:
            num = int(input())
        except EOFError:
            break

        integer_list.append(num)

        print(median(integer_list))


def median(number_list):
    number_list.sort()

    length_of_list = len(number_list)

    if length_of_list % 2 == 0:
        return int((number_list[int(length_of_list/2)] + number_list[int(len(number_list)/2) - 1]) / 2)
    else:
        return int(number_list[int(len(number_list)/2)])


if __name__ == "__main__":
    main()
