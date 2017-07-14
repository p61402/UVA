# Run Time: 1.730
import math


def prime():
    n = 1000000
    sieve = [False] * n
    table = []
    for i in range(2, n):
        if not sieve[i]:
            table.append(i)
        j = 0
        while i * table[j] < n:
            sieve[i * table[j]] = True
            if i % table[j] == 0:
                break
            j += 1

    return table


def is_prime(n):
    for i in range(2, int(math.sqrt(n) + 1)):
        if n % i == 0:
            return False
    return True


def main():
    prime_table = prime()
    while True:
        n = int(input())
        if n == 0:
            break

        half = n >> 1
        for p in prime_table:
            if p <= half:
                if is_prime(n - p):
                    print("{} = {} + {}".format(n, p, n-p))
                    break
            else:
                print("Goldbach's conjecture is wrong.")
                break


if __name__ == '__main__':
    main()
