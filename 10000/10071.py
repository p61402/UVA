# Run Time: 0.250
def main():
    while True:
        try:
            v, t = input().split()
        except EOFError:
            break

        print(int(v) * int(t) * 2)


if __name__ == '__main__':
    main()
