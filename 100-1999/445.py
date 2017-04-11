# Run Time: 0.010
def main():
    while True:
        try:
            line = input()
            if line == "":
                print()
                continue
        except EOFError:
            break

        num = 0
        for char in line:
            if char.isnumeric():
                num += int(char)
            elif char == "b":
                for i in range(num):
                    print(" ", end="")
                    num = 0
            elif char == "!":
                print()
                num = 0
            else:
                for i in range(num):
                    print(char, end="")
                num = 0

        if line[-1] != "!":
            print()


if __name__ == '__main__':
    main()
