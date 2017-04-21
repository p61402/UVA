# Run Time: 0.030
import math


def main():
    quirks = [[] for i in range(4)]
    numbers = [10, 100, 1000, 10000]

    length = 0
    for n in range(len(numbers)):
        length += 1
        for i in range(numbers[n]):
            s = i * i
            l = len(str(s))
            half_l = int(math.ceil(l / 2))
            front = int((s - s % (10 ** half_l)) / (10 ** half_l))
            back = s % (10 ** half_l)
            if (front + back) ** 2 == s:
                str_front = list(str(front))
                str_back = list(str(back))

                padding_front = (length - len(str_front)) != 0
                padding_back = (length - len(str_back)) != 0

                for x in range(length - len(str_front)):
                    str_front.insert(0, "0")

                for y in range(length - len(str_back)):
                    str_back.insert(0, "0")

                if padding_front and padding_back and s != 0 and s != 1:
                    continue

                quirks[n].append("".join(str_front) + "".join(str_back))

    while True:
        try:
            value = int(input())
        except EOFError:
            break

        index = int(value / 2) - 1

        for i in range(len(quirks[index])):
            print(quirks[index][i])


if __name__ == '__main__':
    main()
