# Run Time: 0.140
import math


def f(x, p, q, r, s, t, u):
    return p * math.exp(-x) + q * math.sin(x) + r * math.cos(x) + s * math.tan(x) + t * (x ** 2) + u


def main():
    while True:
        try:
            p, q, r, s, t, u = input().split()
        except EOFError:
            break

        p, q, r, s, t, u = float(p), float(q), float(r), float(s), float(t), float(u)

        if f(0, p, q, r, s, t, u) < -1e-15 or f(1, p, q, r, s, t, u) > 1e-15:
            print("No solution")
        else:
            minimum = 0.0
            maximum = 1.0
            while maximum - minimum >= 1e-10:
                middle = (minimum + maximum) / 2
                if f(middle, p, q, r, s, t, u) > 0:
                    minimum = middle
                else:
                    maximum = middle

            print("{0:.4f}".format(maximum))


if __name__ == '__main__':
    main()
