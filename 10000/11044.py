# Run Time: 0.010
import math


def main():
    num_of_cases = int(input())

    for i in range(num_of_cases):
        row, col = input().split()
        row, col = int(row) - 2, int(col) - 2
        print(math.ceil(row/3) * math.ceil(col/3))


if __name__ == "__main__":
    main()
