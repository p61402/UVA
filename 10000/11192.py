# Run Time: 0.020
def main():
    while True:
        try:
            num_of_groups, string = input().split()
        except ValueError:
            break

        num_of_groups = int(num_of_groups)

        reverse_number = int(len(string) / num_of_groups)

        for i in range(1, num_of_groups + 1):
            for char in range(reverse_number * i - 1, reverse_number * (i - 1) - 1, -1):
                print(string[char], end="")

        print()


if __name__ == '__main__':
    main()

