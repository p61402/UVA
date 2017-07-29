# Run Time: 0.100
def main():
    fib = [0] * 5001
    fib[1] = 1
    for i in range(2, 5001):
        fib[i] = fib[i-1] + fib[i-2]

    while True:
        try:
            num = int(input())
        except EOFError:
            break

        print("The Fibonacci number for", num, "is", fib[num])


if __name__ == '__main__':
    main()
