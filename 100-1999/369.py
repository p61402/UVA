# Run Time: 0.040
def main():
    while True:
        n, m = input().split()
        n, m = int(n), int(m)
        if n == 0 and m == 0:
            break
        numerator = 1
        denominator = 1
        for i in range(n, n-m, -1):
            numerator *= i
        for i in range(1, m+1):
            denominator *= i

        c = int(numerator / denominator)
        print("{0} things taken {1} at a time is {2} exactly.".format(n, m, c))


if __name__ == '__main__':
    main()
