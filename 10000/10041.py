# Run Time: 0.060
def main():
    test_cases = int(input())

    for i in range(test_cases):
        relative_list = input().split()
        length_of_list = int(relative_list[0])
        del relative_list[0]

        for num in range(len(relative_list)):
            relative_list[num] = int(relative_list[num])

        relative_list.sort()

        if length_of_list % 2 == 0:
            position = relative_list[int(length_of_list/2)]
        else:
            position = relative_list[int((length_of_list - 1) / 2)]

        summation = 0
        for element in relative_list:
            summation += abs(position - element)

        print(int(summation))


if __name__ == "__main__":
    main()
