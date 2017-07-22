# Run Time: 0.010
def main():
    while True:
        try:
            n1 = int(input())
            n2 = int(input())
        except EOFError:
            break

        print(n1*n2)


if __name__ == '__main__':
    main()
