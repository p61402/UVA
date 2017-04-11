# Run Time: 0.010
def main():
    while True:
        a, b, c = input().split()

        if a == "0" and b == "0" and c == "0":
            break

        line = [int(a), int(b), int(c)]

        line.sort()

        if line[0]**2 + line[1]**2 == line[2]**2:
            print("right")
        else:
            print("wrong")


if __name__ == '__main__':
    main()

