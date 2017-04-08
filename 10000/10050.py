# Run Time: 0.010
def main():
    test_cases = int(input())

    for c in range(test_cases):
        number_of_days = int(input())
        number_of_parties = int(input())
        hartals_day = []
        for p in range(number_of_parties):
            hartals_day.append(int(input()))

        hartals = set()
        for day in hartals_day:
            current_day = day
            while current_day <= number_of_days:
                holidays = (current_day - 6) % 7
                if holidays != 0 and holidays != 1:
                    hartals.add(current_day)
                current_day += day

        print(len(hartals))


if __name__ == "__main__":
    main()
