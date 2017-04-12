# Run Time: 0.020
def main():
    while True:
        try:
            num1, num2 = input().split()
        except EOFError:
            break

        num1, num2 = int(num1), int(num2)

        binary_num1, binary_num2 = list("{0:b}".format(num1)), list("{0:b}".format(num2))

        if len(binary_num1) > len(binary_num2):
            for i in range(len(binary_num1) - len(binary_num2)):
                binary_num2.insert(0, "0")
        else:
            for i in range(len(binary_num2) - len(binary_num1)):
                binary_num1.insert(0, "0")

        summation = []
        for bit in range(len(binary_num1)):
            if binary_num1[bit] == binary_num2[bit]:
                summation.append("0")
            else:
                summation.append("1")

        print(int("".join(summation), 2))


if __name__ == '__main__':
    main()