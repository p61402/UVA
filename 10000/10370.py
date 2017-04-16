# Run Time: 0.020
def main():
    test_cases = int(input())

    for i in range(test_cases):
        ages = input().split()

        del ages[0]

        summation = 0
        for a in range(len(ages)):
            ages[a] = int(ages[a])
            summation += ages[a]

        average = summation / len(ages)

        num_above_avg = 0
        for age in ages:
            if age > average:
                num_above_avg += 1

        print("{0:.3f}%".format(100 * num_above_avg / len(ages)))


if __name__ == '__main__':
    main()
