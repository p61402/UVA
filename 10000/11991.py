# Run Time: 0.570
def main():
    while True:
        try:
            number_of_integers, number_of_queries = input().split()
        except EOFError:
            break

        number_of_queries = int(number_of_queries)

        number_list = input().split()

        occurrence_dict = {}

        for number in set(number_list):
            occurrence_dict[number] = {}
            current_occurrence = 0
            for index in range(len(number_list)):
                if number_list[index] == number:
                    current_occurrence += 1
                    occurrence_dict[number][current_occurrence] = index + 1

        for query in range(number_of_queries):
            occurrence, value = input().split()
            occurrence = int(occurrence)
            if len(occurrence_dict[value]) < occurrence or value not in occurrence_dict.keys():
                print("0")
            else:
                print(occurrence_dict[value][occurrence])


if __name__ == "__main__":
    main()
