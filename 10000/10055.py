# Run Time: 0.890
def main():
    while True:
        try:
            a, b = input().split()
        except EOFError:
            break

        a, b = int(a), int(b)

        print(abs(a-b))


if __name__ == '__main__':
    main()
